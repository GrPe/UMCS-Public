#ifndef USER_HPP
#define USER_HPP
#include <string>

class User
{
protected:
    std::string login;
    std::string password;
public:
    User(const std::string& login, const std::string& password);
    bool Authorize(const std::string& login, const std::string& password);
};

#endif // USER_HPP
