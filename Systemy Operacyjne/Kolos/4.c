#include <stdio.h>
#include <unistd.h>


int main()
{
    int pdesc[2];
    pipe(pdesc);
    pid_t child = fork();
    if(child == -1)
    {
        puts("error");
        return 1;
    }
    if(child == 0)
    {
        close(pdesc[0]);
        write(pdesc[1],"Hello World!",20);
        close(pdesc[1]);
    }
    else
    {
        char buff[20];
        close(pdesc[1]);
        read(pdesc[0],buff,20);
        close(pdesc[0]);
        puts(buff);
    }
    
    return 0;
}