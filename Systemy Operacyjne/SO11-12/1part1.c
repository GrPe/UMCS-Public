#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100
#define KEY 1324

int main()
{
    int shmid;
    if(fork() == 0)
    {
        void* shared_memory = (void*)0;
        shmid = shmget(KEY,MAX,0666 | IPC_CREAT);
        shared_memory = shmat(shmid, NULL, 0);
        sprintf(shared_memory,"Hallo");
    }
    else
    {
        sleep(1);
        char* data;
        char buf[MAX];
        shmid = shmget(KEY,MAX,IPC_CREAT|0600);
        data = shmat(shmid,NULL,0);
        strcpy(buf,data);
        printf("Odczytano z pamieci: %s\n",data);
    }
    
    
    return 0;
}
