#include <iostream>

//Control de sistemas operativos
#ifdef _WIN32
#include <conio.h> //Biblioteca de reconocimiento de teclas para windows
#else
#include <curses.h> //Bliotecas de reconocimiento de teclas para Linux
#endif


int main(int argc, char const *argv[])
{
    #ifdef _WIN32
    #else
    initscr(); //Inicia la biblioteca curses.h
    raw(); //Desactiva buffer de linea
    keypad(stdscr, TRUE); //Activa las teclas especiales
    #endif

    int key;

    while (true)
    {
        printf("COSAS\n");

        key = getch();


        switch (key)
        {
        case KEY_UP:
            
            break;

        case KEY_DOWN:
            
            break;
        
        case 10:
            
            break;

        case 27:
            
            break;
        default:
            break;
        }



    }
    















    #ifdef _WIN32
    #else
    endwin(); //Finaliza la biblioteca curses.h
    #endif

    return 0;
}
