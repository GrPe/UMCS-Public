#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "student.hpp"
#include <string>

class Subject
{
private:
    std::string name{};
    int maxAmountOfStudent{};
    int amountOfStudent{};
    Student* tabOfStudent[100]{};
public:
    Subject(const std::string& name, int maxAmountOfStudent);
    Subject(Subject& subject);
    bool AddStudent(Student* student);
    Student& GetStudent(int index, bool& isGood);
};

#endif // SUBJECT_HPP
