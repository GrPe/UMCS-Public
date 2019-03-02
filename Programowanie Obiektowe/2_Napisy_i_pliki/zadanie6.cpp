#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

using namespace std;

int main()
{
    string path;
    cin>>path;

    DIR* dirp = opendir(path.c_str());
    dirent* dp;
    std::vector<std::string> vec;
    while((dp = readdir(dirp))!=NULL)
        vec.push_back(dp->d_name);

    closedir(dirp);

    for(const auto& x : vec)
    {
        cout<<x<<endl;
    }


    return 0;
}
