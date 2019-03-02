#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>


int main()
{

    int pdescA[2];
    int pdescB[2];
    pipe(pdescB);
    pid_t pid = fork();
    if(pid == 0)
    {
        dup2(pdescB[1],STDOUT_FILENO);
        execl("/bin/ls","ls","-al",NULL);
        exit(1);
    }
    else
    {
        pipe(pdescA);
        pid = fork();
        if(pid == 0)
        {
            dup2(pdescB[0],STDIN_FILENO);
            execl("/bin/grep","grep","abc",NULL);
            exit(2);
        }
    }
    close(pdescA[0]);
    close(pdescA[1]);
    close(pdescB[0]);
    close(pdescB[1]);
    wait(NULL);

    return 0;
}