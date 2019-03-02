#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "person.hpp"


class Student : public Person
{
public:
    int semester;
    explicit Student(const std::string& name,int semester);
    virtual std::string ident() const override;
};

#endif // STUDENT_HPP
