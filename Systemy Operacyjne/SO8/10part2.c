#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main()
{
    int desc = open("fifo",O_RDONLY);
    if(desc == -1)
    {
        puts("Cannot open fifo");
        exit(1);
    }
    char buff[50];
    int r = read(desc,buff,50);
    if(r == -1)
    {
        puts("Cannot read data");
        exit(2);
    }
    puts(buff);
    close(desc);
    unlink("fifo");
    
    return 0;
}