#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int x=51;

void* TestX(void* arg)
{
    for(int i = 0;i<50;++i)
    {
        if(x%2 == 0)
        {
            x +=3;
        }

    }
    return NULL;
}

void* Increment(void* arg)
{
    for(int i = 0;i<50;++i)
    {
        x++;
    }
    return NULL;
}

int main()
{
    pthread_t thread[12];
    int correct;
    for(int i =0;i<12;++i)
    {
        if(i%2)
            correct = pthread_create(&(thread[i]),NULL,TestX,NULL);
        else
            correct = pthread_create(&(thread[i]),NULL,Increment,NULL);
        if(correct == -1)
        {
            puts("thread create error");
            exit(1);
        }
    }

    for(int i = 0; i<12;++i)
    {
        correct = pthread_join(thread[i],NULL);
        if(correct == -1)
        {
            puts("Thread join error");
            exit(2);
        }
    }

    printf("%d\n",x);

    return 0;
}
