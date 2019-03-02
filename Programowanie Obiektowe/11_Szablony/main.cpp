#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

template <typename T>
T& foo1(T* begin, T* end)
{
	T* min = begin;
	for (T* i = begin; i <= end; i++)
	{
		if (*i < *min)
			min = i;
	}
	return *min;
}

template<>
string& foo1(string* begin, string* end)
{
	string* min = begin;
	for (string* i = begin; i <= end; ++i)
	{
		if (lexicographical_compare(i->begin(), i->end(), min->begin(), min->end(), [](char a, char b) -> bool
		{return tolower(a) < tolower(b); }))
		{
			min = i;
		}
	}
	return *min;
}


template <template<typename ...> class C, typename T>
T& foo3(C<T>& container)
{
	T& min = *container.begin();
	for (auto& i : container)
	{
		if (i < min)
		{
			min = i;
		}
	}
	return min;
}

//zadanie 1 pd
template <template<typename ...> class C>
string& foo3(C<string> container)
{
	string& min = *container.begin();
	for (auto& i : container)
	{
		if (lexicographical_compare(i.begin(), i.end(), min.begin(), min.end()))
		{
			min = i;
		}
	}

	return min;
}

template <typename T, int size>
class Table
{
	T* tab;

public:
	Table();
	~Table();
	T& operator[](int index);
	template<typename R> void Add(R& a);
};


template<typename T, int size>
Table<T, size>::Table()
{
	tab = new T[size];
}

template<typename T, int size>
Table<T, size>::~Table()
{
	delete[] tab;
}

template<typename T, int size>
T& Table<T, size>::operator[](int index)
{
	return tab[index];
}

//zadanie 5
template<typename T, int size>
template<typename R>
void Table<T, size>::Add(R & a)
{
	for (int i = 0; i < size; i++)
		tab[i] += a;
}


//Zadanie 2 pd

template <int size>
class Table<string, size>
{
	string* tab;

public:
	Table();
	~Table();
	string& operator[](int index);
	 void Add(const string& a);
};

template<int size>
Table<string, size>::Table()
{
	tab = new string[size];
}

template<int size>
Table<string, size>::~Table()
{
	delete[] tab;
}


template<int size>
string& Table<string, size>::operator[](int index)
{
	return tab[index];
}

template <int size>
void Table<string, size>::Add(const string & a)
{
	for (int i = 0; i < size; ++i)
	{
		if (tab[i][tab[i].size()] == ' ' || a[0] == ' ') tab[i] += a;
		else tab[i] += ' ' + a;
	}
}

int main()
{
	//test 1
	int tab[10]{ 1,2,5,7,9,2,3,5,6,8 };
	cout << foo1(tab + 2, tab + 9) << endl;

	//test 2
	string t[4]{ "ala","ma","kota","null" };
	cout << foo1(t, t + 3) << endl;

	//test3
	vector<int> vec{ 1,2,3 };
	cout << foo3<vector, int>(vec) << endl;

	//test zadanie 1 pd
	vector<string> vecs{ "kota","ala","ma" };
	cout << foo3(vecs) << endl; // dla VS 2017
	//cout << foo3<vector, string>(vecs) << endl; // dla GCC 7.2

	//test4
	{
		Table<int, 3> table;
		table[0] = 3;
		table[1] = 4;
		table[2] = 134;
		cout << table[2] << endl;
	}

	//test 2 PD
	{
		Table<string, 3> table;
		table[0] = "ala";
		table[1] = "ma";
		table[2] = "kota";
		table.Add("cos");
		cout << table[2] << endl;
	}

	return 0;
}

