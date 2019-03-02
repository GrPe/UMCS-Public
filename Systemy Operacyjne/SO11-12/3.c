#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define SHMKEY 123456


int main()
{
    int shmid = shmget(SHMKEY,20*sizeof(char),IPC_CREAT | 0666);
    char* mem = shmat(shmid,NULL,0);
    strcpy(mem,"Hello World!");
    puts(mem);
    shmdt(mem);
    shmctl(shmid,IPC_RMID,NULL);
    puts("Done");

    return 0;
}