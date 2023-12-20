#include "activity.h"
#include <string>
Actividad::Actividad(std::string title, std::string description, std::string date, std::string hour, std::string clase, float price){}

//DONE
void Actividad::VerInformacionActividad(std::string nombre_fichero_actividad){
    std::string nombreActividad, ActivityVisuality;
    std::string title, description, date, hour, clase, price, tipo;
    std::string::size_type sz;
    std::ifstream file ("../../data/activitiesdata/Actividades.txt");
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                std::ifstream Actividad(nombreActividad);
                if(Actividad.is_open()){
                    std::getline(Actividad, title_);
                    std::getline(Actividad, description_);
                    std::getline(Actividad, date_);
                    std::getline(Actividad, hour_);
                    std::getline(Actividad, clase_);
                    std::getline(Actividad, price);
                    //price_= std::stof(price);
                    std::getline(Actividad, tipo);
                    SetType(ToEnum(tipo));
                    std::getline(Actividad, ActivityVisuality);
                    //int ActVisuality = std::stoi(ActivityVisuality);
                    //SetVisuality(ActVisuality);

                    system("clear");
                    printf("*****************************\n*      VISTA DETALLADA      *\n*****************************\n");
                    //std::cout<<title_<<"\n"<<description_<<"\n"<<date_<<"\n"<<hour_<<"\n"<<clase_<<"\n"<<price<<"\n"<<tipo<<"\n"<<ActivityVisuality<<"\n";

                    printf("Titulo: %s\nDescripcion: %s\nFecha: %s\nHora de comienzo: %s\nAula: %s\nPrecio: %s\nTipo de Actividad: %s\n", title_.c_str(), description_.c_str(),
                                                                                                    date_.c_str(), hour_.c_str(), clase_.c_str(), price.c_str(), tipo.c_str());


                    printf("\nPresione ENTER para volver atras\n");
                    std::cin.get();

                    Actividad.close();
                    file.close();
                    return;
                }
                else{
                    //system("clear");
                    printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                    std::cin.get();
                    return;  
                }
            }
        }
        std::cout<<"No se ha encontrado el fichero que de la actividad\nPresione ENTER para volver atras";
        file.close();
        std::cin.get();
        return;
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }
}

//DONE
bool Actividad::CrearActividad(){
    std::string NombreActividad, titulo, descripcion, fecha, hora, clase, precio, tipo, ActivityVisuality;
    system("clear");
    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (1/9): Escriba el nombre de la actividad <<recuerde el .txt al final del nombre>>"<<std::endl;
    std::getline(std::cin, NombreActividad);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (2/9): Escriba el titulo de la actividad"<<std::endl;
    std::getline(std::cin, titulo);
    SetTitle(titulo);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (3/9): Escriba la descripcion de la actividad"<<std::endl;
    std::getline(std::cin, descripcion);
    SetDescription(descripcion);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (4/9): Escriba la fecha de la actividad"<<std::endl;
    std::getline(std::cin, fecha);
    SetDate(fecha);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (5/9): Escriba la hora de la actividad"<<std::endl;
    std::getline(std::cin, hora);
    SetHour(hora);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (6/9): Escriba el aula de la actividad"<<std::endl;
    std::getline(std::cin, clase);
    SetClass(clase);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (7/9): Escriba el precio de la actividad"<<std::endl;
    std::getline(std::cin, precio);
    SetPrice(precio);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (8/9): Indique el tipo de la actividad <<seminario, taller, ponencia, congreso>>"<<std::endl;
    std::getline(std::cin, tipo);
    SetType(ToEnum(tipo));
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (9/9): Quiere que sea visible para los demas usuarios?\n Escriba 0 si no quiere que lo vea y 1 para que si lo vean"<<std::endl;
    std::getline(std::cin, ActivityVisuality);
    SetVisuality(ActivityVisuality);
    system("clear");

    std::ofstream file("../../data/activitiesdata/Actividades.txt",std::ios::app);
    if(file.is_open()){
        file<<NombreActividad;
        file.close();
        NombreActividad="../../data/activitiesdata/" + NombreActividad;
        std::ofstream Actividad(NombreActividad);
        if(Actividad.is_open()){
            Actividad<<titulo<<"\n"<<descripcion<<"\n"<<fecha<<"\n"<<hora<<"\n"<<clase<<"\n"<<precio<<"\n"<<tipo<<"\n"<<ActivityVisuality<<std::endl;
            Actividad.close();
            return true;
        }
        else{
            //system("clear");
            //printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
            //std::cin.get();
            return false;;
        }
    }
    else{
        //system("clear");
        //printf("Ha ocurrido un error al abrir el fichero de actividades\nPresione ENTER para volver atras\n");
        //std::cin.get();
        return false;
    }
    
}

