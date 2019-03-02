#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string napis;
    cin>>napis;
    char min{toupper(napis[0])};
    char max{toupper(napis[0])};
    for(auto x : napis)
    {
        if(min > toupper(x)) min = toupper(x);
        if(max < toupper(x)) max = toupper(x);
    }
    cout<<"MIN: "<<min<<" MAX: "<<max<<'\n';
    return 0;
}
