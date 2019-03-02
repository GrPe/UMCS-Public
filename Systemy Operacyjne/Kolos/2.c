#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


#define SEMKEY 123546

int main()
{
    int semid = semget(SEMKEY,3,IPC_CREAT | 0660);
    semctl(semid,0,SETVAL,(int)0);
    semctl(semid,1,SETVAL,(int)1);
    semctl(semid,2,SETVAL,(int)2);

    puts("Done");
}