#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    if(argc !=2)
    {
        perror("Invalid number of arguments");
        return 1;
    }

    //test: argument is not a number
    for(int i = 0; i<strlen(argv[1]);++i)
    {
        if(isdigit(argv[1][i]) == 0)
        {
            perror("Invalid argument");
            return 2;
        }
    }

    int n = atoi(argv[1]);
    char fileName[12];
    for(int i = 1;i<=n;++i)
    {
        sprintf(fileName,"PLIK_%d",i);
        int createFlag = creat(fileName,0640);
        if(createFlag == -1)
        {
            perror("Cannot create files");
            return 3;
        }
    }
    return 0;
}