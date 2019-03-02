#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pdesk[2];
    pipe(pdesk);
    
    pid_t child = fork();
    if(child == -1)
    {
        printf("Fork error!\n");
        exit(1);
    }
    if(child == 0)
    {
        close(pdesk[0]);
        write(pdesk[1], "czesc!",7);
        close(pdesk[1]);
    }
    else
    {
        char buf[10];
        close(pdesk[1]);
        read(pdesk[0],buf, 7);
        printf("odczytano z potoku: %s\n",buf);
        close(pdesk[0]);
    }
 
    
    return 0;
}
