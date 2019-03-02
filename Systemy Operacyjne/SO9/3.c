#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void* Time(void* arg)
{
    for(int i = 0 ; i < 6;++i)
    {
        time_t t = time(NULL);
        puts(ctime(&t));
        sleep(10);
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    if(pthread_create(&thread,NULL,Time,NULL))
    {
        puts("pthread_create");
        exit(1);
    }
    if(pthread_join(thread,NULL))
    {
        puts("pthread_join");
        exit(2);
    }
    
    return 0;
}
