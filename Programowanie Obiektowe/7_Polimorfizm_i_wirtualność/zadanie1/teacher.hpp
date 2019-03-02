#ifndef TEACHER_HPP
#define TEACHER_HPP
#include "person.hpp"
#include <string>

class Teacher : public Person
{
private:
    std::string title;
public:
    Teacher(const std::string& name, const std::string& title);
    virtual std::string ident() const override;
};

#endif // TEACHER_HPP
