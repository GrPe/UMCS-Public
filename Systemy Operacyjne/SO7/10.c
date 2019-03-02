#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t child = fork();
    if(child == 0)
        exit(0xd);
    int ret;
    waitpid(child,&ret,0);
    printf("Proces is dead with code: %d\n",WEXITSTATUS(ret));
    return 0;
}
