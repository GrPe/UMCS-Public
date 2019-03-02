#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX 10
#define KLUCZ_SEM 11111
#define KLUCZ_SHM 654321

struct sembuf buf;

void down(int semid, int semnum)
{
    buf.sem_num = semnum;
    buf.sem_op = -1;
    buf.sem_flg = 0;
    semop(semid,&buf,1);
}

void up(int semid, int semnum)
{
    buf.sem_num = semnum;
    buf.sem_op = 1;
    buf.sem_flg = 0;
    semop(semid,&buf,1);
}

int main()
{
    int shmid, semid;
    int *shared_mem = NULL;
    semid = semget(KLUCZ_SEM,2,IPC_CREAT | 0600);
    semctl(semid,0,SETVAL,(int)MAX);
    semctl(semid,1,SETVAL,(int)0);
    shmid = shmget(KLUCZ_SHM,sizeof(int)*MAX,IPC_CREAT | 0600);
    shared_mem = (int*)shmat(shmid,NULL,0);
    for(int i = 0;i<10000;i++)
    {
        down(semid,0);
        shared_mem[i%MAX] = i;
        up(semid,1);
    }
    shmdt(shared_mem);
    return 0;
}