#ifndef ACTIVITY_H
#define ACTIVITY_H
    #include <iostream>
    #include <string>
    #include "../user/user.h"
    #include <filesystem>
    #include <fstream>
    #include <cstdlib>
    #include <string.h>
    #include <unistd.h>
    enum tipo{
        seminario,
        taller,
        ponencia,
        congreso
    };
    inline tipo ToEnum(std::string v){
        int cont=0;
        if(v == "seminario"){cont= 1;}
        if(v == "taller"){cont= 2;}
        if(v == "ponencia"){cont= 3;}
        if(v == "congreso"){cont= 4;}
        switch(cont){
            case 1: return seminario;
            case 2: return taller;
            case 3: return ponencia;
            case 4: return congreso;
        }
    };
    class Actividad{
        private:
        std::string title_;
        std::string description_;
        std::string date_;
        std::string hour_;
        std::string clase_;
        std::string speaker_;
        std::string price_;
        tipo ActType_;
        std::string ActivityVisuality_;
        public:
        Actividad(std::string title= "\n", std::string description= "\n", std::string date= "\n", std::string hour= "\n", std::string clase= "\n", std::string price= "0");

        void VerInformacionActividad(std::string nombre_fichero_actividad, int number);
        bool CrearActividad();
        bool PreInscribirse(User usuario, std::string nombre_fichero_actividad);
        void MostrarListaInscritos(std::string nombre_fichero_actividad);
        bool ModificarActividad(std::string nombre_fichero_actividad);
        bool EliminarPreInscripcion(User usuario, std::string nombre_fichero_actividad);
        bool EstaPreInscrito(User usuario, std::string nombre_fichero_actividad);

        std::string GetTitle(){return title_;}
        std::string GetDescription(){return description_;}
        std::string GetHour(){return hour_;}
        std::string GetDate(){return date_;}
        std::string GetClass(){return clase_;}
        std::string GetSpeaker(){return speaker_;}
        std::string GetPrice(){return price_;}
        tipo GetType(){return ActType_;}
        std::string GetVisuality(){return ActivityVisuality_;}

        void SetTitle(std::string title){title_= title;}
        void SetDescription(std::string description){description_= description;}
        void SetHour(std::string hour){hour_= hour;}
        void SetDate(std::string date){date_= date;}
        void SetClass(std::string clase){clase_= clase;}
        void SetSpeaker(std::string speaker){speaker_= speaker;}
        void SetPrice(std::string price){price_= price;}
        void SetType(tipo ActType){ActType_= ActType;}
        void SetVisuality(std::string ActivityVisuality){ActivityVisuality_= ActivityVisuality;}
};

#endif