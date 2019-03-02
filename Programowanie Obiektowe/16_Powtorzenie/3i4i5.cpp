#include <list>
#include <string>
#include <sstream> 
#include <stdexcept> // do out_of_range
#include <iostream>// do ostream i maina

using namespace std;

class StringList
{
	list<string> listOfStrings;

	//operatory poza klas¹ musza byc zaprzyjaznione
	friend StringList operator+(const StringList& stringList,string str);
	friend StringList operator-(const StringList& stringList, string str);

	//do zadania 4
	friend ostream& operator<<(ostream& os, StringList& stringList);
	//przydaloby sie cos co przechowa nam informacje, ktore slowo obecnie mamy przekazywac
	int pozycja{ 0 };
	string getSlowo(); // metoda która bedzie zwracala nam odpowiednie slowo z listy

};

StringList operator+(const StringList& stringList, string str)
{
	StringList newStringList = stringList; // tworzymy nowy obiekt
	newStringList.listOfStrings.push_back(str); // twochê dlugie ale po prostu dodajemy napis do listy
	return newStringList;
}


StringList operator-(const StringList& stringList, string str)
{
	StringList newStringList = stringList;
	// szukamy napisu w liscie. Fukcja find zwraca nam iterator na znaleziony element
	list<string>::iterator iter = find(newStringList.listOfStrings.begin(), newStringList.listOfStrings.end(), str);
	if (iter != newStringList.listOfStrings.end()) // albo iterator za ostatni element ( end() ) jesli nic nie znajdzie
	{
		newStringList.listOfStrings.erase(iter); // usuwamy element z listy
	}
	return newStringList;
}

//zadanie 4

//implentacja naszej metody
//Metoda nieoptymalna ale w miare ³atwa i logiczna i dziala :>
string StringList::getSlowo()
{
	auto iter = listOfStrings.begin(); 
	stringstream ss(*iter);
	string wyraz;
	for (int i = 0; i < pozycja+1; i++) // petla wczytuje wyrazy az nie dojdzie do tego, który chcemy dostac
	{
		if (!(ss >> wyraz)) // wczytujemy wyraz i jeœli siê nie uda przestawiamy sie na nastêpny napis
		{
			iter++; // przestawiamy

			//zadanie 5 ---------------------------------------------------

			//sprawdzamy czy wyszlismy poza zakres listy i jeœli tak to rzucamy wyjatek
			if (iter == listOfStrings.end())
			{
				pozycja = 0;
				throw out_of_range("String List Out Of Range");
				//wracamy na poczatek
			}
			//koniec 5 ----------------------------------------------------

			ss = stringstream(*iter); // tworzymy nowy strumien 
			i--; // zmiejszamy licznik, bo w koncu nie uda³o nam siê nic wczytac
		}
	}
	pozycja++; // przestawiamy pozycje o jeden do przodu
	return wyraz; // zwracamy nasz wyraz;

}

//operator<< zawsze zwraca ostream i jako pierwszy parametr przyjmuje ostream
ostream& operator<<(ostream& os, StringList& stringList)
{
	os << stringList.getSlowo(); //Uwaga. Uzywamy naszego "os" a nie cout !!!
	return os;
}


int main()
{
	StringList stringList;
	stringList = stringList + "Ala";
	stringList = stringList + "ma";
	stringList = stringList + "kota";
	stringList = stringList + "i";
	stringList = stringList + "psa";

	stringList = stringList - "psa";
	stringList = stringList - "psa";


	//zadanie 4 i 5
	try
	{
		cout << stringList << endl;
		cout << stringList << endl;
		cout << stringList << endl;
		cout << stringList << endl;
		cout << stringList << endl;
	}
	catch (exception& ex) // lapiemy wyjatek :)
	{
		cout << ex.what() << endl;
	}
	cout << stringList << endl;

	return 0;
}
