#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>



int main()
{
    if(mkfifo("fifo",0600) == -1)
    {
        puts("Error - create fifo");
        exit(1);
    }

    int desc = -1;

    if(fork() == 0)
    {
        desc = open("fifo",O_WRONLY);
        dup2(desc,STDOUT_FILENO);
        execl("/bin/ls", "ls", "-al",NULL);
        exit(3);
    }
    if(fork() == 0)
    {
        desc = open("fifo",O_RDONLY);
        dup2(desc,STDIN_FILENO);
        execl("/bin/grep","grep","abc",NULL);
        exit(4);
    }

    wait(NULL);
    wait(NULL);
    close(desc);
    unlink("fifo");

    return 0;
}
