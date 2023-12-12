#include "app.h"

//SUB-MENUS
void MenuInicioSesion()
{
    std::string username, password;
    User generated_user();

        system("clear");
        printf("*****************************\n*      INCIO DE SESION      *\n*****************************\n");

        printf("Usuario:");
        std::cin>>username;
        generated_user.SetUserName(username);

        std::cin.ignore(1000, '\n'); //Limpia los 1000 caracteres depues del espacio del buffer

        printf("Contraseña:");
        std::cin>>password;
        generated_user.SetPassword(password);

        std::cin.ignore(1000, '\n'); //Limpia los 1000 caracteres depues del espacio del buffer

    //Comprobacion de datos, sino la variable de intentos se decrementa
    MenuGeneral(generated_user);
}

void MenuRegistro()
{

    std::string username, email, password;
    User generated_user;
    std::vector<User> user_vector;

    system("clear");
    printf("*****************************\n*         REGISTRO          *\n*****************************\n");

    printf("Usuario:");
    std::cin>>username;
    generated_user.SetUserName(username);

    std::cin.ignore(1000, '\n');

    printf("Email:");
    std::cin>>email;
    generated_user.SetEmail(email);

    std::cin.ignore(1000, '\n');

    printf("Contraseña:");
    std::cin>>password;
    generated_user.SetPassword(password);

    std::cin.ignore(1000, '\n');
}

void MenuVerActividades(int user_is_registered)
{
    system("clear");
    printf("*****************************\n*   LISTA DE ACTIVIDADES    *\n*****************************\n");
    char selected_activity;
    std::vector<FILE> vector; //Vector de archivos

    for (int i = 0; i < vector.size(); i++)
    {
        /* abrira los archivos para mostrar su nombre por pantalla */
    }
    printf("\nSeleccione actividad:");
    std::cin>>selected_activity;

    if (isdigit(selected_activity) == 0) //Si no es un numero no hace nada
    {
        return;        
    }

    //Si el nombre seleccionado coincide con una actividad se introduce en el menu

    if (user_is_registered == 0)
    {
        //Ver detalle sin inscripcion
    }else if(user_is_registered == 1)
    {
        //Ver detalle con inscripcion
    }else if(user_is_registered == 2)
    {
        //Ver detalle como administrador
    }
}

void VerInformacionUsuario(User generated_user)
{
    system("clear");
    printf("*****************************\n*  INFORMACION DE USUARIO   *\n*****************************\n");
    printf("Usuario: %s\n", generated_user.GetUserName().c_str());
    printf("Email: %s\n", generated_user.GetEmail().c_str());
    printf("/Para cambiar la contraseña pongase en contacto con un administrador/\n");

    printf("\n(Pulsa ENTER para volver al atras)\n");
}

void VerListaCorreos(User generated_user)
{
    Mail new_mail;
    new_mail.ViewMail(generated_user);
}

void EnviarCorreo()
{
    Mail new_mail;
    new_mail.SendMail();
}

//MENU GENERAL - RECIBE COMO PARAMETRO EL USUARIO Y SUS DATOS
void MenuGeneral(User generated_user)
{
    system("clear");
    printf("Sesion Iniciada correctamente!\nBienvenido %s\n", generated_user.GetUserName().c_str());
    sleep(1);

    //Si el usuario es admin se mostrara el menu de admin, sino se mostrara el estandar
    if (generated_user.GetAdmin() == 1)
    {
        MenuGeneralAdmin(generated_user);
    }else
    {
        char selected_option;
        while (1)
        {
            system("clear");
            printf("*****************************\n*      UCO ACTIVIDADES      *\n*****************************\n");
            printf("1. Ver Actividades\n2. Ver Correo\n3. Ver Mi Usuario\n4. Cerrar Sesion\n");        

            std::cin>>selected_option;
            if(isdigit(selected_option) == 0) //Si no es un numero no hace nada
            {
                selected_option = 99; //Va a default        
            }

            switch (selected_option)
            {
            case '1':
                std::cin.ignore(1000, '\n');
                MenuVerActividades(1);
            break;

            case '2':
                std::cin.ignore(1000, '\n');
                VerListaCorreos(generated_user);
            break;

            case '3':
                std::cin.ignore(1000, '\n');
                VerInformacionUsuario(generated_user);
            break;

            case '4':
                std::cin.ignore(1000, '\n');
                system("clear");
                printf("Cerrando Sesión ...\n");
                sleep(1);
                printf("Sesion Cerrada con Exito\n");
                sleep(1);
                return;
            break;
            
            default:
                break;
            }

            std::cin.ignore(1000, '\n');
        }
    }
}

void MenuGeneralAdmin(User generated_user)
{
    char selected_option;
    while (1)
    {
        system("clear");
        printf("*****************************\n*      UCO ACTIVIDADES      *\n*****************************\n");
        printf("1. Ver Actividades\n2. Crear Actividad\n3. Ver Correo\n4. Enviar Correo\n5. Ver Mi Usuario\n6. Cerrar Sesion\n");        

        std::cin>>selected_option;
        if (isdigit(selected_option) == 0) //Si no es un numero no hace nada
        {
            selected_option = 99; //Va a default        
        }

        switch (selected_option)
        {
        case '1':
            std::cin.ignore(1000, '\n');
            MenuVerActividades(2);
        break;

        case '2':
            std::cin.ignore(1000, '\n');
            
        break;

        case '3':
            std::cin.ignore(1000, '\n');
            VerListaCorreos(generated_user);
        break;

        case '4':
            std::cin.ignore(1000, '\n');
            EnviarCorreo();
        break;

        case '5':
            std::cin.ignore(1000, '\n');
            VerInformacionUsuario(generated_user);
        break;

        case '6':
            system("clear");
            printf("Cerrando Sesión ...\n");
            sleep(1);
            printf("Sesion Cerrada con Exito\n");
            sleep(1);
            return;
        break;
        
        default:
            break;
        }

        std::cin.ignore(1000, '\n');
    }
}