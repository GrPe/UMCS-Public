//Work correctly only with upper case letters
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <fcntl.h>

#define SIZE 1024
void Cesar(char* buffer);

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        perror("Invalid number of arguments");
        return 1;
    }
    int inputFileDescriptor = open(argv[1],O_RDONLY);
    int appendFileDescriptor = open(argv[2],O_WRONLY);
    if(inputFileDescriptor == -1 || appendFileDescriptor == -1)
    {
        perror("Cannot open file");
        return 2;
    }
    lseek(appendFileDescriptor,0,2);

    char buffer[SIZE];
    int readFlag = 0;
    int appendFlag = 0;
    while(true)
    {
        readFlag = read(inputFileDescriptor,buffer,SIZE);
        if(readFlag == 0) break;
        if(readFlag == -1)
        {
            perror("Cannot read the file");
            return 3;
        }

        Cesar(buffer);
        appendFlag = write(appendFileDescriptor,buffer,readFlag);
        if(appendFlag == -1)
        {
            perror("Cannot append data");
            return 4;
        }
    }
    if(close(inputFileDescriptor) == -1 || close(appendFileDescriptor) == -1)
    {
        perror("Cannot close files");
        return 5;
    }

    return 0;
}
void Cesar(char* buffer)
{
    for(int i = 0;i<strlen(buffer);++i)
    {
        if(isalpha(buffer[i]))
        {
            buffer[i] +=8;
            if(buffer[i] > 'Z') buffer[i] -= 26;
        }
    }
}