#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Usuario {
public:
    std::string nombre_;
    std::string correo_;
    std::string contrasena_;

    Usuario(std::string nombre, std::string correo, std::string contrasena) {
        nombre_ = nombre;
        correo_ = correo;
        contrasena_ = contrasena;
    }

    string obtenerDetalles()
    {
        return "Nombre: " + nombre_ + "\nCorreo: " + correo_ + "\nContraseña: " + contrasena_ + "\n";
    }
};

vector<Usuario> obtenerUsuarios()
{
    vector<Usuario> usuarios;
    ifstream archivo("usuarios.txt");

    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            std::string nombre, correo, contrasena;

            getline(archivo, nombre);
            getline(archivo, correo);
            getline(archivo, contrasena);
            //archivo.ignore(); // Limpiar el buffer del salto de línea

            Usuario nuevoUsuario(nombre,correo,contrasena);
            usuarios.push_back(nuevoUsuario);
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo" << endl;
    }

    return usuarios;
}

bool iniciaSesion(vector<Usuario> &usuarios)
{
    cout << "Introduzca su nombre de usuario: ";
    std::string minombre;
    getline(cin, minombre); 
    cout << "Introduzca su contraseña: ";
    std::string micontrasena;
    getline(cin, micontrasena);
    int aux=0; 
    for (size_t i = 0; i < usuarios.size(); i++)
    {
        if(usuarios[i].nombre_==minombre && usuarios[i].contrasena_==micontrasena)
        {
            aux=1;
            cout <<"Sesión iniciada correctamente";
            return true;
        }
    }
    cout <<"Error al iniciar sesión";
    return false;
}

Usuario registrarUsuario() {
    std::string nombre, correo, contrasena;

    cout << "Introduzca su nombre de usuario: ";
    getline(cin, nombre);
    //Hay que comprobar si ya existe

    cout << "Introduzca su correo: ";
    getline(cin, correo);
    //Hay que comprobar si ya existe

    cout << "Introduzca su contrasena: ";
    getline(cin, contrasena);
    //Tiene que ser segura

    Usuario nuevoUsuario(nombre, correo, contrasena);
    return nuevoUsuario;
}

int main() {
    vector<Usuario> usuarios = obtenerUsuarios();
    
    for(int i=0;i!=3;)
    {
        cout << "¿Qué desea hacer?\n";
        cout << "1) Iniciar sesión\n";
        cout << "2) Registrarse\n";
        cout << "3) Salir\n";
        cin >> i;
        cin.ignore();

        switch (i)
        {
            case 1:
            {
                for(int i=0; i<3; i++)
                {
                    iniciaSesion(usuarios);
                    if(iniciaSesion(usuarios)==true)
                    {
                        i=4;
                    }
                }
                if(i!=4)
                {
                    cout<<"Ha realizado demasiados intentos incorrectos"<<endl;
                }
                break;
            }
            case 2:
            {
                Usuario nuevoUsuario = registrarUsuario();
                usuarios.push_back(nuevoUsuario);

                ofstream archivo("usuarios.txt", ios::app);
                if (archivo.is_open()) 
                {
                    archivo << nuevoUsuario.obtenerDetalles();
                    archivo.close();
                    cout << "Hemos registrado su usuario correctamente y los cambios se han guardado en 'usuarios.txt'." << endl;
                } else {
                    cout << "Error al abrir el archivo" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "Programa finalizado" << endl;
                break;
            }
            default:
            {
                cout << "Introduzca una opción del menú" << endl;
                break;
            }
        }
    }

    return 0;
}
