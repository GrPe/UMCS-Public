#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc !=2)
	{
		fprintf(stderr,"Niepoprawna liczba argumentow");
		exit(2);
	}

	int descriptor = open(argv[1],O_RDONLY);
	if(descriptor == -1)
	{
		perror("Blad otwarcia pliku");
		exit(1);
	}

	int size = lseek(descriptor, 0,SEEK_END);
	if(size == -1)
	{
		perror("Blad pliku");
		exit(3);
	}
	printf("%iB",size);
	if(close(descriptor) == -1)
	{
		perror("Blad zamkniecia pliku");
		exit(4);
	}
	return 0;
}

