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
    semid = semget(KLUCZ_SEM,2,0600);
    shmid = shmget(KLUCZ_SHM,MAX*sizeof(int),0600);
    shared_mem = (int*)shmat(shmid,NULL,0);
    for(int i = 0; i<10000;i++)
    {
        down(semid,1);
        printf("Number: %d wartosc: %d\n",i,shared_mem[i%MAX]);
        up(semid,0);
    }
    shmdt(shared_mem);
    shmctl(semid,IPC_RMID,0);
    return 0;
}