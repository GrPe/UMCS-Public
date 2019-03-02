#include "teacher.hpp"

Teacher::Teacher(const std::string& name, const std::string& title) : Person(name)
{
    this->title = title;
}

std::string Teacher::ident() const
{
    return title + ' ' + name;
}
