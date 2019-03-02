#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

class Point
{
public:
    float x,y;
};

vector<Point> foo2(const vector<Point>& vec, const Point& p1, const Point& p2)
{
    vector<Point> ret;
    for(auto p : vec)
    {
        if(p.x < p2.x || p.x > p1.x || p.y < p1.y || p.y > p2.y) continue;
        ret.push_back(p);
    }
    return ret;
}

void foo3(const list<string>::iterator& beg,const list<string>::iterator& end)
{
    for(auto i = beg; i !=end;++i)
    {
        cout<<(*i)<<endl;
    }
}

vector<int> foo4(const vector<int>& vec1, const vector<int>& vec2)
{
    //v1
    //vector<int> ret(vec1);
    //ret.reserve(ret.size()*2);
    //ret.insert(ret.end(),vec2.begin(),vec2.end());
    //sort(ret.begin(),ret.end());
    //ret.erase(unique(ret.begin(),ret.end()),ret.end());

    //v2
    set<int> s;
    s.insert(vec1.begin(),vec1.end());
    s.insert(vec2.begin(),vec2.end());
    vector<int> ret(s.size());
    copy(s.begin(),s.end(),ret.begin());
    return ret;
}


class Phonebook
{
    vector<pair<string,int>> data;
public:
    Phonebook() {}
    void Show() const
    {
        endl(cout);
        for(auto p : data)
        {
            cout<<"Name: "<<p.first<<" "<<"Number: "<<p.second<<endl;
        }
        endl(cout);
    }
    void Add(const string& name,int number)
    {
        data.push_back(pair<string,int>(name,number));
    }
    void Remove(const string& name, int number)
    {
        vector<pair<string,int>>::iterator iter = data.end();
        for(auto x = data.begin();x !=data.end();++x)
        {
            if(x->first==name && x->second == number)
            {
                iter = x;
                break;
            }
        }
        if(iter != data.end())
            data.erase(iter,iter+1);
    }
    void Modify(const string& name, int number, const string& newName, int newNumber)
    {
        vector<pair<string,int>>::iterator iter = data.end();
        for(auto x = data.begin();x !=data.end();++x)
        {
            if(x->first==name && x->second == number)
            {
                iter = x;
                break;
            }
        }
        if(iter != data.end())
        {
            iter->first = newName;
            iter->second = newNumber;
        }
        else Add(newName,newNumber);
    }

};

int main()
{
    vector<Point> points{Point{1,2},Point{5,3},Point{2,14},Point{4,10},Point{5,5},Point{3,5}};
    sort(points.begin(),points.end(),[](const Point& p, const Point& p2){return p.x<p2.x ;});
    for(auto x : points)
    {
        cout<<x.x<< " "<<x.y<<endl;
    }
    sort(points.begin(),points.end(),[](const Point& p, const Point& p2){return p.y<p2.y;});
    for(auto x : points)
    {
        cout<<x.x<<" "<<x.y<<endl;
    }
    endl(cout);
    cout<<"Test zadanie 2\n";
    vector<Point> vec = foo2(points,Point{1,1},Point{5,5});
    for(auto x : vec)
    {
        cout<<x.x<<" "<<x.y<<endl;
    }

    endl(cout);
    cout<<"test zadanie 3\n";
    list<string> lista{"Ala", "Ma","kota","abv","koniec"};
    auto f = find(lista.begin(),lista.end(),"kota");
    foo3(f,lista.end());

    endl(cout);
    cout<<"test zadanie 4\n";
    vector<int> a{1,5,13,8,50,2,6};
    vector<int> b{2,5,14,24,788,1,1,1};
    auto c = foo4(a,b);
    for(auto x : c)
    {
        cout<<x<<endl;
    }

    endl(cout);
    cout<<"test praca domowa 1\n";
    Phonebook phonebook;
    phonebook.Add("Jan",666666666);
    phonebook.Add("Jerzy",123456789);
    phonebook.Show();
    phonebook.Modify("Jerzy",123456789,"Jerzy",987654321);
    phonebook.Show();
    phonebook.Remove("Jan",666666666);
    phonebook.Show();

    return 0;
}
