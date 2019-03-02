#include "student.hpp"

Student::Student(const User& user, int semestr) : User(user),semestr(semestr)
{}

Student::Student(const std::string& login, const std::string& password, int semestr) :
    User(login, password), semestr(semestr) {}
