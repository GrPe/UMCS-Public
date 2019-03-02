#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define NUMPR 7

int main()
{
    pid_t child = 1;
    int i = 0;
    while(i<NUMPR)
    {
        if(child != 0) 
        {
            ++i;
            child = fork();
        }
        else break;
    }
    printf("PID: %d PPID: %d\n",getpid(),getppid());
    
    return 0;
}
