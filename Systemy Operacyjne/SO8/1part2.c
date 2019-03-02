#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int pdesk;
    if(mkfifo("kolejka",0600) == -1)
    {
        puts("Error mkfifo");
        exit(1);
    }
    
    pid_t child = fork();
    if(child == -1)
    {
        puts("Error: fork()");
        exit(2);
    }
    if(child == 0)
    {
        pdesk = open("kolejka",O_WRONLY);
        write(pdesk,"czesc!",7);
        close(pdesk);
        exit(0);
    }
    else
    {
        char buf [10];
        pdesk = open("kolejka",O_RDONLY);
        read(pdesk,buf,10);
        printf("Odczytano z potoku: %s\n",buf);
        close(pdesk);
        unlink("kolejka");
    }
    
 
    
    return 0;
}
