#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *counter(void *arg)
{
    int i;
    for(i = 15; i > 0; i--)
    {
        printf("Pozostalo %d sekund\n",i);
        sleep(1);
    }
    return NULL;
}

int main()
{
    int isThreadCreated, isThreadComplete;
    
    printf("Uwaga zarzadamy ewakuacje!\n");
    pthread_t myThread;
    
    isThreadCreated = pthread_create(&myThread,NULL,counter,NULL);
    if(isThreadCreated == -1)
    {
        puts("Blad tworzenia watku");
    }
    
    isThreadComplete = pthread_join(myThread,NULL);
    if(isThreadComplete == -1)
        puts("Blad tworzenia watku");
    
    puts("BUM!");
    return 0;
}
