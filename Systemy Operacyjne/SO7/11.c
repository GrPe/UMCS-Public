#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>


void IAmChild();
void IAmParent();

int main()
{
    pid_t child = fork();
    if(child == -1)
    {
        puts("Error fork");
        return 1;
    }
    if(child == 0) IAmChild();
    else IAmParent();
    
    return 0;
}

void IAmChild()
{
    //troche przerazajace. Proces zabija swojego rodzica
    printf("PID: %d, PPID: %d\n",getpid(),getppid());
    char command[50] = "kill ";
    char buff[20];
    sprintf(buff,"%d",getppid()); //convert int to string
    strcat(command,buff);
    system(command);
    printf("PID: %d, PPID: %d\n",getpid(),getppid());
}
void IAmParent()
{
    printf("PID: %d, PPID: %d\n",getpid(),getppid());
    while(true);
}
