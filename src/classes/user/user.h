#ifndef USER_H
#define USER_H

#include <string>

class User
{
private:
    std::string user_name_;
    std::string email_;
    std::string password_;
    //enum con intereses
    bool admin_status_; //0 para usuarios comunes y 1 para Administradores  

public:
    User(std::string user_name="empty", std::string email="empty", std::string password="empty", bool admin_status=0)
    {user_name_ = user_name; email_ = email; password_ = password; admin_status_ = admin_status;}

    std::string GetUserName(){return user_name_;}
    std::string GetEmail(){return email_;}
    std::string GetPassword(){return password_;}
    //void GetIntereses(){}
    bool GetAdmin(){return admin_status_;}

    void SetUserName(std::string user_name){user_name_ = user_name;}
    void SetEmail(std::string email){email_ = email;}
    void SetPassword(std::string password){password_ = password;}
    void SetAdminStatus(bool admin_status){admin_status_ = admin_status;}
};

#endif