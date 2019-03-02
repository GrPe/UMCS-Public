#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>


#define SIZE 15
#define READ 0
#define WRITE 1
#define MSGKEY 666666
#define SHMKEY 123456
#define SEMKEY 111111
#define MSGTYPE 1

char GlobalBuff[SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static struct sembuf sbuf;

struct msgbuf
{
    long mtype;
    char mtext[SIZE];
};

void lock(int semid, int semnum);
void unlock(int semid, int semnum);

void* thread(void* arg);

void Process1(int pdesc[]);
void Process2(int pdesc[]);
void Process3(int msgid);
void Process4(int msgid, int shmid, int semid);
void Process5();

int main()
{
    int pdesc[2];
    pipe(pdesc);
    mkfifo("fifo",0600);
    int msgid = msgget(MSGKEY, IPC_CREAT | 0600);
    if(msgid == -1)
    {
        perror("Cannot create msg\n");
        exit(0x32);
    }
    int shmid = shmget(SHMKEY,SIZE,IPC_CREAT | 0600);
    if(shmid == -1)
    {
        perror("Cannot create shm\n");
        exit(0x42);
    }
    int semid = semget(SEMKEY,2,IPC_CREAT | 0600);
    pthread_t thr;

    pid_t child = fork();
    if(child == -1)
    {
        perror("Error with fork\n");
        exit(0x11);
    }
    if(child == 0)
    {
        Process2(pdesc);
    }
    else
    {
        Process1(pdesc);
        child = fork();
        if(child == -1)
        {
            perror("Error with fork #2\n");
            exit(0x12);
        }
        if(child == 0)
        {
            Process3(msgid);
        }
        else
        {
            child = fork();
            if(child == -1)
            {
                perror("Error with fork #3\n");
                exit(0x13);
            }
            if(child == 0)
            {
                Process4(msgid,shmid,semid);
            }
            else
            {
                child = fork();
                if(child == -1)
                {
                    perror("Error with fork #4\n");
                    exit(0x14);
                }
                if(child == 0)
                {
                    Process5(thr);
                }
            }
        }
    }
}

void Process1(int pdesc[])
{
        int fileDesc = open("file.txt",O_RDONLY);
        if(fileDesc == -1)
        {
            perror("Cannot open file to read\n");
            exit(0x12);
        }
        close(pdesc[READ]);
        char buff[SIZE];
        int r = read(fileDesc,buff,SIZE);
        if (r == -1 )
        {
            perror("Cannot read data\n");
            exit(0x13);
        }
        close(fileDesc);
        int w = write(pdesc[WRITE],buff,SIZE);
        if(w == -1)
        {
            perror("Cannot write data\n");
            exit(0x14);
        }
        close(pdesc[WRITE]);
}

void Process2(int pdesc[])
{
    close(pdesc[WRITE]);
    char buff[SIZE];
    int r = read(pdesc[READ],buff,SIZE);
    if(r == -1)
    {
        perror("Error with read data from pipe\n");
        exit(0x21);
    }
    close(pdesc[READ]);
    int fifoDesc = open("fifo",O_WRONLY);
    int w = write(fifoDesc,buff,SIZE);
    if(w == -1)
    {
        perror("Cannot write data to fifo\n");
        exit(0x22);
    }
    close(fifoDesc);
}

void Process3(int msgid)
{
    int fifoDesc = open("fifo",O_RDONLY);
    char buff[SIZE];
    int r = read(fifoDesc,buff,SIZE);
    if(r == -1)
    {
        perror("Cannot read fifo\n");
        exit(0x31);
    }
    close(fifoDesc);
    unlink("fifo");
    
    struct msgbuf msg;
    msg.mtype = MSGTYPE;
    memcpy(msg.mtext,buff,SIZE);
    if(msgsnd(msgid,&msg,sizeof(msg.mtext),0) == -1)
    {
        perror("Problem with msgsnd\n");
        exit(0x33);
    }
}

void Process4(int msgid, int shmid,int semid)
{
    struct msgbuf msg;
    if(msgrcv(msgid,&msg,sizeof(msg.mtext),MSGTYPE,0) == -1)
    {
        perror("Error with msgid\n");
        puts(msg.mtext);
        exit(0x41);
    }
    msgctl(msgid,IPC_RMID,NULL);
    
    semctl(semid,0,SETVAL,(char)SIZE);
    semctl(semid,1,SETVAL,(char)0);
    void* shared_mem = NULL;
    shared_mem = (char*)shmat(shmid,NULL,0);
    lock(semid,0);
    sprintf(shared_mem,"%s",msg.mtext);
    unlock(semid,1);
    
}

void Process5(pthread_t thr)
{
    int semid = semget(SEMKEY,2,0600);
    int shmid = shmget(SHMKEY,SIZE,0600);
    void* shared_mem = (char*)shmat(shmid,NULL,0);
    lock(semid,1);
    pthread_mutex_lock(&mutex);
    memcpy(GlobalBuff,shared_mem,SIZE);
    pthread_mutex_unlock(&mutex);
    unlock(semid,0);
    shmctl(shmid,IPC_RMID,NULL);

    pthread_create(&thr,NULL,thread,NULL);
    pthread_join(thr,NULL);

}

void lock(int semid, int semnum)
{
    sbuf.sem_num = semnum;
    sbuf.sem_op = -1;
    sbuf.sem_flg = 0;
    if(semop(semid,&sbuf,1) == -1)
    {
        perror("Error with semaphore");
        exit(0xff);
    }
}

void unlock(int semid, int semnum)
{
    sbuf.sem_num = semnum;
    sbuf.sem_op = 1;
    sbuf.sem_flg = 0;
    if(semop(semid,&sbuf,1) == -1)
    {
        perror("Error with semaphore");
        exit(0xfe);
    }
}

void* thread(void* arg)
{
    int fileDesc = creat("newFile.txt",0600);
    if(fileDesc == -1)
    {
        perror("Error with create file\n");
        exit(0x51);
    }
    fileDesc = open("newFile.txt",O_WRONLY);
    if(fileDesc == -1)
    {
        perror("Error with open file\n");
        exit(0x52);
    }
    pthread_mutex_lock(&mutex);
    int w = write(fileDesc,GlobalBuff,SIZE);
    pthread_mutex_unlock(&mutex);
    if(w == -1)
    {
        perror("Error with write output file\n");
        exit(0x53);
    }
    return NULL;
}
