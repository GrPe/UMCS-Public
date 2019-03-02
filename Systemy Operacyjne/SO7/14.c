#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    execl("/bin/ps","ps","-ef",NULL);
    
    return 0;
}