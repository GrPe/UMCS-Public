#include <stdio.h>
#include <pthread.h>


int Global;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* foo(void* arg)
{
    for(int i = 0;i<20;i++)
    {
        pthread_mutex_lock(&mutex);
        Global++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main()
{
    pthread_t threads[2];
    for(int i = 0;i<2;++i)
    {
        pthread_create(&threads[i],NULL,foo,NULL);
    }
    for(int i = 0;i<2;++i)
    {
        pthread_join(threads[i],NULL);
    }
    printf("%d\n",Global);

    return 0;
}