#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    Array<int> array(50);
    array[3]=10;
    for(auto x : array)
    {
        cout<<x<<endl;
    }
    return 0;
}
