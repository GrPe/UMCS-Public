#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //
    fstream file;
    file.open("plik.txt",ios::out);
    file<<"Ala ma kota\n kot ma ale\nkot\nkot";
    file.close();
    //

    string path = "plik.txt";
    string napis;

    //cin>>path;
    cin>>napis;
   // fstream file;
    file.open(path,ios::in);

    string temp;
    unsigned int counter = 0;
    while(!file.eof())
    {
        file>>temp;
        if(temp == napis) counter++;
    }
    file.close();
    cout<<counter<<'\n';

    return 0;
}
