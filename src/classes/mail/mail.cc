#include "mail.h"

void Mail::ViewMail(User generated_user)
{
    Mail generated_mail;
    std::vector<std::string> mail_vector;
    int selected_option;
    std::string temp_interes; //Conversion de interes (int) a string
    std::string path="../../data/maildata"; //Especificacion de directorio

    system("clear");
    for (const auto it: fs::directory_iterator(path)) //Lectura de archivos del directorio al vector (nombre archivo) (utiliza <filesystem>)
    {
        if (fs::is_regular_file(it))
        {
            std::cout<<"DEBUG it:"<<it.path().filename().string()<<"\n";

            switch (generated_user.GetIntereses())
            {
            case 0:
                temp_interes = "Tecnologia";
                break;

            case 1:
                temp_interes = "Medicina";
                break;

            case 2:
                temp_interes = "Ciencia";
                break;

            case 3:
                temp_interes = "Derecho";
                break;
            
            default:
                temp_interes = "NA";
                break;
            }

            size_t pos1 = it.path().filename().string().find(generated_user.GetEmail());
            size_t pos2 = it.path().filename().string().find(temp_interes); //AÑADIR TAMB INTERESES

            printf("DEBUG: En comparacion de intereses: <%s> - <%s>\n", temp_interes.c_str(), it.path().filename().string().c_str());

            if (pos1 != std::string::npos || pos2 != std::string::npos) //Se encuentra la subcadena en la cadena
            {
                //std::cout<<"Contiene la subcadena\n"; DEBUG COUT
                mail_vector.push_back(it.path().filename().string());
            }
        }
    }

    printf("*****************************\n*          CORREO           *\n*****************************\n");
    for (int i = 0; i < mail_vector.size(); i++) //Muestra el vector
    {
        printf("%i. %s\n", (i+1), mail_vector[i].c_str());
    }

    if (mail_vector.size() < 1)
    {
        printf("No hay nuevos correos\n");
        printf("\nPresiona ENTER para volver\n");
        return;
    }
    
    printf("\nIndique numero del correo para verlo:");
    std::cin>>selected_option;

    if (selected_option < 1 || selected_option > mail_vector.size()) //De esta forma se asegura de que solo se abren ficheros existentes
    {
        system("clear");
        printf("(ERROR) Se ha especificado un correo inexistente\n\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }

    std::string file_path = "../../data/maildata/" + mail_vector[(selected_option-1)];
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

void Mail::SendMail()
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

    std::string file_path = "../../data/maildata/" + temp_title + "-" + temp_to_person; //El nombre del archivo es a quien va dirigido + titulo

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
