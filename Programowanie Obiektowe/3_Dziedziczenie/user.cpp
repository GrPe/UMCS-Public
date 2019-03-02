#include "user.hpp"

User::User(const std::string& login, const std::string& password) :
    login(login), password(password) {}


bool User::Authorize(const std::string& login, const std::string& password)
{
    if(this->login == login && this->password == password)
        return true;
    else return false;
}
