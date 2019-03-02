#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    char buffer[] ="Lorem ipsum dolor sit amet, consectetur adipiscing elit";

    if(argc != 2)
    {
        printf("Invalid number of arguments");
        return 1;
    }

    int createTest = creat(argv[1],0640);
    if(createTest == -1)
    {
        perror("Cannot create a file");
        return 2;
    }

    int descriptor = open(argv[1],O_WRONLY);
    if(descriptor == -1)
    {
        perror("Cannot open file to write");
        return 3;
    }
    if(write(descriptor,buffer,sizeof(buffer)) == -1)
    {
        perror("Write operation failed");
        return 4;
    }
    if(close(descriptor) == -1)
    {
        perror("Cannot close the file");
        return 5;
    }

    return 0;
}