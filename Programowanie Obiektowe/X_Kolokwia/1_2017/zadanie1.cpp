#include <iostream>


int foo(char **&arr, int size)
{
	//zliczanie elementow roznych od nullptr
	int counter = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] != nullptr) counter++;

	//kopiujemy wskazniki do tablicy tymczasowej
	int j = 0;
	char **tempArr = new char*[counter];
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] != nullptr)
		{
			tempArr[j] = arr[i];
			++j;
		}
	}

	//usuwamy stara tablice i tworzymy nowa
	delete[] arr;
	arr = new char*[counter];

	//przestawiamy wskaznik z tempArr na arr;
	arr = tempArr;
	tempArr = nullptr;

	return counter;
}

int main()
{
	char** arr = new char*[5]{ new char{'c'}, new char{'d'}, nullptr, new char{'W'}, nullptr };
	int newSize = foo(arr, 5);

	for (int i = 0; i < newSize; ++i) std::cout << *arr[i] << std::endl;


	return 0;
}