#include "user.h"
#include <iostream>
#include <fstream>
#include <vector>

/*int main()
{
    std::vector<User> usuarios = GetUsers();

    for (int i = 0; i != 3;)
    {
        std::cout << "¿Qué desea hacer?\n";
        std::cout << "1) Iniciar sesión\n";
        std::cout << "2) Registrarse\n";
        std::cout << "3) Salir\n";
        std::cin >> i;

        if (i == 1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (IniciarSesion()==1 || IniciarSesion()==2)
                {
                    std::cout << "Usuario y contraseña correctos\n";
                    j=4;
                    i=3;
                }
                std::cout << "Error al iniciar sesión\n";
            }
            if (i != 3)
            {
                std::cout << "Ha realizado demasiados intentos incorrectos, fin del programa" << std::endl;
                return 0;
            }
        }
        else if (i == 2)
        {
        	boll a=RegistrarUsuario();
            	std::cout<<" a "<<std::endl;
        }
        else if (i == 3)
        {
            std::cout << "Programa finalizado" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Error, introduzca una opción del menú" << std::endl;
        }
    }

    return 0;
}*/

std::string User::GetDetails()
{
    return user_name_ + "\n" + email_ + "\n" + password_ + "\n" + std::to_string(intereses_) +
           "\n" + (admin_status_ ? "1" : "0") + "\n";
}

std::vector<User> User::GetUsers()
{
    std::ifstream fich("../../data/userdata/users.txt");
    std::vector<User> aux;

    if (fich.is_open())
    {
        std::string user_name, email, password, intereses, admin_status;
        int admin_status_num;
        Intereses interes_enum;

        while (getline(fich, user_name))
        {
            getline(fich, email);
            getline(fich, password);
            getline(fich, intereses);
            getline(fich, admin_status);

            if (intereses == "0") {
                interes_enum = Tecnologia;
            } else if (intereses == "1") {
                interes_enum = Medicina;
            } else if (intereses == "2") {
                interes_enum = Ciencia;
            } else if (intereses == "3") {
                interes_enum = Derecho;
            } else if (intereses == "4") {
                interes_enum = Ninguno;
            } else {
                interes_enum = Ninguno;
            }

            if (admin_status == "0")
            {
                admin_status_num = 0;
            }else
            {
                admin_status_num = 1;
            }

            User New(user_name, email, password, interes_enum, admin_status_num);
            aux.push_back(New);
        }
        fich.close();
    }
    else
    {
        std::cout << "Error, no se pudo abrir el contenido del archivo" << std::endl;
    }

    return aux;
}

bool User::ComprobarNombre(std::vector<User> &usuarios, std::string &user_name)
{
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        if (it->GetUserName() == user_name)
        {
            return false;
        }
    }
    return true;
}

bool User::ComprobarEmail(std::vector<User> &usuarios, std::string &email)
{
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        if (it->GetEmail() == email)
        {
            return false;
        }
    }
    return true;
}

bool User::CumpleRequisitosContrasena(std::string &password)
{
    if (password.length() < 8)
    {
        system("clear");
        printf("*****************************\n*         REGISTRO          *\n*****************************\n");

        std::cout << "\nError de contraseña, debe tener al menos 8 caracteres.\n";
        return false;
    }

    bool tieneAlMenosUnNumero = false;
    for (auto it = password.begin(); it != password.end(); ++it)
    {
        if (std::isdigit(*it))
        {
            tieneAlMenosUnNumero = true;
        }
    }

    if (tieneAlMenosUnNumero==false)
    {
        system("clear");
        printf("*****************************\n*         REGISTRO          *\n*****************************\n");

        std::cout << "\nError de contraseña, debe contener al menos un número.\n";
        return false;
    }

    return true;
}

User User::IniciarSesion()
{
    User no_encontrado("NA","NA","NA");
    std::vector<User> usuarios = GetUsers();

    //printf("DEBUG: Tamaño del vector de user: %i\n", usuarios.size());

    std::string myname, mypassword;

    system("clear");
    printf("*****************************\n*      INCIO DE SESION      *\n*****************************\n");
    printf("Usuario: ");
    std::cin>>myname;
    std::cin.ignore(1000, '\n');

    printf("Contraseña: ");
    std::cin>>mypassword;
    std::cin.ignore(1000, '\n');

    for (int i = 0; i < usuarios.size(); i++)
    {
        //printf("DEBUG: se compara: <%s> - <%s> / <%s> - <%s>\n", usuarios[i].GetUserName().c_str(), myname.c_str(), usuarios[i].GetPassword().c_str(), mypassword.c_str());

        if (usuarios[i].GetUserName() == myname && usuarios[i].GetPassword() == mypassword)
        {
            return usuarios[i]; //Devuelve un User
        }
    }

    printf("\nLas credenciales son incorrectas (Recordatorio: Antes de iniciar sesion se debe estar registrado)\n");
    printf("\nPulsa ENTER para volver atras\n");
    std::cin.get();
    return no_encontrado;
}

bool User::RegistrarUsuario()
{
    std::vector<User> usuarios = GetUsers();

    std::string user_name, email, password;
    Intereses interes;
    bool admin_status = 0;

    system("clear");
    printf("*****************************\n*         REGISTRO          *\n*****************************\n");

    printf("Usuario (usuario UCO): ");
    std::cin>>user_name;
    std::cin.ignore(1000, '\n');

    printf("Email (@uco.es): ");
    std::cin>>email;
    std::cin.ignore(1000, '\n');

    printf("Contraseña: ");
    std::cin>>password;
    std::cin.ignore(1000, '\n');

    while (CumpleRequisitosContrasena(password) == false)
    {
        printf("\nIntroduzca una contraseña segura: \n");
        std::cin>>password;
        std::cin.ignore(1000, '\n');
    }
    

    if (ComprobarNombre(usuarios, user_name) == false || ComprobarEmail(usuarios, email) == false)
    {
        system("clear");
        printf("*****************************\n*         REGISTRO          *\n*****************************\n");
        printf("\nError de registro, El nombre de usuario o correo ya existen\n");
        sleep(3);
        return false;
    }
    
    system("clear");
    printf("*****************************\n*         REGISTRO          *\n*****************************\n");

    std::cout << "Escoja su interes:\n";
    std::cout << "1. Tecnologia\n";
    std::cout << "2. Medicina\n";
    std::cout << "3. Ciencia\n";
    std::cout << "4. Derecho\n";
    std::cout << "5. Ninguno\n";
    int interesesValue;
    std::cin >> interesesValue;
    std::cin.ignore(1000, '\n');

    switch (interesesValue)
    {
    case 1:
        interes = Tecnologia;
        break;
    case 2:
        interes = Medicina;
        break;
    case 3:
        interes = Ciencia;
        break;
    case 4:
        interes = Derecho;
        break;

    case 5:
        interes = Ninguno;
        break;

    default:
        interes = Ninguno;
        break;
    }

    User New(user_name, email, password, interes, admin_status);

    std::ofstream archivo("../../data/userdata/users.txt", std::ios::app);
    if (archivo.is_open())
    {
        archivo << New.GetDetails();
        system("clear");
        printf("*****************************\n*         REGISTRO          *\n*****************************\n");
        std::cout << "\nUsuario Registrado Correctamente\n" << std::endl;
        printf("\nPulsa ENTER para volver al menu\n");
        std::cin.get();
        archivo.close();
        return true;
    }
    else
    {
        std::cout << "No se puedo Registrar el usuario\n" << std::endl;
        printf("\nPulsa ENTER para volver atras\n");
        std::cin.get();
        return false;
    }

    return false;
}
