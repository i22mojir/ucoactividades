#include "app.h"

void MenuInicioSesion()
{
    std::string username, password;
    User generated_user;

    system("clear");
    printf("*****************************\n*      INCIO DE SESION      *\n*****************************\n");

    printf("Usuario:");
    std::cin>>username;
    generated_user.SetUserName(username);

    printf("Contraseña:");
    std::cin>>password;
    generated_user.SetPassword(password);

    //Comprobacion de datos, sino la variable de intentos se decrementa

}

void MenuRegistro()
{

    std::string username, email, password;
    User generated_user;

    system("clear");
    printf("*****************************\n*         REGISTRO          *\n*****************************\n");

    printf("Usuario:");
    std::cin>>username;
    generated_user.SetUserName(username);

    printf("Email:");
    std::cin>>email;
    generated_user.SetEmail(email);

    printf("Contraseña:");
    std::cin>>password;
    generated_user.SetPassword(password);

    //Comprobacion de base de datos si existe

}

void MenuVerActividades()
{
    system("clear");
    printf("*****************************\n*   LISTA DE ACTIVIDADES    *\n*****************************\n");

    std::vector<FILE> vector; //Vector de archivos

    for (int i = 0; i < vector.size(); i++)
    {
        /* abrira los archivos para mostrar su nombre por pantalla */
    }

    //std::cin>> El usuario introduce cual a acual quiere acceder
    
}