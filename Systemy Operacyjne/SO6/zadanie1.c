#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 512 

int main(int argc, char* argv[])
{
	char buf[MAX];
	int desc_zr, desc_cel;
	int lbajt;

	if(argc < 3)
	{
		fprintf(stderr, "Zbyt malo argumentow! Podaj: %s <plik_zrodlowy> <plik_docelowy>", argv[0]);
		exit(1);
	}

	desc_zr = open(argv[1], O_RDONLY);
	if(desc_zr == -1)
	{
		perror("Blad otwarcia pliku zrodlowego");
		exit(1);
	}

	desc_cel = creat(argv[2], 0640);
	if(desc_cel == -1)
	{
		perror("Blad utworzenia pliku docelowego");
		exit(1);
	}

	while((lbajt = read(desc_zr,buf,MAX)) > 0)
	{
		if(write(desc_cel, buf, lbajt) == -1)
		{
			perror("Blad zapisu");
			exit(1);
		}
	}

	if(lbajt == -1)
	{
		perror("Blad zapisu");
		exit(1);
	}

	if(close(desc_zr) == -1 || close(desc_cel) == -1)
	{
		perror("blad zakmniecia pliku");
		exit(1);
	}
	return 0;
	
}
