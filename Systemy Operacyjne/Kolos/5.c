#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    mkfifo("fifo",0600);
    pid_t child = fork();

    if(child == -1)
    {
        puts("error");
        return 1;
    }
    if(child == 0)
    {
        char buff[10];
        int fdesc = open("fifo",O_WRONLY);
        sprintf(buff,"%d",getpid());
        write(fdesc,buff,10);
        close(fdesc);
    }
    else
    {
        char buff[10];
        int fdesc = open("fifo",O_RDONLY);
        read(fdesc,buff,10);
        close(fdesc);
        unlink("fifo");
        puts(buff);
    }
    



    return 0;
}
