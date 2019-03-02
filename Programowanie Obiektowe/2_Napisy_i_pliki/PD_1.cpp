#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>

int main()
{
    using std::cin;
    using std::cout;
    using std::string;

    string path;

    cin>>path;

    std::fstream file;
    file.open(path,std::ios::out);

    string str;
    uint32_t counter{};
    while(cin>>str)
    {
        //cin>>str;
        counter +=str.size();
        if(counter>20)
        {
            int i{};
            int temp = counter - str.size();
            int shift = 20 - temp;
            bool First{true};
            while(counter>20)
            {
                if(First)
                {
                    file<<str.substr(i*20,shift)<<'\n';
                    First = true;
                }
                temp = str.size() - (i*20+shift);
                if(temp > 20)
                    file<<str.substr(i*20+shift,20)<<'\n';
                else
                {
                    file<<str.substr(i*20+shift)<<" ";
                    counter = str.size() - (i*20+shift) + 1;
                }
                ++i;
            }
        }
        else
        {
            file<<str<<" ";
            ++counter;
        }

    }
    file.close();


    return 0;
}