#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#define N 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

char warunek = 0;

void* watek(void* number)
{
    printf("Uruchomiono watek #%d\n",(int)number);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        do
        {
            if(warunek) break;
            else
            {
                printf("Watek #%d oczekuje na sygnal\n",(int)number);
                pthread_cond_wait(&cond, &mutex);
                printf("Watek #%d otrzymal sygnal\n",(int)number);
            }
        }while(1);
        pthread_mutex_unlock(&mutex);
    }
     return NULL;
}

int main()
{
    pthread_t id[N];
    int i;
    puts("Poczatek programu");
    for(i = 0;i<N;i++)
    {
        errno = pthread_create(&id[i],NULL,watek,(void*)(i+1));
        if(errno)
        {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }
    sleep(1);
    puts("Sygnal do jednego watku");
    pthread_cond_signal(&cond);
    sleep(1);
    puts("Sygnal do wszystkich");
    pthread_cond_broadcast(&cond);
    sleep(1);
    return EXIT_SUCCESS;
}
