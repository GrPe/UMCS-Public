#include <iostream>
#include "regularprism.hpp"
#include "regularpyramid.hpp"

using namespace std;

int main()
{
    poly::RegularPolyhedron* arr;
    arr = new poly::RegularPrism(2,3,4);
    //arr[1] = new poly::
    cout<<arr->volume()<<endl;
    return 0;
}
