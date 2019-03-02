#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int globalVariable = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *MagicIncrementingThread(void* arg)
{

    for(int i = 0;i<10;++i)
    {
        pthread_mutex_lock(&mutex);
        ++globalVariable;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main()
{
    pthread_t threads[20];
    int correct;
    for(int i = 0; i<20;++i)
    {
        correct = pthread_create(&(threads[i]),NULL,MagicIncrementingThread,NULL);
        if(correct == -1) exit(1);
    }

    for(int i = 0;i<20;++i)
    {
        correct = pthread_join(threads[i],NULL);
        if(correct == -1) exit(2);
    }
    printf("%d\n",globalVariable);

    return 0;
}
