#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int zadanie1(char**& tab, int n)
{
    int size = 0;
    for(int i = 0;i<n;++i) if(tab[i] != nullptr) size++;
    char** retArr = new char*[size];
    int currentPos=0;
    for(int i = 0;i<n;++i)
        if(tab[i] != nullptr) retArr[currentPos++] = tab[i];

    delete[] tab;
    tab = retArr;
    retArr = nullptr;
    return size;
}


class WordReplacer
{
    vector<string> content;
public:
    explicit WordReplacer(const string& path)
    {
        fstream file;
        file.open(path,ios::in);
        string temp;
        while((file>>temp))
            content.push_back(temp);
        file.close();
    }

    void Replace(unsigned int a, unsigned int b)
    {
        if(a == 0 || b == 0) return;
        if(--a >= content.size() || --b >= content.size()) return;
        string temp = content[a];
        content[a] = content[b];
        content[b] = temp;
    }

    string Text() const
    {
        string ret;
        //for(const auto& str : content) ret +=str + " ";
        for_each(content.begin(),content.end(),[&ret](const string& str) -> void {ret += str+ " ";});
        return ret;
    }
};


class Stworek
{
public:
    virtual void powiedz(string& ) = 0;
};

class StworekJakajacy : public Stworek
{
public:
    virtual void powiedz(string& text) override
    {
        for(auto c : text)
        {
            if(isalpha(c))
             {
                 cout<<c<<c;
                 break;
             }
        }
        cout<<text<<endl;
    }
};

class StworekBezR : public Stworek
{
public:
    virtual void powiedz(string& text) override
    {
        for(auto c : text)
        {
            if(c == 'r') cout<<'l';
            else cout<<c;
        }
        endl(cout);
    }
};

class Punkt
{
    int x,y;
public:
    Punkt(int x = 0, int y = 0){this->x = x; this->y = y;}
    int getX()const {return x;}
    int getY()const {return y;}

    Punkt operator!()
    {
        return Punkt(-x,-y);
    }
};

int main()
{

    Punkt punkt{2,3};
    Punkt punkt2 = !punkt;
    cout<<punkt2.getX()<<" "<<punkt2.getY()<<endl;


    char** tab = new char*[5]{nullptr};
    tab[2] = new char{'A'};
    tab[3] = new char{'B'};
    cout<<zadanie1(tab,5)<<'\n';
    cout<<*tab[0]<<" "<<*tab[1]<<endl;

    WordReplacer wordReplacer("file.txt");
    wordReplacer.Replace(1,2);
    wordReplacer.Replace(3,4);
    wordReplacer.Replace(100,200);
    cout<<wordReplacer.Text()<<endl;


    Stworek* stworek1 = new StworekJakajacy();
    Stworek* stworek2 = new StworekBezR();
    string text = "  Al ma kota RRRrrr";
    stworek1->powiedz(text);
    stworek2->powiedz(text);
    return 0;
}
