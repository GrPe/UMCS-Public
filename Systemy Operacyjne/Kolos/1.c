#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        puts("Invalid number of arguments");
        return 1;
    }
    int fileDesc = open(argv[1],O_RDONLY);
    if(fileDesc == -1)
    {
        puts("Cannot open file");
        return 2;
    }
    size_t size = lseek(fileDesc,0,SEEK_END);
    close(fileDesc);
    printf("Size in bytes: %ld\n",size);

    return 0;
}