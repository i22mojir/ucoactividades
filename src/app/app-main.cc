#include "app.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    std::vector<std::string> opciones={"1. Iniciar Sesion", "2. Registrarse", "3. Ver Actividades sin iniciar sesion", "4. Salir"};

    char key;

    while (1)
    {
        system("clear");
        printf("*****************************\n*       UCOACTIVIDADES      *\n*****************************\n");
        for (int i = 0; i < opciones.size(); i++)
        {
            printf("%s\n", opciones[i].c_str());
        }
        
        std::cin>>key;

        if (isdigit(key) == 0) //Si no es un numero no hace nada
        {
            key = 99; //Va a default        
        }
        
        switch (key)
        {
        case '1':
            std::cin.ignore(1000, '\n');
            MenuInicioSesion();
        break;

        case '2':
            std::cin.ignore(1000, '\n');
            MenuRegistro();    
        break;
        
        case '3':
            std::cin.ignore(1000, '\n');
            MenuVerActividades(0);
        break;

        case '4':
            system("clear");
            printf("Saliendo del programa □□□\n");
            sleep(1);
            system("clear");
            printf("Saliendo del programa ■□□\n");
            sleep(1);
            system("clear");
            printf("Saliendo del programa ■■□\n");
            sleep(1);
            system("clear");
            printf("Saliendo del programa ■■■\n");
            system("clear");
            return 0;
        break;

        default:
            //void
        break;
        }
    }

    std::cin.ignore(1000, '\n');
}
