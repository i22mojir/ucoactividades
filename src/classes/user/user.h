#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>

enum Intereses
{
    Tecnologia,
    Medicina,
    Ciencia,
    Derecho,
    Ninguno
};

class User
{
private:
    std::string user_name_;
    std::string email_;
    std::string password_;
    Intereses intereses_;
    bool admin_status_; //0 para usuarios comunes y 1 para Administradores

public:
    User(std::string user_name = "empty", std::string email = "empty", std::string password = "empty", Intereses intereses = Ninguno, bool admin_status = false)
        {user_name_ = user_name; email_ = email; password_ = password; intereses_ = intereses; admin_status_ = admin_status;}

    std::string GetUserName() const { return user_name_; }
    std::string GetEmail() const { return email_; }
    std::string GetPassword() const { return password_; }
    Intereses GetIntereses() const { return intereses_; }
    bool GetAdmin() const { return admin_status_; }

    void SetUserName(std::string user_name) { user_name_ = user_name; }
    void SetEmail(std::string email) { email_ = email; }
    void SetPassword(std::string password) { password_ = password; }
    void SetIntereses(Intereses intereses) { intereses_ = intereses; }
    void SetAdminStatus(bool admin_status) { admin_status_ = admin_status; }

    std::string GetDetails() const;
};

#endif