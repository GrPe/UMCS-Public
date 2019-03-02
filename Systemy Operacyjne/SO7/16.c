#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    puts("------------Poczatek listy-------------------");
    system("ps -aux | tr -s ' ' | cut -d ' ' -f '2 11'");
    puts("-------------Koniec listy--------------------");
    
    return 0;
}