#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>


int main()
{
    int desc;
    mkfifo("fifo",0600);
    
    pid_t child = fork();
    if(-1 == child)
    {
        puts("Error fork");
        exit(1);
    }
    if(0 == child)
    {
        char buff[100];
        desc = open("fifo",O_RDONLY);
        if(desc == -1)
        {
            puts("Cannot open the fifo to read");
            exit(2);
        }
        int r = read(desc,buff,100);
        if(r < 0)
        {
            puts("Error cannot read data");
            exit(0xddd);
        }
        puts(buff);
        close(desc);
    }
    else
    {
        child = fork();
        if(-1 == child)
        {
            puts("Error fork");
            exit(0xDD);
        }
        if(0 == child)
        {
            desc = open("fifo",O_WRONLY);
            if(desc == -1)
            {
                puts("Cannot open fifo to write");
                exit(0xdead);
            }
            int w = write(desc,"Wololo!!!",10);
            if(w != 10)
            {
                puts("Cannot write data");
                exit(0xcba);
            }
            close(desc);
            unlink("fifo");
        }
    }
    return 0;
}
