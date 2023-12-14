#include "activity.h"

Actividad::Actividad(std::string title, std::string description, std::string date, std::string hour, std::string clase, float price){

}

void Actividad::VerInformacionActividad(std::string nombre_fichero_actividad){
    std::string nombreActividad, price;
    std::string::size_type sz;
    std::ifstream file ("../data/activitydata/Actividades");
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                nombreActividad= "../data/activitydata/" + nombreActividad;
                std::ifstream Actividad(nombreActividad);
                if(Actividad.is_open()){
                    std::getline(Actividad, title_);
                    std::getline(Actividad, description_);
                    std::getline(Actividad, date_);
                    std::getline(Actividad, hour_);
                    std::getline(Actividad, clase_);
                    std::getline(Actividad, price);
                    price_= std::stof(price);
                    std::cout<<title_<<"\n"<<description_<<"\n"<<date_<<"\n"<<hour_<<"\n"<<clase_<<"\n"<<price_<<std::endl;
                    Actividad.close();
                }
                else{
                    system("clear");
                    printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                    std::cin.get();
                    return;  
                }
            }
        }
        file.close();
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }
}
bool Actividad::CrearActividad(){
    std::string NombreActividad, titulo, descripcion, fecha, hora, clase, precio;
    std::cout<<"Escriba el nombre de la actividad"<<std::endl;
    std::cin>>NombreActividad;
    std::cout<<"Escriba el titulo de la actividad"<<std::endl;
    std::cin>>titulo;
    SetTitle(titulo);
    std::cout<<"Escriba la descripcion de la actividad"<<std::endl;
    std::cin>>descripcion;
    SetDescription(descripcion);
    std::cout<<"Escriba la fecha de la actividad"<<std::endl;
    std::cin>>fecha;
    SetDate(fecha);
    std::cout<<"Escriba la hora de la actividad"<<std::endl;
    std::cin>>hora;
    SetHour(hora);
    std::cout<<"Escriba el aula de la actividad"<<std::endl;
    std::cin>>clase;
    SetClass(clase);
    std::cout<<"Escriba el precio de la actividad"<<std::endl;
    std::cin>>precio;
    float price = std::stof(precio);
    SetPrice(price);
    std::ofstream file("../data/activitydata/Actividades",std::ios::app);
    if(file.is_open()){
        file<<NombreActividad;
        file.close();
        NombreActividad="../data/activitydata/" + NombreActividad;
        std::ofstream Actividad(NombreActividad);
        if(Actividad.is_open()){
            Actividad<<titulo<<"\n"<<descripcion<<"\n"<<fecha<<"\n"<<hora<<"\n"<<clase<<"\n"<<precio<<std::endl;
            Actividad.close();
            return true;
        }
        else{
            system("clear");
            printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
            std::cin.get();
            return false;;
        }
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero de actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    }
    
}
bool Actividad::PreInscribirse(user usuario, std::string nombre_fichero_actividad){
    std::string nombreActividad;
    std::ifstream file ("../data/activitydata/Actividades");
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                VerInformacionActividad(nombreActividad);
                nombreActividad= "../data/activitydata/" + nombreActividad;
                std::ofstream Actividad(nombreActividad, std::ios::app);
                if(Actividad.is_open() && price_ == 0.0){
                    Actividad<<usuario.GetUserName()<<std::endl;
                    Actividad.close();
                    file.close();
                    return true;
                }
                else if(Actividad.is_open() && price_ != 0.0){
                    std::string confirmacion;
                    std::cout<<"El precio a pagar para preinscribirse es de "<<price_<<"\n quiere seguir con la preinscripción"<<std::endl;
                    std::cout<<"Escribe yes para seguir y no para cancelar la preinscipcion"<<std::endl;
                    std::cin>>confirmacion;
                        if(confirmacion == "yes"){
                            printf("La actividad se deberá pagar el proximo dia en la Universidad de Cordoba\n");
                            Actividad<<usuario.GetUserName()<<std::endl;
                            system("clear");
                            Actividad.close();
                            file.close();
                            return true;
                        }
                        else if (confirmacion == "no"){
                            system("clear");
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
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    } 
}
void Actividad::MostrarListaInscritos(std::string nombre_fichero_actividad){
  std::string nombreActividad, precio;
    std::ifstream file("../data/activitydata/Actividades");
    if (file.is_open())
    {
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                nombreActividad= "../data/activitydata/" + nombreActividad;
                std::ifstream Actividad(nombreActividad);
                if(Actividad.is_open()){
                    std::string Inscritos;
                    std::getline(Actividad, title_);
                    std::getline(Actividad, description_);
                    std::getline(Actividad, date_);
                    std::getline(Actividad, hour_);
                    std::getline(Actividad, clase_);
                    std::getline(Actividad, precio);
                    float price= stof(precio);
                    SetPrice(price);
                    while(std::getline(Actividad, Inscritos)){
                        std::cout<<Inscritos<<std::endl;
                    }
                    Actividad.close();
                }
                else{
                system("clear");
                printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                std::cin.get();
                return;  
                }
            }
        }
    file.close();
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return;
    }  
}
bool Actividad::ModificarActividad(std::string nombre_fichero_actividad){
    std::string nombreActividad, titulo, descripcion, fecha, hora, clase, precio;
    std::cout<<"Escriba el titulo de la actividad"<<std::endl;
    std::cin>>titulo;
    SetTitle(titulo);
    std::cout<<"Escriba la descripcion de la actividad"<<std::endl;
    std::cin>>descripcion;
    SetDescription(descripcion);
    std::cout<<"Escriba la fecha de la actividad"<<std::endl;
    std::cin>>fecha;
    SetDate(fecha);
    std::cout<<"Escriba la hora de la actividad"<<std::endl;
    std::cin>>hora;
    SetHour(hora);
    std::cout<<"Escriba el aula de la actividad"<<std::endl;
    std::cin>>clase;
    SetClass(clase);
    std::cout<<"Escriba el precio de la actividad"<<std::endl;
    std::cin>>precio;
    float price= stof(precio);
    SetPrice(price);
    std::ifstream file("../data/activitydata/Actividades");
    if(file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                nombreActividad= "../data/activitydata/" + nombreActividad;
                std::ofstream Actividad(NombreActividad);
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
    }
    else{
        system("clear");
        printf("Ha ocurrido un error al abrir el fichero de actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    }
}
bool Actividad::EliminarPreInscripcion(user usuario, std::string nombre_fichero_actividad){
    std::string nombreActividad, data, confirmacion;
    std::ifstream file ("../data/activitydata/Actividades");
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                VerInformacionActividad(nombreActividad);
                std::cout<<"Esta seguro que quiere eliminarse de esta actividad\n Diga yes si quiere eliminarse y diga no si no quiere"<<std::endl;
                std::cin>>confirmacion;
                if(confirmacion == "yes"){
                    nombreActividad= "../data/activitydata/" + nombreActividad;
                    std::ofstream NuevaActividad("../data/activitydata/ActividadRemplazo");
                    std::ifstream Actividad(nombreActividad);
                        if(Actividad.is_open()){
                            while(std::getline(Actividad, data)){
                                if(data != usuario.GetUserName()){
                                    NuevaActividad<<data<<std::endl;
                                    file.close();
                                    Actividad.close();
                                    rename("../data/activitydata/ActividadRemplazo", nombreActividad);
                                    NuevaActividad.close();
                                    return true;
                                }
                            }
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