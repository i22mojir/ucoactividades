#include "app.h"

//SUB-MENUS
void MenuInicioSesion()
{
    User generated_user;

    generated_user = generated_user.IniciarSesion();

    printf("DEBUG: user info: %s\n", generated_user.GetDetails().c_str());

    if (generated_user.GetUserName() == "NA" && generated_user.GetEmail() == "NA" && generated_user.GetPassword() == "NA") //Usuario que no existe
    {
        printf("Las credenciales no son validas\n");
        return;
    }
    
    if (generated_user.GetAdmin() == 1)
    {
        MenuGeneralAdmin(generated_user);
    }else
    {
        MenuGeneral(generated_user);
    }
}

void MenuRegistro()
{
    User generated_user;

    if (generated_user.RegistrarUsuario() == true)
    {
        printf("Usuario Registrado Completamente\n");
    }else
    {
        printf("Error al Registrar al usuario\n");
    }
}

void MenuVerActividades(int user_is_registered, User generated_user)
{
    system("clear");
    printf("*****************************\n*   LISTA DE ACTIVIDADES    *\n*****************************\n");
    int selected_activity;
    std::vector<FILE> vector; //Vector de archivos

    for (int i = 0; i < vector.size(); i++)
    {
        /* abrira los archivos para mostrar su nombre por pantalla */
    }
    printf("\nSeleccione actividad:");
    std::cin>>selected_activity;
    std::cin.ignore(1000, '\n');

    //Si el nombre seleccionado coincide con una actividad se introduce en el menu

    if (user_is_registered == 0)
    {
        DetallesActividadSinRegistro(); //Menu sin posibilidad de preinscripcion
    }else if(user_is_registered == 1)
    {
        DetallesActividadConRegistro(generated_user);
    }else if(user_is_registered == 2)
    {
        DetallesActividadAdministracion(generated_user);
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

void DetallesActividadSinRegistro()
{
    char selected_option;
    while (true)
    {
        system("clear");
        printf("*****************************\n*      VISTA DETALLADA      *\n*****************************\n");
        printf("Actividad seleccionada: <nombre> como: Anonimo\n\n");

        printf("Acciones de actividad:\n1. Ver Informacion\n2. Volver a Incio de Sesion\n\n(Para habilitar la preinscripcion debe estar registrado)\n");
        std::cin>>selected_option;

        if (isdigit(selected_option) == 0) //Si no es un numero no hace nada
        {
            selected_option = 99; //Va a default        
        }

        switch (selected_option)
        {
        case '1':
            std::cin.ignore(1000, '\n');
            //Ver informacion de actividad
            break;

        case '2':
            std::cin.ignore(1000, '\n');
            return;
        break;
        
        default:
            //void
            break;
        }
    }
}

void DetallesActividadConRegistro(User generated_user)
{
    char selected_option;
    while (true)
    {
        system("clear");
        printf("*****************************\n*      VISTA DETALLADA      *\n*****************************\n");
        printf("Actividad seleccionada: <nombre> como: %s\n\n", generated_user.GetUserName().c_str());

        printf("Acciones de actividad:\n1. Ver Informacion\n2. PreInscribirse en esta Actividad\n3. Volver al Menu\n");
        std::cin>>selected_option;

        if (isdigit(selected_option) == 0) //Si no es un numero no hace nada
        {
            selected_option = 99; //Va a default        
        }

        switch (selected_option)
        {
        case '1':
            std::cin.ignore(1000, '\n');
            //Ver informacion de actividad
            break;

        case '2':
            //Funcion de preinscripcion tiene informacion del usuario
        break;

        case '3':
            return;
        break;
        
        default:
            //void
            break;
        }
    }
}

void DetallesActividadAdministracion(User generated_user)
{
    char selected_option;
    while (true)
    {
        system("clear");
        printf("*****************************\n*      VISTA DETALLADA      *\n*****************************\n");
        printf("Actividad seleccionada: <nombre> como: %s (admin)\n\n", generated_user.GetUserName().c_str());

        printf("Acciones de actividad:\n1. Ver Informacion\n2. Modificar Actividad\n3. Obtener Lista de Inscritos\n4. Volver al Menu\n");
        std::cin>>selected_option;

        if (isdigit(selected_option) == 0) //Si no es un numero no hace nada
        {
            selected_option = 99; //Va a default        
        }

        switch (selected_option)
        {
        case '1':
            std::cin.ignore(1000, '\n');
            //Ver informacion de actividad
            break;

        case '2':
            //Funcion de modificacion de actividad
        break;

        case '3':
            //Funcion de obtener lista de inscritos
        break;

        case '4':
            return;
        break;
        
        default:
            //void
            break;
        }
    }
}

void CrearActividad()
{
    //Llamada a funcion de creacion de actividad
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
                MenuVerActividades(1, generated_user); //Entra como usuario comun
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
    system("clear");
    printf("Sesion Iniciada correctamente!\nBienvenido administrador %s\n", generated_user.GetUserName().c_str());
    sleep(1);

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
            MenuVerActividades(2, generated_user); //Entra como administrador
        break;

        case '2':
            std::cin.ignore(1000, '\n');
            CrearActividad();
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