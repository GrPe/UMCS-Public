#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int desc;
    mkfifo("fifo",0600);
    
    pid_t child = fork();
    if(child == -1)
    {
        puts("Error fork");
        exit(1);
    }
    if(child == 0)
    {
        desc = open("fifo",O_WRONLY);
        if(desc == -1)
        {
            puts("ERROR");
            exit(0xdd);
        }
        int w = write(desc,"przerzutnik schmitta",21);
        if(w < 0)
        {
            puts("Cannot write date");
            exit(0xd);
        }
        close(desc);
        unlink("fifo");
    }
    else
    {
        char buff[100];
        desc = open("fifo",O_RDONLY);
        if(desc == -1)
        {
            puts("Cannot open fifo to read");
            exit(0xDDD);
        }
        read(desc,buff,100);
        puts(buff);
        close(desc);
    }
    return 0;
}
