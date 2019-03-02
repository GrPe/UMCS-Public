#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    puts("Poczatek");
    system("ls");
    puts("Koniec");
    
    return 0;
}