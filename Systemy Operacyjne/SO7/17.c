#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //error control
    if(argc !=2)
    {
        puts("Invalid number of argumets");
        return 1;
    }
    for(unsigned int i = 0;i<strlen(argv[1]);++i)
    {
        if(isdigit(argv[1][i]) == 0 )
        {
            puts("Argument is not a integer value");
            return 1;
        }
    }
    //convert
    int result = strtol(argv[1],NULL,10);

    //child factory
    pid_t child = 1;
    for(int i = 0; i<result;++i)
    {
        if(child != 0) child=fork();
        else
        {
            printf("Proces %d\n",i);
            break;
        }
    }
    
    return 0;
}