//POR VER
bool Actividad::PreInscribirse(User usuario, std::string nombre_fichero_actividad){
    std::string nombreActividad;
    std::ifstream file("../../data/activitiesdata/Actividades.txt");

    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){

                VerInformacionActividad(nombreActividad);
                nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                std::ofstream Actividad(nombreActividad, std::ios::app);

                if(Actividad.is_open() && price_ == "0"){
                    Actividad<<usuario.GetUserName()<<"\n";
                    Actividad.close();
                    file.close();
                    return true;
                }
                else if(Actividad.is_open() && price_ != "0"){

                    std::string confirmacion;
                    std::cout<<"El precio de la actividad es de: "<<price_<<" euros."<<std::endl;
                    std::cout<<"Si desea inscribirse escriba <confirmar>" <<std::endl;
                    std::cin>>confirmacion;

                        if(confirmacion == "confirmar"){
                            printf("Se ha inscrito correctamente en %s.\nLa actividad se deberá pagar el proximo dia en la Universidad de Cordoba\n", nombre_fichero_actividad.c_str());
                            sleep(3);
                            Actividad<<usuario.GetUserName()<<std::endl;
                            Actividad.close();
                            file.close();
                            return true;
                        }
                        else{
                            printf("Se ha cancelado la operacion\nPresione ENTER para volver atras\n");
                            std::cin.get();
                            return false;
                        }
                }
                else{
                    system("clear");
                    printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                    std::cin.get();
                    return false;
                }
            }
        }
        system("clear");
        std::cout<<"No se ha encontrado el fichero que de la actividad\n\nPresione ENTER para volver atras";
        file.close();
        std::cin.get();
        return false;
        
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    } 
}

