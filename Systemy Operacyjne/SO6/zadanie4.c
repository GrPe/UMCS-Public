#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#define SIZE 1024

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        perror("Invalid number of arguments");
        return 1;
    }

    int inputFileDescriptor = open(argv[1],O_RDONLY);
    int outputFileDescriptor = open(argv[2],O_WRONLY); // yes, because O_APPEND doesn't work on my PC :(
    if(inputFileDescriptor == -1 || outputFileDescriptor == -1)
    {
        perror("Cannot open one or more file");
        return 2;
    }
    lseek(outputFileDescriptor,0,2); //see previous comment

    char buffer[SIZE];
    int readFlag = 0;
    int appendFlag = 0;
    while(true)
    {
        readFlag = read(inputFileDescriptor,buffer,SIZE);
        if(readFlag == 0) break;
        if(readFlag == -1)
        {
            perror("Cannot read data");
            return 3;
        }

        appendFlag = write(outputFileDescriptor,buffer,readFlag);
        if(appendFlag == -1)
        {
            perror("Cannot append data to file");
            return 4;
        }
    }

    if(close(inputFileDescriptor) == -1 || close(outputFileDescriptor) == -1)
    {
        perror("Cannot close file");
        return 5;
    }

    return 0;
}