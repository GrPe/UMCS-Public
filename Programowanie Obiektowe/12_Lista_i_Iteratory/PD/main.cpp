#include <iostream>
#include <algorithm>
#include "list.hpp"

using namespace std;

int main()
{
	Deque<int> lista;
	lista.push_back(12);
	lista.push_back(15);
	lista.push_front(10);
	lista.Display();
	std::endl(std::cout);


	lista.push_back(321456);
	lista.push_back(78456);
	lista.push_back(789321);
	lista.Display();
	std::endl(std::cout);

	lista.pop_back();
	lista.pop_front();
	lista.Display();
	std::endl(std::cout);


	for (auto x : lista)
		std::cout << x << std::endl;
	std::endl(std::cout);

	for (auto x = lista.begin(); x != lista.end(); x++)
	{
		cout << *x << endl;
	}

	return 0;
}
