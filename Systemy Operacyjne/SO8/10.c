#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    puts("Start program #1 'Sender'");
    if(mkfifo("fifo",0600) == -1)
    {
        puts("Cannot create the fifo");
        exit(1);
    }
    int desc = open("fifo",O_WRONLY);
    if(desc == -1)
    {
        puts("Cannot open fifo");
        exit(2);
    }
    int w = write(desc,"ABC++",6);
    if( w != 6)
    {
        puts("Cannot write data");
        exit(3);
    }
    close(desc);
    return 0;
}