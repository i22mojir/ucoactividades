#include "app.h"

//SUB-MENUS
void MenuInicioSesion()
{
    std::string username, password;
    User generated_user;

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
    MenuGeneralAdmin(generated_user);
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

    std::cin.ignore(1000, '\n');

    printf("Email:");
    std::cin>>email;
    generated_user.SetEmail(email);

    std::cin.ignore(1000, '\n');

    printf("Contraseña:");
    std::cin>>password;
    generated_user.SetPassword(password);

    std::cin.ignore(1000, '\n');

    //Comprobacion de base de datos si existe y comprobacion de contraseña segura

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
    Mail generated_mail;
    std::vector<std::string> mail_vector;
    char selected_option;

    std::string path="../data/maildata"; //Especificacion de directorio
    system("clear");
    for (const auto it: fs::directory_iterator(path)) //Lectura de archivos del directorio al vector (nombre archivo) (utiliza <filesystem>)
    {
        if (fs::is_regular_file(it))
        {
            mail_vector.push_back(it.path().filename().string());
        }
    }

    printf("*****************************\n*          CORREO           *\n*****************************\n");
    for (int i = 0; i < mail_vector.size(); i++) //Muestra el vector
    {
        printf("%i. %s\n", (i+1), mail_vector[i].c_str());
    }
    
    printf("\nIndique numero del correo para verlo:");
    std::cin>>selected_option;

    if (isdigit(selected_option) == 0) //Si no es un numero no hace nada
    {
        return;        
    }

    if (selected_option < 1 || selected_option > mail_vector.size()) //De esta forma se asegura de que solo se abren ficheros existentes
    {
        system("clear");
        printf("(ERROR) Se ha especificado un correo inexistente\n\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }

    std::string file_path = "../data/maildata/" + mail_vector[(selected_option-1)];
    std::cout<<"DEBUG: "<<file_path<<"\n";
    std::ifstream mail_file(file_path); //Abrir archivo modo lectura

    if (mail_file.is_open())
    {
        system("clear");
        std::string temp_title, temp_to_person, temp_desc;
    
        std::getline(mail_file, temp_title);
        std::getline(mail_file, temp_to_person);
        std::getline(mail_file, temp_desc);

        generated_mail.SetTitle(temp_title);
        generated_mail.SetToPerson(temp_to_person);
        generated_mail.SetDesc(temp_desc);

        printf("Titulo: %s\nPara: %s\nDescripcion: %s\n\n", generated_mail.GetTitle().c_str(), generated_mail.GetToPerson().c_str(), generated_mail.GetDesc().c_str());

        printf("Presiona ENTER para volver al menu\n");
        std::cin.get();

        mail_file.close();
    }else
    {
        system("clear");
        printf("Ha ocurrido un error al abrir el correo\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }
}

void EnviarCorreo()
{
    std::string temp_title, temp_to_person, temp_desc;

    Mail new_mail;

    system("clear");

    printf("Paso 1/3. Indique el usuario o grupo al cual se le enviara el correo:\n");
    std::cin>>temp_to_person;
    std::cin.ignore(1000, '\n');
    new_mail.SetToPerson(temp_to_person);

    system("clear");

    printf("Paso 2/3. Indique el Asunto del correo:\n");
    std::getline(std::cin, temp_title);
    new_mail.SetTitle(temp_title);

    system("clear");

    printf("Paso 3/3. Indique la descripcion del correo:\n");
    std::getline(std::cin, temp_desc);
    new_mail.SetDesc(temp_desc);

    system("clear");

    std::string file_path = "../data/maildata/" + temp_to_person + temp_title;

    std::ofstream new_mail_file(file_path);

    if (new_mail_file.is_open())
    {
        new_mail_file << new_mail.GetTitle() << "\n";
        new_mail_file << new_mail.GetToPerson() << "\n";
        new_mail_file << new_mail.GetDesc() << "\n";

        printf("Se envio el correo correctamente\n\n");

        printf("Presione ENTER para volver al menu principal\n");

        new_mail_file.close();
    }else
    {
        printf("Hubo un problema enviando el correo\n\n");
        printf("Presione ENTER para volver al menu principal\n");
    }
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