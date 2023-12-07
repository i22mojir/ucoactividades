#include "app.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    std::vector<std::string> opciones={"1. Iniciar Sesion", "2. Registrarse", "3. Ver Actividades sin iniciar sesion", "4. Salir"};

    int key;

    while (1)
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
            MenuRegistro();    
        break;
        
        case 3:
            MenuVerActividades(0);
        break;

        case 4:
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
}
