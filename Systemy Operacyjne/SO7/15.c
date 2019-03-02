#include <stdio.h>
#include <unistd.h>

int main()
{
    //wyswietla zawartosc biezacego katalogu, ale nie wyswietli "koniec"
    printf("Poczatek\n");
    execlp("ls","ls","-a",NULL);
    printf("Koniec\n");
    
    return 0;
}