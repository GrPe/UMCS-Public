#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int pdesc[2];
    pipe(pdesc);
    
    pid_t child = fork();
    if(-1 == child)
    {
        puts("Error fork");
        exit(1);
    }
    if(0 == child)
    {
        close(pdesc[0]);
        write(pdesc[1],"Hell, World",12);
        close(pdesc[1]);
    }
    else
    {
        if(fork() == 0)
        {
            char buff[15];
            close(pdesc[1]);
            read(pdesc[0],buff,12);
            close(pdesc[0]);
            puts(buff);
        }
    }    
 
    return 0;
}
