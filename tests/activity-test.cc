#include "../src/classes/activity/activity.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Actividad obj;
    //std::cout<<obj.GetTitle();
    //if(obj.GetTitle() != "\n"){printf("CONSTRUCTOR FAILED line 8"); return -1;}
    //if(obj.GetDescription() != "\n"){printf("CONSTRUCTOR FAILED line 9"); return -1;}
    //if(obj.GetDate() != "\n"){printf("CONSTRUCTOR FAILED line 10"); return -1;}
    //if(obj.GetHour() != "\n"){printf("CONSTRUCTOR FAILED line 11"); return -1;}
    //if(obj.GetClass() != "\n"){printf("CONSTRUCTOR FAILED line 12"); return -1;}
    //if(obj.GetSpeaker() != "\n"){printf("CONSTRUCTOR FAILED line 13"); return -1;}
    //if(obj.GetPrice() != "0"){printf("CONSTRUCTOR FAILED line 14"); return -1;}
    //if(obj.GetType() != "\n"){printf("CONSTRUCTOR FAILED"); return -1;}
    //if(obj.GetVisuality() != "\n"){printf("CONSTRUCTOR FAILED"); return -1;}


    obj.SetTitle("title");
    obj.SetDescription("description");
    obj.SetDate("12/12/12");
    obj.SetHour("12:30 PM");
    obj.SetClass("Aula 12");
    obj.SetSpeaker("Person A");
    obj.SetPrice("12");
    obj.SetType(seminario);
    obj.SetVisuality("1");


    if(obj.GetTitle() != "title"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetDescription() != "description"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetDate() != "12/12/12"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetHour() != "12:30 PM"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetClass() != "Aula 12"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetSpeaker() != "Person A"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetPrice() != "12"){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetType() != seminario){printf("SET_FUCTIONS FAILED"); return -1;}
    if(obj.GetVisuality() != "1"){printf("SET_FUCTIONS FAILED"); return -1;}


    printf("ALL TESTS PASSED\n");

    return 0;
}