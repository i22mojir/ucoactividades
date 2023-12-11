#include "user.h"
#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<User> usuarios;
    usuarios = GetUsers();

    for (int i = 0; i != 3;)
    {
        std::cout << "¿Qué desea hacer?\n";
        std::cout << "1) Iniciar sesión\n";
        std::cout << "2) Registrarse\n";
        std::cout << "3) Salir\n";
        std::cin >> i;

        if (i == 1)
        {
            User aux;
            for (int j = 0; j < 3; j++)
            {
                if (IniciarSesion(usuarios, aux))
                {
                    std::cout << "Usuario y contraseña correctos\n";
                    usuarios.push_back(aux);
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
            User nuevoUsuario = RegistrarUsuario(usuarios);
            usuarios.push_back(nuevoUsuario);

            std::ofstream archivo("usuarios.txt", std::ios::app);
            if (archivo.is_open())
            {
                archivo << nuevoUsuario.GetDetails();
                archivo.close();
                std::cout << "Hemos registrado su usuario correctamente y los cambios se han guardado en 'usuarios.txt'." << std::endl;
            }
            else
            {
                std::cout << "Error, no se pudo abrir el contenido del archivo" << std::endl;
            }
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
}


std::string User::GetDetails() const
{
    return "Nombre de usuario: " + user_name_ + "\nCorreo: " + email_ + "\nContraseña: " + password_ + "\nIntereses: " + std::to_string(static_cast<int>(intereses_)) +
           "\nAdmin: " + (admin_status_ ? "Sí" : "No") + "\n";
}

std::vector<User> GetUsers()
{
    std::ifstream fich("usuarios.txt");
    std::vector<User> aux;

    if (fich.is_open())
    {
        std::string user_name, email, password, intereses, admin_status;

        while (getline(fich, user_name))
        {
            getline(fich, email);
            getline(fich, password);
            getline(fich, intereses);
            getline(fich, admin_status);

            User New(user_name, email, password, static_cast<Intereses>(std::stoi(intereses)), std::stoi(admin_status));
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

bool IniciarSesion(std::vector<User> &usuarios, User &aux)
{
    std::string myname, mypassword;
    std::cout << "Introduzca su nombre de usuario:\n";
    std::cin.ignore();
    getline(std::cin, myname);
    std::cout << "Introduzca su contraseña:\n";
    getline(std::cin, mypassword);

    for (int i = 0; i < usuarios.size(); i++)
    {
        if (usuarios[i].GetUserName() == myname && usuarios[i].GetPassword() == mypassword)
        {
            aux = usuarios[i];
            return true;
        }
    }
    return false;
}

User RegistrarUsuario(std::vector<User> &usuarios)
{
    std::string user_name, email, password;
    Intereses intereses;
    bool admin_status = 0;

    std::cout << "Introduzca su nombre de usuario: ";
    std::cin>>user_name;

    while(ComprobarNombre(usuarios, user_name)==false)
    {
        std::cout << "Error, introduzca un nombre de usuario que no esté repetido: ";
        std::cin>>user_name;
    }

    std::cout << "Introduzca su correo:\n";
    std::cin>>email;

    while(ComprobarEmail(usuarios, email)==false)
    {
        std::cout << "Error, introduzca un correo que no esté repetido:\n";
        std::cin>>email;
    }

    std::cout << "Introduzca su contrasena: ";
    std::cin>>password;

    while(CumpleRequisitosContrasena(password)==false)
    {
        std::cout << "Introduzca de nuevo una contraseña:\n";
        std::cin>>password;
    }

    std::cout << "Introduzca sus intereses siendo:\n";
    std::cout << "0)Tecnologia\n";
    std::cout << "1)Medicina\n";
    std::cout << "2)Ciencia\n";
    std::cout << "3)Derecho\n";
    std::cout << "4)Ninguno\n";
    int interesesValue;
    std::cin >> interesesValue;
    intereses = static_cast<Intereses>(interesesValue);

    User New(user_name, email, password, intereses, admin_status);
    return New;
}

bool ComprobarNombre(std::vector<User> &usuarios, std::string &user_name)
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

bool ComprobarEmail(std::vector<User> &usuarios, std::string &email)
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


bool CumpleRequisitosContrasena(std::string &password)
{
    if (password.length() < 8)
    {
        std::cout << "Error, la contraseña debe tener al menos 8 caracteres.\n";
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
        std::cout << "Error, la contraseña debe contener al menos un número.\n";
        return false;
    }

    return true;
}