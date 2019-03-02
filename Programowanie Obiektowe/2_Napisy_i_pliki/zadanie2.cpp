#include <iostream>
#include <string>

using namespace std;

int main()
{
    string nap1, nap2, nap3;
    getline(cin,nap1);
    cin>>nap2;
    cin>>nap3;
    std::size_t pos = nap1.find(nap2);
    while(pos != nap1.npos)
    {
        nap1.replace(pos,nap3.size(),nap3);
        pos = nap1.find(nap2);
    }
    cout<<nap1<<endl;

    return 0;
}
