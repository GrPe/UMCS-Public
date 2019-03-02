#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


int main()
{
    int pdesc[2];
    pipe(pdesc);
    pid_t child = fork();
    
    if(-1 == child)
    {
        puts("error fork");
        exit(1);
    }
    if(0 == child)
    {
        char buff[15];
        close(pdesc[1]);
        read(pdesc[0],buff,15);
        close(pdesc[0]);
        puts(buff);
    }
    else
    {
        close(pdesc[0]);
        write(pdesc[1],"asdfasdfasdf",13);
        close(pdesc[1]);
    }
    
    
 
    return 0;
}
