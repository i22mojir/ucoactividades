#include "activity.h"
Actividad::Actividad(std::string title, std::string description, std::string date, std::string hour, std::string clase, std::string price){

}
//DONE
void Actividad::VerInformacionActividad(std::string nombre_fichero_actividad, int number){
   std::string nombreActividad, ActivityVisuality;
    std::string price, tipo;
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
                    std::getline(Actividad, speaker_);
                    std::getline(Actividad, price);
                    std::getline(Actividad, tipo);
                    SetType(ToEnum(tipo));
                    std::getline(Actividad, ActivityVisuality);
                    SetVisuality(ActivityVisuality);

                    system("clear");
                    printf("*****************************\n*      VISTA DETALLADA      *\n*****************************\n");
                    //std::cout<<title_<<"\n"<<description_<<"\n"<<date_<<"\n"<<hour_<<"\n"<<clase_<<"\n"<<price<<"\n"<<tipo<<"\n"<<ActivityVisuality<<"\n";

                    printf("Titulo: %s\nDescripcion: %s\nFecha: %s\nHora de comienzo: %s\nAula: %s\nOrador: %s\nPrecio: %s\nTipo de Actividad: %s\n", title_.c_str(), description_.c_str(),
                                                                                                    date_.c_str(), hour_.c_str(), clase_.c_str(),speaker_.c_str(), price.c_str(), tipo.c_str());

                    if (number == 0)
                    {
                        printf("\nPresione ENTER para volver atras\n");
                        std::cin.get();
                    }else if(number == 1)
                    {
                        printf("\nPresione ENTER continuar la Inscripcion\n");
                        std::cin.get();
                    }else if(number == 2)
                    {
                        printf("\nPresione ENTER para continuar la eliminacion de la Inscripcion\n");
                        std::cin.get();
                    }
                    Actividad.close();
                    file.close();
                    return;
                }
                else{
                    system("clear");
                    printf("Ha ocurrido un error al visualizar la informacion\nPresione ENTER para volver atras\n");
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
    std::string NombreActividad, titulo, descripcion, fecha, hora, clase, speaker, precio, tipo, ActivityVisuality;
    char tipo_num, ActivityVis_num;
    system("clear");
    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (1/10): Escriba el nombre de la actividad"<<std::endl;
    std::getline(std::cin, NombreActividad);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (2/10): Escriba el titulo de la actividad"<<std::endl;
    std::getline(std::cin, titulo);
    SetTitle(titulo);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (3/10): Escriba la descripcion de la actividad"<<std::endl;
    std::getline(std::cin, descripcion);
    SetDescription(descripcion);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (4/10): Escriba la fecha de la actividad"<<std::endl;
    std::getline(std::cin, fecha);
    SetDate(fecha);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (5/10): Escriba la hora de la actividad"<<std::endl;
    std::getline(std::cin, hora);
    SetHour(hora);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (6/10): Escriba el aula de la actividad"<<std::endl;
    std::getline(std::cin, clase);
    SetClass(clase);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (7/10): Escriba el nombre del Orador de la actividad"<<std::endl;
    std::getline(std::cin, speaker);
    SetSpeaker(speaker);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (8/10): Escriba el precio de la actividad"<<std::endl;
    std::getline(std::cin, precio);
    SetPrice(precio);
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (9/10): Indique (numero) el tipo de la actividad {1.seminario, 2.taller, 3.ponencia, 4.congreso}"<<std::endl;
    std::cin>>tipo_num;
    std::cin.ignore(1000, '\n');
    switch (tipo_num)
    {
    case '1':
        tipo = "seminario";
    break;
    case '2':
        tipo = "taller";
    break;
    case '3':
        tipo = "ponencia";
    break;
    case '4':
        tipo = "congreso";
    break;
    default:
        tipo = "seminario";
        break;
    }
    SetType(ToEnum(tipo));
    system("clear");

    printf("*****************************\n*   CREACION DE ACTIVIDAD   *\n*****************************\n");
    std::cout<<"Paso (10/10): Quiere que sea visible para los demas usuarios?\nIndique (numero): 0 para no visible y 1 para visible"<<std::endl;
    std::cin>>ActivityVis_num;
    std::cin.ignore(1000, '\n');
    switch (ActivityVis_num)
    {
    case '0':
        ActivityVisuality = "0";
    break;
    case '1':
        ActivityVisuality = "1";
    break;
        
    default:
        ActivityVisuality = "1";
        break;
    }
    SetVisuality(ActivityVisuality);
    system("clear");

    std::ofstream file("../../data/activitiesdata/Actividades.txt",std::ios::app);
    if(file.is_open()){
        file<<NombreActividad;
        file.close();
        NombreActividad="../../data/activitiesdata/" + NombreActividad;
        std::ofstream Actividad(NombreActividad);
        if(Actividad.is_open()){
            Actividad<<titulo<<"\n"<<descripcion<<"\n"<<fecha<<"\n"<<hora<<"\n"<<clase<<"\n"<<speaker<<"\n"<<precio<<"\n"<<tipo<<"\n"<<ActivityVisuality<<std::endl;
            Actividad.close();
            return true;
        }
        else{
            //system("clear");
            printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
            std::cin.get();
            return false;;
        }
    }
    else{
        //system("clear");
        printf("Ha ocurrido un error al abrir el fichero de actividades\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    }
    
}
//DONE
bool Actividad::PreInscribirse(User usuario, std::string nombre_fichero_actividad){
    std::string nombreActividad;
    std::ifstream file("../../data/activitiesdata/Actividades.txt");
    if(EstaPreInscrito(usuario, nombre_fichero_actividad) == true){
        system("clear");
        printf("Ya estas preinscrito en esta actividad.\n\nPresione ENTER para volver atras");
        std::cin.get();
        return false;
    }
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){

                VerInformacionActividad(nombreActividad, 1);
                nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                std::ofstream Actividad(nombreActividad, std::ios::app);

                if(Actividad.is_open() && price_ == "0" || Actividad.is_open() && price_ == "0.0"){
                    Actividad<<usuario.GetUserName()<<"\n";
                    Actividad.close();
                    file.close();
                    return true;
                }
                else if(Actividad.is_open() && price_ != "0" || Actividad.is_open() && price_ != "0.0"){

                    std::string confirmacion;
                    std::cout<<"IMPORTANTE: El precio de la actividad es de: "<<price_<<" euros."<<std::endl;
                    std::cout<<"Si desea inscribirse escriba CONFIRMAR" <<std::endl;
                    std::cin>>confirmacion;

                        if(confirmacion == "confirmar" || confirmacion == "CONFIRMAR"){
                            system("clear");
                            printf("Se ha inscrito correctamente en %s.\nIMPORTANTE: La actividad se deberá pagar el proximo dia en la Universidad de Cordoba\n", nombre_fichero_actividad.c_str());
                            printf("\n(Se le reedigira automaticamente al menu)\n");
                            sleep(5);
                            Actividad<<usuario.GetUserName()<<std::endl;
                            Actividad.close();
                            file.close();
                            return true;
                        }
                        else{
                            system("clear");
                            printf("Se ha cancelado la operacion\n\nPresione ENTER para volver atras\n");
                            std::cin.ignore(1000, '\n');
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
        std::cout<<"No se ha encontrado el fichero que de la actividad\n\nPresione ENTER para volver atras\n";
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
                    std::getline(Actividad, speaker_);
                    std::getline(Actividad, precio);
                    SetPrice(precio);
                    std::getline(Actividad, tipo);
                    SetType(ToEnum(tipo));
                    std::getline(Actividad, ActivityVisuality);
                    SetVisuality(ActivityVisuality);

                    system("clear");
                    printf("*****************************\n*     LISTA DE INSCRITOS    *\n*****************************\n\n");

                    while(std::getline(Actividad, Inscritos)){
                        //printf("Entra en inscrito\n");
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
//DONDE
bool Actividad::ModificarActividad(std::string nombre_fichero_actividad){
    std::string nombreActividad, titulo, descripcion, fecha, hora, clase, speaker, precio, tipo, ActivityVisuality;
    char tipo_num, ActivityVis_num;
    std::ifstream file("../../data/activitiesdata/Actividades.txt");
    if(file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (1/9): Escriba el nuevo titulo de la actividad"<<std::endl;
                std::getline(std::cin, titulo);
                SetTitle(titulo);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (2/9): Escriba la nueva descripcion de la actividad"<<std::endl;
                std::getline(std::cin, descripcion);
                SetDescription(descripcion);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (3/9): Escriba la nueva fecha de la actividad"<<std::endl;
                std::getline(std::cin, fecha);
                SetDate(fecha);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (4/9): Escriba la nueva hora de la actividad"<<std::endl;
                std::getline(std::cin, hora);
                SetHour(hora);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (5/9): Escriba el nuevo aula de la actividad"<<std::endl;
                std::getline(std::cin, clase);
                SetClass(clase);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (6/9): Escriba la nueva persona que dara la actividad"<<std::endl;
                std::getline(std::cin, speaker);
                SetSpeaker(speaker);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (7/9): Escriba el nuevo precio de la actividad"<<std::endl;
                std::getline(std::cin, precio);
                SetPrice(precio);
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (8/9): Indique (numero) el tipo de la actividad {1.seminario, 2.taller, 3.ponencia, 4.congreso}"<<std::endl;
                std::cin>>tipo_num;
                std::cin.ignore(1000, '\n');
                switch (tipo_num)
                {
                case '1':
                    tipo = "seminario";
                break;
                case '2':
                    tipo = "taller";
                break;
                case '3':
                    tipo = "ponencia";
                break;
                case '4':
                    tipo = "congreso";
                break;
                default:
                    tipo = "seminario";
                    break;
                }
                SetType(ToEnum(tipo));
                system("clear");

                printf("*****************************\n* MODIFICACION DE ACTIVIDAD *\n*****************************\n");
                printf("(Modificando actividad %s)\n", nombre_fichero_actividad.c_str());
                std::cout<<"Paso (9/9): Quiere que sea visible para los demas usuarios?\nIndique (numero): 0 para no visible y 1 para visible"<<std::endl;
                std::cin>>ActivityVis_num;
                std::cin.ignore(1000, '\n');
                switch (ActivityVis_num)
                {
                case '0':
                    ActivityVisuality = "0";
                break;
                case '1':
                    ActivityVisuality = "1";
                break;
                    
                default:
                    ActivityVisuality = "1";
                    break;
                }
                SetVisuality(ActivityVisuality);
                system("clear");
                nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                std::ifstream Inscritos(nombreActividad);
                std::string data;
                std::vector<std::string> Insc;
                    if(Inscritos.is_open()){

                        std::getline(Inscritos, title_);
                        std::getline(Inscritos, description_);
                        std::getline(Inscritos, date_);
                        std::getline(Inscritos, hour_);
                        std::getline(Inscritos, clase_);
                        std::getline(Inscritos, speaker_);
                        std::getline(Inscritos, precio);
                        SetPrice(precio);
                        std::getline(Inscritos, tipo);
                        SetType(ToEnum(tipo));
                        std::getline(Inscritos, ActivityVisuality);
                        SetVisuality(ActivityVisuality);
                        while(std::getline(Inscritos, data)){
                            Insc.push_back(data);
                        }
                    Inscritos.close();
                    }
                    else{
                        system("clear");
                        printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                        std::cin.get();
                        return false;
                    }
                std::ofstream Actividad(nombreActividad);
                    if(Actividad.is_open()){
                        Actividad<<titulo<<"\n"<<descripcion<<"\n"<<fecha<<"\n"<<hora<<"\n"<<clase<<"\n"<<precio<<"\n"<<tipo<<std::endl;
                        for(int i= 0; i <= Insc.size(); i++){
                            Actividad<<Insc[i]<<std::endl;
                        }
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
    if(EstaPreInscrito(usuario, nombre_fichero_actividad) == false){
        system("clear");
        printf("No estas preinscrito en esta actividad\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    }
    std::ifstream file ("../../data/activitiesdata/Actividades.txt");
    if (file.is_open()){
        while(std::getline(file, nombreActividad)){
            if( nombreActividad == nombre_fichero_actividad){
                VerInformacionActividad((std::string)nombreActividad, 2 );
                std::cout<<"¿Esta seguro de querer eliminar su preinscripcion de esta actividad?\nEscriba CONFIRMAR para eliminar su preinscripcion"<<std::endl;
                std::cin>>confirmacion;
                if(confirmacion == "confirmar" || confirmacion == "CONFIRMAR"){
                    nombreActividad= "../../data/activitiesdata/" + nombreActividad;
                    std::ofstream NuevaActividad("../../data/activitiesdata/ActividadRemplazo");
                    std::ifstream Actividad(nombreActividad);
                        if(Actividad.is_open()){
                            while(std::getline(Actividad, data)){
                                if(data != usuario.GetUserName()){
                                    NuevaActividad<<data<<"\n";
                                    
                                }
                            }
                            file.close();
                            Actividad.close();
                            char * direccion = new char [nombreActividad.length()+1];
                            strcpy(direccion, nombreActividad.c_str());
                            rename("../../data/activitiesdata/ActividadRemplazo", direccion);
                            return true;
                        }
                        else{
                            system("clear");
                            printf("Ha ocurrido un error al abrir el fichero de la actividad\nPresione ENTER para volver atras\n");
                            std::cin.get();
                            return false;
                        }
                }
                else{
                    system("clear");
                    printf("Se ha cancelado la operacion\n\nPresione ENTER para volver atras\n");
                    std::cin.ignore(1000, '\n');
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
//POR VER
bool Actividad::EstaPreInscrito(User usuario, std::string nombre_fichero_actividad){
    int count= 0;
    std::string nombreActividad, precio, ActivityVisuality, tipo;
    std::ifstream file("../../data/activitiesdata/Actividades.txt");

    if (file.is_open()){
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
                    std::getline(Actividad, speaker_);
                    std::getline(Actividad, precio);
                    SetPrice(precio);
                    std::getline(Actividad, tipo);
                    SetType(ToEnum(tipo));
                    std::getline(Actividad, ActivityVisuality);
                    SetVisuality(ActivityVisuality);
                        while(std::getline(Actividad, Inscritos)){
                            if(Inscritos == usuario.GetUserName()){
                                //std::cout<<"estas inscrito en esta actividad"<<std::endl;
                                file.close();
                                Actividad.close();
                                return true;
                            }
                        }
                    system("clear");
                    //printf("\nNo estas preinscrito en la actividad seleccionada\n");
                    //sleep(3);
                    Actividad.close();
                    file.close();
                    return false;
                }
                else{
                    system("clear");
                    printf("ERROR al ver su preinscripcion en la actividad\n\nPresione ENTER para volver atras\n");
                    std::cin.get();
                    return false; 
                }
            }
        }
    file.close();
    system("clear");
    printf("ERROR la actividad no Existe\n\nPresione ENTER para volver atras\n");
    std::cin.get();
    return false;
    

    }
    else{
        system("clear");
        printf("ERROR al ver si estas preinscrito en la acttividad\n\nPresione ENTER para volver atras\n");
        std::cin.get();
        return false;
    }  
}