#include <iostream>
#include "teacher.hpp"
#include "student.hpp"
#include <memory>
using namespace std;

int main()
{
    Person *p1 = new Student{"Ala",1};
    Student s1("Jas",1);
    cout<<p1->ident()<<endl;
    cout<<s1.ident()<<endl;
    Person* persons[5];
    persons[0] = new Student{"Ala",1};
    persons[1] = new Teacher{"Zosia", "doktor"};
    persons[2] = new Student{"Jas",2};


    return 0;
}
