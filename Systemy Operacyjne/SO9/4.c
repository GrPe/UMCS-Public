#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *Timer(void* arg)
{
    for(int i = 0;i<60;++i)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}


int main()
{
    puts("Uruchamiania, prosze czekaj");
    pthread_t thread;
    int isThreadCreated = pthread_create(&thread,NULL,Timer,NULL);
    if(isThreadCreated == -1)
    {
        puts("Blad tworzenia watku");
        exit(1);
    }

    int isThreadComplited = pthread_join(thread,NULL);
    if(isThreadComplited == -1)
    {
        puts("Blad synchronizacji watku");
        exit(2);
    }
    

    return 0;
}