#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdio.h>

#define SHMKEY 2135487
#define MAX 20


int main()
{
    int shmid = shmget(SHMKEY,sizeof(int)*MAX,IPC_CREAT | 0600);
    int* mem = shmat(shmid,NULL,0);
    mem[0] = 32768;
    printf("%d\n",mem[0]);
    shmdt(mem);
    shmctl(shmid,IPC_RMID,NULL);
    puts("Done");

    return 0;
}