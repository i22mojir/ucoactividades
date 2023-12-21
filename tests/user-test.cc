#include "../src/classes/user/user.h"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    User obj;
    std::vector<User> usuarios;

    printf("%i", usuarios.size());

    if(obj.GetUserName() != "empty"){printf("CONSTRUCTOR TEST FAILED");   return -1;}
    if(obj.GetEmail() != "empty"){printf("CONSTRUCTOR TEST FAILED");   return -1;}
    if(obj.GetPassword() != "empty"){printf("CONSTRUCTOR TEST FAILED");   return -1;}
    if(obj.GetIntereses() != Ninguno){printf("CONSTRUCTOR TEST FAILED");   return -1;}
    if(obj.GetAdmin() != false){printf("CONSTRUCTOR TEST FAILED");   return -1;}

    obj.SetUserName("usuario1234");
    obj.SetEmail("usuario1234@uco.es");
    obj.SetPassword("12345678");
    obj.SetIntereses(Medicina);
    obj.SetAdminStatus(true);

    if(obj.GetUserName() != "usuario1234"){printf("USER_SET TEST FAILED");   return -1;}
    if(obj.GetEmail() != "usuario1234@uco.es"){printf("USER_SET TEST FAILED");   return -1;}
    if(obj.GetPassword() != "12345678"){printf("USER_SET TEST FAILED");   return -1;}
    if(obj.GetIntereses() != Medicina){printf("USER_SET TEST FAILED");   return -1;}
    if(obj.GetAdmin() != true){printf("USER_SET TEST FAILED");   return -1;}

    usuarios.push_back(obj);
    std::string cadena;
    cadena = "usuario1234";
    if (obj.ComprobarNombre(usuarios, cadena) != false){printf("COMPROBAR NOMBRE TEST FAILED %s %s", usuarios[0].GetUserName().c_str(), cadena.c_str());   return -1;}
    cadena = "usuario";
    if (obj.ComprobarNombre(usuarios, cadena) != true){printf("COMPROBAR NOMBRE TEST FAILED %s %s", usuarios[0].GetUserName().c_str(), cadena.c_str());   return -1;}
    cadena = "usuario1234@uco.es";
    if (obj.ComprobarEmail(usuarios, cadena) != false){printf("COMPROBAR EMAIL TEST FAILED %s %s", usuarios[0].GetUserName().c_str(), cadena.c_str());   return -1;}
    cadena = "usuario1234";
    if (obj.ComprobarEmail(usuarios, cadena) != true){printf("COMPROBAR EMAIL TEST FAILED %s %s", usuarios[0].GetUserName().c_str(), cadena.c_str());   return -1;}
    cadena = "1234567";
    if (obj.CumpleRequisitosContrasena(cadena) != false){printf("COMPROBAR CONTRASEÑA TEST FAILED %s", cadena.c_str());   return -1;}
    cadena = "12345678";
    if (obj.CumpleRequisitosContrasena(cadena) != true){printf("COMPROBAR CONTRASEÑA TEST FAILED %s", cadena.c_str());   return -1;}
    cadena = "password";
    if (obj.CumpleRequisitosContrasena(cadena) != false){printf("COMPROBAR CONTRASEÑA TEST FAILED %s", cadena.c_str());   return -1;}
    cadena = "password1234";
    if (obj.CumpleRequisitosContrasena(cadena) != true){printf("COMPROBAR CONTRASEÑA TEST FAILED %s", cadena.c_str());   return -1;}

    system("clear");
    printf("ALL USER TESTS PASSED\n");


















    return 0;
}