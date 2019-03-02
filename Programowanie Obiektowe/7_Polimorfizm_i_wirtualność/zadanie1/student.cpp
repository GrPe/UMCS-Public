#include "student.hpp"
#include <string>

Student::Student(const std::string& name, int semester) : Person(name)
{
    this->semester = semester;
}

std::string Student::ident() const
{
    return std::to_string(semester) + ' ' + name;
}
