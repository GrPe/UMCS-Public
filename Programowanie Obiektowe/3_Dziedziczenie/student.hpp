#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "user.hpp"
#include <string>

class Student : public User
{
private:
    int semestr{};
public:
    Student(const User& user, int semestr);
    Student(const std::string& login, const std::string& password, int semestr);
};

#endif // STUDENT_HPP
