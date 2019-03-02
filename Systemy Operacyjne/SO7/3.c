#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t child =fork();
    if(child == -1)
    {
        puts("Error");
        return 1;
    }
    if(child != 0)
    {
        pid_t schild = fork();
        if(schild !=0) fork();
    }
    printf("PID %d, PPID %d\n",getpid(),getppid());
    if(child != 0)
    {
        while(1) {};
    }
    
    return 0;
}
