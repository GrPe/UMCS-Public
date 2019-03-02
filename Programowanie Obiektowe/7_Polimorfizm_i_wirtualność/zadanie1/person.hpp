#ifndef PERSON_HPP
#define PERSON_HPP
#include <string>

class Person
{
protected:
    std::string name;
public:
    Person();
    explicit Person(const std::string& name);
    virtual std::string ident() const;
};

#endif // PERSON_HPP
