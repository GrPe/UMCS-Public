#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>



int main(int argc, char* argv[])
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
        if(argc != 2)
        {
            puts("invalid argument");
            exit(2);
        }
        close(pdesc[0]);
        write(pdesc[1],argv[1],strlen(argv[1])+1);
        close(pdesc[1]);
    }
    else
    {
        close(pdesc[1]);
        char buff[100];
        read(pdesc[0],buff,100);
        close(pdesc[0]);
        puts(buff);
    }
    
    return 0;
}
