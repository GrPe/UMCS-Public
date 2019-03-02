#include <iostream>
#include <string>
#include <vector>
#include <fstream>
//POSIX
#include <sys/types.h>
#include <dirent.h>


void readDirectory(const std::string& path, std::vector<std::string>& vec)
{
    DIR* dir = opendir(path.c_str());
    dirent* dr;
    while((dr = readdir(dir))!=nullptr)
    {
        vec.push_back(dr->d_name);
    }
    closedir(dir);
}

int main()
{
    std::string path;
    std::cin>>path;

    int maxNumber = -0x80000000;
    std::string text = "none";

    std::vector<std::string> stringVector;
    readDirectory(path,stringVector);
    for(auto& x : stringVector)
    {
        if(x[0] == 'p' && x[1] == '_')
        {
            std::ifstream file;
            file.open(path +"/"+ x);

            std::string temp;
            int tempNumber;
            getline(file,temp);
            file>>tempNumber;
            if(tempNumber > maxNumber)
            {
                maxNumber = tempNumber;
                text = temp;
            }
            file.close();
        }
    }
    std::cout<<text<<std::endl;
    return 0;
}