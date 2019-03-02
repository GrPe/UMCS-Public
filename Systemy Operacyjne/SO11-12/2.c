#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 5
#define SEMKEY 123456

int main()
{
    int semid = semget(SEMKEY,1,IPC_CREAT | 0666);
    semctl(semid,0,SETVAL,(int)5);

    return 0;
}