#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int desc[2];
    pipe(desc);
    pid_t child = fork();
    if(-1 == child)
    {
        puts("Error fork");
        exit(1);
    }
    if(0 == child)
    {
        char buff[100];
        //open file to read
        int fileDesc = open("plik.txt",O_RDONLY);
        if(fileDesc == -1)
        {
            puts("Cannot open plik.txt");
            exit(2);
        }
        //prepare pipe
        close(desc[0]);
        //read -> pipe
        int r=1;
        do
        {   r = read(fileDesc,buff,100);
            write(desc[1],buff,r);
        }while(r>0);
        //clean
        close(desc[1]);
        close(fileDesc);
    }
    else
    {
        child = fork();
        if(-1 == child)
        {
            puts("Error fork2");
            exit(0xd);
        }
        if(0 == child)
        {
            char buff[100];
            //open file to write
            int fileDesc = open("out.txt",O_WRONLY);
            if(fileDesc == -1)
            {
                puts("Cannot open out.txt");
                exit(0xdd);
            }
            //prepare pipe
            close(desc[1]);
            //pipe->write
            int w;
            do
            {
                w = read(desc[0],buff,100);
                write(fileDesc,buff,w);
            }
            while(w > 0);
            //clean
            close(desc[0]);
            close(fileDesc);
        }
    }
    return 0;
}
