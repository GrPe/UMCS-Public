#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define NRPID 5

int main()
{
    int i = 0;
    pid_t child = 1;
    while(i<NRPID)
    {
        if(child !=0)
        {
            ++i;
            child = fork();
        }
        else break;
    }
    printf("PID: %d - Hello!\n",getpid());
    
    return 0;
}
