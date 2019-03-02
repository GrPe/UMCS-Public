#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();
    if(child == 0)
    {
        fork();
        fork();
    }
    printf("PID: %d, PPID: %d\n",getpid(),getppid());
    wait(NULL);
    return 0;
}
