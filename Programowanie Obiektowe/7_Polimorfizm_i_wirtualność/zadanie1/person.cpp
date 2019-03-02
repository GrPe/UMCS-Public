#include "person.hpp"

Person::Person(){}

Person::Person(const std::string &name)
{
    this->name = name;
}

std::string Person::ident() const
{
    return name;
}
