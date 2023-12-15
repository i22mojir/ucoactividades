#ifndef USER_H
#define USER_H

#include <string>


class user
{
private:
    std::string user_name_;
    std::string email_;
    std::string password_;
    //enum con intereses
    bool admin_status_; //0 para usuarios comunes y 1 para Administradores  
    bool blocked_status_; //0 para usuarios no bloqueados y 1 para usuarios bloqueados

public:
    std::string GetuserName(){return user_name_;}
    std::string GetEmail(){return email_;}
    std::string Getpassword(){return password_;}
    //void GetIntereses(){}
    bool GetAdmin(){return admin_status_;}
    bool GetBlocked(){return blocked_status_;}
};

#endif