#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

template <typename T>
T foo(T* tab, uint32_t size)
{
    if(size == 0) throw invalid_argument("Array cannot be empty\n");

    //find most common
    unordered_map<T,uint32_t> values;
    for(uint32_t i = 0;i<size;i++)
    {
        values[tab[i]]++;
    }

    uint32_t counter = 0;
    T mostCommon;

    for(auto x : values)
    {
        if(counter < x.second)
        {
            counter = x.second;
            mostCommon = x.first;
        }
    }

    vector<T> except;
    //find duplicates
    for(auto x : values)
    {
        if(x.second == counter) except.push_back(x.first);
    }
    if(except.size() != 1) throw except;

    return mostCommon;
}


int main()
{
    auto * tab = new int [7]{1,2,3,1,4,10,20};
    //auto * tabs = new string[3]{"aka","ala","ala"};

    try
    {
        cout<<foo(tab,7)<<endl;
    }
    catch(vector<int>& ex)
    {
        cout<<"Exception:\n";
        for(auto x : ex)
        {
            cout<<x<<endl;
        }
    }
    catch(invalid_argument& ex)
    {
        cout<<ex.what()<<endl;
    }

    delete[] tab;

}
