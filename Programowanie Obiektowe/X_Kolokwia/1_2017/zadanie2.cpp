#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class WordReplacer
{
	string* content;
	int size;
public:
	WordReplacer(string path)
	{
		//otwieramy plik itp.
		size = 0;
		fstream file;
		file.open(path, ios::in);
		string temp;
		//sprawdzamy rozmiar pliku (ile wyrazow)
		while ((file >> temp)) size++;
		//przestawiamy wskaznik odczytu pliku na poczatek
		file.clear();
		file.seekg(0, ios::beg);
		//alokujemy pamiec
		content = new string[size];
		//wczytujemy dane
		int i = 0;
		while ((file >> temp))
		{
			content[i] = temp;
			++i;
		}
		//zamykamy plik
		file.close();
	}

	void Replace(unsigned int a, unsigned int b)
	{
		if (a == 0 || b == 0) return; //przerywa funckje
		if (a > size || b > size) return; // jw.
		//zmiejszamy indexy zeby bylo od 0
		--a;
		--b;
		//zamiana
		string temp = content[a];
		content[a] = content[b];
		content[b] = temp;
	}

	string Text()
	{
		string ret;
		for (int i = 0; i < size; ++i)
			ret += content[i] + " ";
		return ret;
	}

	~WordReplacer()
	{
		delete[] content;
	}

};

int main()
{
	WordReplacer replacer("file.txt");
	replacer.Replace(1, 3);
	replacer.Replace(2, 4);
	replacer.Replace(1, 100);
	cout << replacer.Text() << endl;
	return 0;
}
