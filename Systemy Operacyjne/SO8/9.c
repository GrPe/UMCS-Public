#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

void IAmChild();
void IAmParent();

int main()
{
    mkfifo("fifo",0600);

    pid_t child = 1;

    for(int i = 0; i<5;++i)
    {
        if(child != 0)
        {
            child = fork();
        }
        else
        {
            IAmChild();
            break;
        }
    }
    if(child != 0) IAmParent();

    return 0;
}

void IAmChild()
{
    int desc = open("fifo",O_WRONLY);
    if(desc == -1)
    {
        puts("Error");
        exit(1);
    }
    char buff[80];
    sprintf(buff,"PID: %d, PPID: %d\n",getpid(), getppid());
    write(desc,buff,strlen(buff)+1);
    close(desc);
}

void IAmParent()
{
    int desc = open("fifo",O_RDONLY);
    char buff[80];
    int status;
    while(wait(&status) != -1) //czekanie na dzieci
    {
        if(WIFEXITED(status))
        {
            read(desc,buff,80);
            puts(buff);
        }
    }
    close(desc);
    unlink("fifo");
}
