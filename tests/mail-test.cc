#include "../src/classes/mail/mail.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Mail obj;
    
    
    if(obj.GetTitle() != "empty"){printf("CONSTRUCTOR FAILED"); return -1;}
    if(obj.GetToPerson() != "empty"){printf("CONSTRUCTOR FAILED"); return -1;}
    if(obj.GetDesc() != "empty"){printf("CONSTRUCTOR FAILED"); return -1;}

    obj.SetTitle("Titulo de Prueba");
    obj.SetToPerson("correo@uco.es");
    obj.SetDesc("descripcion de prueba");

    if(obj.GetTitle() != "Titulo de Prueba"){printf("SET_FUCTION FAILED"); return -1;}
    if(obj.GetToPerson() != "correo@uco.es"){printf("SET_FUCTION FAILED"); return -1;}
    if(obj.GetDesc() != "descripcion de prueba"){printf("SET_FUCTION FAILED"); return -1;}

    printf("ALL TESTS PASSED");

    return 0;
}
