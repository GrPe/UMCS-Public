#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>


#define SHMKEY 12354
#define SEMKEY 213546
#define MAX 10

struct sembuf sbuf;

void down(int semid, int semnum)
{
    sbuf.sem_num = semnum;
    sbuf.sem_op = -1;
    sbuf.sem_flg = 0;
    semop(semid,&sbuf,1);
}

void up(int semid, int semnum)
{
    sbuf.sem_num = semnum;
    sbuf.sem_op = 1;
    sbuf.sem_flg = 0;
    semop(semid,&sbuf,1);
}


int main()
{
    int semid = semget(SEMKEY,2,IPC_CREAT | 0660);
    semctl(semid,0,SETVAL,(int)0);
    semctl(semid,1,SETVAL,(int)MAX);
    int shmid = shmget(SHMKEY,sizeof(int)*MAX,IPC_CREAT | 0666);

    pid_t child = fork();
    if(child == -1)
    {
        puts("error");
        return 1;
    }
    if(child == 0)
    {
        int* mem = shmat(shmid,NULL,0);
        for(int i = 0;i<=1000;++i)
        {
            down(semid,1);
            mem[i%MAX] = i;
            up(semid,0);
        }
        shmdt(mem);
    }
    else
    {
        int* mem = shmat(shmid,NULL,0);
        for(int i = 0;i<=1000;++i)
        {
            down(semid,0);
            printf("%d\n",mem[i%MAX]);
            up(semid,1);
        }
        shmdt(mem);
        shmctl(shmid,IPC_RMID,NULL);
    }
    

    return 0;
}