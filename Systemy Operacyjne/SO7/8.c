#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LIMIT 3

int main()
{
    pid_t child = 1;
    for(int i = 0; i<3;++i)
    {
        if(child != 0) child = fork();
        else break;
    }
    printf("PID: %d, PPID: %d\n",getpid(),getppid());
    int temp;
    wait(&temp);
    return 0;
}
