#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t child = fork();
    if(child == -1)
    {
        puts("Error!");
        return 1;
    }
    if(child > 0)
        printf("Proces macierzysty o PID: %d i PPID %d\n",getpid(),getppid());
    else
        printf("Proces potomny o PID: %d i PPID %d\n",getpid(),getppid());
    
    
    return 0;
}
