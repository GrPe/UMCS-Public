#include <iostream>
#include <algorithm>
#include "list.hpp"

//using namespace std;

int main()
{
    list<int> lista;
    lista.push_back(12);
    lista.push_back(15);
    lista.push_front(10);
    lista.Display();
    std::endl(std::cout);


    lista.push_back(321456);
    lista.push_back(78456);
    lista.push_back(789321);


    for(auto x : lista)
        std::cout<<x<<std::endl;
    std::endl(std::cout);

    lista.pop_front();

    std::for_each(lista.begin(),lista.end(),[](int x){std::cout<<x<<std::endl;});
    return 0;
}
