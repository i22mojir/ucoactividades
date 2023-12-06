#include <iostream>
#include <vector>
#include "app.h"

int main(int argc, char const *argv[])
{
    std::vector<std::string> opciones={"Iniciar Sesion", "Registrarse", "Ver Actividades sin iniciar sesion", "Salir"};

    int key, status = 1;

    while (status == 1)
    {
        system("clear");
        printf("*****************************\n*       UCOACTIVIDADES      *\n*****************************\n");
        for (int i = 0; i < opciones.size(); i++)
        {
            printf("%s\n", opciones[i].c_str());
        }
        
        std::cin>>key;

        switch (key)
        {
        case 1:
            MenuInicioSesion();
        break;

        case 2:
    
        break;
        
        case 3:
            
        break;

        case 4:
            printf("Saliendo del programa\n");
            return 0;
        break;

        default:
            //void
        break;
        }
    }
}