//DONE
void Actividad::MostrarListaInscritos(std::string nombre_fichero_actividad){
  std::string nombreActividad, precio, tipo, ActivityVisuality;
    std::ifstream file("../../data/activitiesdata/Actividades.txt");
    int count=0;

    if (file.is_open())
    {
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                std::ifstream Actividad(nombreActividad);
                if(Actividad.is_open()){
                    std::string Inscritos;
                    std::getline(Actividad, title_);
                    std::getline(Actividad, description_);
                    std::getline(Actividad, date_);
                    std::getline(Actividad, hour_);
                    std::getline(Actividad, clase_);
                    std::getline(Actividad, precio);
                    //float price= stof(precio);
                    //SetPrice(price);
                    std::getline(Actividad, tipo);
                    SetType(ToEnum(tipo));
                    std::getline(Actividad, ActivityVisuality);
                    //int ActVisuality= stoi(ActivityVisuality);
                    //SetVisuality(ActVisuality);

                    system("clear");
                    printf("*****************************\n*     LISTA DE INSCRITOS    *\n*****************************\n\n");

                    while(std::getline(Actividad, Inscritos)){
                        printf("Entra en inscrito\n");
                        std::cout<<Inscritos<<std::endl;
                        count++;
                    }

                    if (count < 1)
                    {
                        printf("\nNo existen inscritos en la actividad seleccionada\n");
                    }

                    printf("\nPresione ENTER para volver atras\n");
                    Actividad.close();
                    std::cin.get();
                    return;
                }
                else{
                system("clear");
                printf("ERROR al mostrar la lista de Incritos\n\nPresione ENTER para volver atras\n");
                std::cin.get();
                return;  
                }
            }
        }
    printf("No existe Actividad con ese nombre\n\nPresione ENTER para volver atras\n");
    std::cin.get(); 
    file.close();
    return;
    }
    else{
        system("clear");
        printf("ERROR al mostrar la lista de Incritos\n\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }  
}

//DONE
bool Actividad::ModificarActividad(std::string nombre_fichero_actividad){
    std::string nombreActividad, titulo, descripcion, fecha, hora, clase, precio, tipo, ActivityVisuality;
    std::ifstream file("../../data/activitiesdata/Actividades.txt");
    if(file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (1/8): Escriba el nuevo titulo de la actividad"<<std::endl;
                std::getline(std::cin, titulo);
                SetTitle(titulo);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (2/8): Escriba la nueva descripcion de la actividad"<<std::endl;
                std::getline(std::cin, descripcion);
                SetDescription(descripcion);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (3/8): Escriba la nueva fecha de la actividad"<<std::endl;
                std::getline(std::cin, fecha);
                SetDate(fecha);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (4/8): Escriba la nueva hora de la actividad"<<std::endl;
                std::getline(std::cin, hora);
                SetHour(hora);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (5/8): Escriba el nuevo aula de la actividad"<<std::endl;
                std::getline(std::cin, clase);
                SetClass(clase);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (6/8): Escriba el nuevo precio de la actividad"<<std::endl;
                std::getline(std::cin, precio);
                //float price = std::stof(precio);
                //SetPrice(price);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (7/8): Indique el tipo de la actividad <<seminario, taller, ponencia, congreso>>"<<std::endl;
                std::getline(std::cin, tipo);
                SetType(ToEnum(tipo));
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (8/8): Quiere que sea visible para los demas usuarios?\n Escriba 0 si no quiere que lo vea y 1 para que si lo vean"<<std::endl;
                std::getline(std::cin, ActivityVisuality);
                //int ActVisuality = std::stoi(ActivityVisuality);
                //SetVisuality(ActVisuality);
                system("clear");
                nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                std::ofstream Actividad(nombreActividad);
                    if(Actividad.is_open()){
                        Actividad<<titulo<<"\n"<<descripcion<<"\n"<<fecha<<"\n"<<hora<<"\n"<<clase<<"\n"<<precio<<std::endl;
                        Actividad.close();
                        file.close();
                        return true;
                    }
                    else{
                    system("clear");
                    printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                    std::cin.get();
                    return false;
                    }
            }
        }
        printf("No existe un fichero con ese nombre\nPresione ENTER para volver atras\n");
        std::cin.get(); 
        file.close();
        return false;
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero de actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    }
}

//POR VER
bool Actividad::EliminarPreInscripcion(User usuario, std::string nombre_fichero_actividad){
    std::string nombreActividad, data, confirmacion;
    std::ifstream file ("../../data/activitydata/Actividades.txt");
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                VerInformacionActividad((std::string)nombreActividad);
                std::cout<<"Esta seguro que quiere eliminarse de esta actividad\n Diga yes si quiere eliminarse y diga no si no quiere"<<std::endl;
                std::cin>>confirmacion;
                if(confirmacion == "yes"){
                    nombreActividad= "../../data/activitydata/" + nombreActividad;
                    std::ofstream NuevaActividad("../../data/activitydata/ActividadRemplazo");
                    std::ifstream Actividad(nombreActividad);
                        if(Actividad.is_open()){
                            while(std::getline(Actividad, data)){
                                if(data != usuario.GetUserName()){
                                    NuevaActividad<<data<<"\n";
                                    
                                }
                            }
                            file.close();
                            Actividad.close();
                            //rename("../../data/activitydata/ActividadRemplazo", nombreActividad);
                            NuevaActividad.close();
                            return true;
                        }
                        else{
                            system("clear");
                            printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                            std::cin.get();
                            return false;
                        }
                }
                else if (confirmacion == "no"){
                    system("clear");
                    printf("Se ha cancelado la operacion\nPresione ENTER para volver atras\n");
                    std::cin.get();
                    return false;
                }
            
            }
        }
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    } 
}