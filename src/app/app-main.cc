#include <iostream>
#include <ncurses.h>

int main(int argc, char const *argv[])
{
    //Inicio de preparacion para gestion de teclas
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    //Fin de preparacion

    int key, status = 1;

    while (status == 1)
    {
        printf("COSAS\n");

        key = getch();
        switch (key)
        {
        case KEY_UP:
            printf("keyup\n");
            break;

        case KEY_DOWN:
            printf("keydown\n");
            break;
        
        case 10:
            printf("enter\n");
            break;

        case 27:
            printf("esc\n");
            status=0;
            break;

        default:
            break;
        }
    }

    endwin(); //Cierra la libreria antes de salir del programa

    return 0;
}
