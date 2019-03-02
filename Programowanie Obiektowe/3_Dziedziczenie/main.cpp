#include <iostream>
#include "user.hpp"
#include "student.hpp"
#include "subject.hpp"

int main()
{
    User user{"Jan", "asd"};
    Student student{"Jan","qzswefca",2};
    Student student2{user,2};
    Student student3{"Jan","password",5};

    Subject sub("infor",3);
    sub.AddStudent(&student);
    sub.AddStudent(&student2);
    std::cout<<sub.AddStudent(&student3)<<std::endl;
    std::cout<<sub.AddStudent(&student)<<std::endl;

    Student stud3(student);
    bool isGood;
    stud3 = sub.GetStudent(2,isGood);

    Subject subject(sub);


    return 0;
}
