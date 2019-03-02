#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int parse(const string& nap)
{
    std::istringstream iss(nap);
    int sum{};
    int temp;
    while(!iss.eof())
    {
        iss>>temp;
        if(iss.fail()) break;
        sum+=temp;
    }
    return sum;
}

//copy output -> input;
void RewriteFile(const string &path)
{
    fstream input;
    fstream output;
    input.open(path, ios_base::out);
    output.open("temp.temp", ios_base::in);
    while(!output.eof())
    {
        string temp;
        getline(output,temp);
        input<<temp<<'\n';
    }
    input.close();
    output.close();
    remove("temp.temp");
}

void fun(const string& path)
{
    fstream file;
    fstream output;
    file.open(path,ios::in);
    output.open("temp.temp",ios::out);
    unsigned int numberOfLine{};
    while(!file.eof())
    {
        string temp;
        getline(file,temp);
        int sum = parse(temp);

        size_t pos = temp.rfind('=');
        if(pos != string::npos)
        {
            int sumToCheck = std::stoi(temp.substr(pos+1));
            if(sumToCheck != sum) cout<<"corrected "<<numberOfLine<<'\n';
        }
        numberOfLine++;

        output<<temp.substr(0,pos)<<" = "<<sum<<endl;
    }
    file.close();
    output.close();
    RewriteFile(path);

}

int main()
{
    //test
    fstream file;
    file.open("plik.txt",ios::out);
    file<<"22 152 15 15 +15 15 = 1569\n10 -10 -10 +10 10 = 111";
    file.close();
    fun("plik.txt");
    return 0;
}
