#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    fork();
    fork();
    printf("PID: %d, PPID %d\n",getpid(),getppid());
    wait(NULL);
    return 0;
}
