#include "subject.hpp"

Subject::Subject(const std::string &name, int maxAmountOfStudent) :
    name(name), maxAmountOfStudent(maxAmountOfStudent)
{}

Subject::Subject(Subject &subject)
{
    this->name = subject.name;
    this->maxAmountOfStudent = subject.maxAmountOfStudent;
    this->amountOfStudent = 0;
    for(int i =0;i<this->amountOfStudent;++i)
        this->tabOfStudent[i] = nullptr;
}

bool Subject::AddStudent(Student *student)
{
    if(maxAmountOfStudent == amountOfStudent) return false;
    tabOfStudent[amountOfStudent++]  = student;
    return true;
}

Student &Subject::GetStudent(int index, bool &isGood)
{
    if(index < 0 || index >= amountOfStudent)
    {
        isGood = false;
        return *tabOfStudent[0];
    }
    isGood = true;
    return *tabOfStudent[index];
}
