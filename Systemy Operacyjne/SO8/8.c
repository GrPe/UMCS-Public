#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

void IAmChild();
void IAmParent();

int main()
{
    mkfifo("fifo",0600);

    pid_t child = fork();

    if(child == -1)
    {
        puts("Error fork");
        exit(1);
    }

    if(child == 0) IAmChild();
    else IAmParent();

    return 0;
}

void IAmChild()
{
    int desc = open("fifo",O_WRONLY);
    if(desc == -1)
    {
        puts("Error - write fifo");
        exit(2);
    }
    int fileDesc = open("file8.txt",O_RDONLY);
    if(fileDesc == -1)
    {
        puts("Error: Cannot open the file");
        exit(3);
    }
    int fSize = lseek(fileDesc,0,2);
    if(fSize == -1)
    {
        puts("Error: Problem with file");
        exit(4);
    }
    lseek(fileDesc,0,0);
    char buff[100];
    while(fSize > 0)
    {
        int r = read(fileDesc,buff,100);
        write(desc,buff,r);
        fSize -=100;
    }
    close(desc);
    close(fileDesc);
}

void IAmParent()
{
    int desc = open("fifo",O_RDONLY);
    int fDesc = creat("OutFILE8.txt",0640);
    if(desc == -1) exit(4);
    if(fDesc == -1) exit(5);
    fDesc = open("OutFILE8.txt",O_WRONLY);
    if(fDesc == -1) exit(6);
    char buff[100];
    int w;
    while(1)
    {
        w = read(desc,buff,100);
        if(w <=0) break;
        write(fDesc,buff,w);
    }
    close(desc);
    unlink("fifo");
    close(fDesc);
}
