#include <list>
#include <map>
#include <string>
#include <sstream> // do stringstream
#include <iostream> // do maina

using namespace std;

template <typename T>
map<T, int> foo(list<T>& lista)
{
	map<T, int> mapa; // tworzymy mape
	//zliczamy ilosc wystapien elementow w liscie i zapisujemy je do mapy
	// petla zakresowa for. zaczyna od pierwszego elementu i konczy na ostatnim
	//opcjonalnie mozna uzyc petli po iteratorze czyli 
	//for(auto i = lista.begin(); i!= lista.end(); i++)
	for (T element : lista)
	{
		mapa[element]++; // to dziala tak, ze jesli istnieje juz ten element w mapie to zwiekszy licznik (int) o jeden
						//jesli element nie istnieje to wstawi go i zwiekszy licznik o jeden;
						//taka tablica z indeksem, który moze byc wszystkim np stringiem i sama zwieksza swoj rozmiar
	}
	return mapa;
}

//zadanie 2

template <> // specjalizacja, usuwamy argument szablonu
map<string, int> foo(list<string>& lista) // zamieniamy T na string
{
	map<string, int> mapa; //i tu
	for (string element : lista) // tu te¿
	{
		//teraz musimy wyci¹gnac slowa z listy. Mozna szukac spacja
		//albo uzyc string streama
		stringstream ss(element); // tworzymy nowy strumien
		string slowo;
		while (ss >> slowo) // pobieramy po jednym slowie do konca zdania/strumienia
		{
			mapa[slowo]++; // tak jak w pierwszym zadaniu
		}
	}
	return mapa;
}

int main()
{
	//test zadanie 1
	{
		list<int> a;
		a.push_back(1);
		a.push_back(4);
		a.push_back(7);
		auto c = foo(a);
		for (auto x : c)
		{
			cout << x.first << " " << x.second << endl; // wyswietlanie mapy
		}
	}
	//test zadanie 2
	{
		list<string> a;
		a.push_back("Ala ma kota");
		a.push_back("Ala nie ma kota");
		a.push_back("Just another weird string");
		auto c = foo(a);
		for (auto x : c)
		{
			cout << x.first << " " << x.second << endl;
		}
	}
	return 0;
}