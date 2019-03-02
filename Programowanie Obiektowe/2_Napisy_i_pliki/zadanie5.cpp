#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

std::vector<int> parse(const string& nap)
{
    std::istringstream iss(nap);
    std::vector<int> ret;
    int temp;
    while(!iss.eof())
    {
       iss>>temp;
       ret.push_back(temp);
    }
    return ret;
}

void fun(const string& path)
{
    fstream file;
    file.open(path,ios::in);
    while(!file.eof())
    {
        string temp;
        unsigned int sum = 0;
        getline(file,temp);
        std::vector<int> vec = parse(temp);
        for(const auto& x : vec)
        {
               sum+=x;
        }
        cout<<sum<<endl;
    }
    file.close();
}

int main()
{
    fstream file;
    file.open("plik.txt",ios::out);
    file<<"22 152 15 15 +15 15\n10 -10 -10 +10 10";
    file.close();
    fun("plik.txt");
    return 0;
}
