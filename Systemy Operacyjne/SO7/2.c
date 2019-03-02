#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child = fork();
    if(child == -1)
    {
        puts("Error");
        return 1;
    }
    if(child == 0)
    {
        fork();
        fork();
        printf("Child: PID %d, PPID %d\n",getpid(),getppid());
    }
    else
    {
        printf("Rodzic: PID %d, PPID %d\n",getpid(),getppid());
    }
    int s;
    wait(&s);
    return 0;
}
