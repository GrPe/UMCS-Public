#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    string path;
    cin>>path;
    fstream file;
    file.open(path,std::ios::out);

    string temp;
    int counter = 0;
    while(true)
    {
        cin>>temp;
        if(cin.eof()) break;
        counter +=temp.size();
        if(counter > 20)
        {
            counter = temp.size();
            file<<'\n'<<temp<<" ";
        }
        else
        {
            file<<temp<<" ";
        }
    }
    file.close();


    return 0;
}
