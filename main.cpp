#include "I_Menu.h"
#include "curses.h"

int main(){

//    entities.push_back(std::make_unique<Fire_user>("Alex"));
//    entities.push_back(std::make_unique<Earth_user>("Dumbo"));
//    entities.push_back(std::make_unique<Air_user>("Mambo"));

//    {
//        std::cout << "======== Test ========" << std::endl;
//
//
//
//        std::cout << "======== Test ========" << std::endl;
//    }

//    Menu::start_game();

    initscr(); /* Start curses mode */
    printw("Hello World !!!"); /* Print Hello World */
    refresh(); /* Print it on to the real screen */
    getch(); /* Wait for user input */
    endwin();


//    system("PAUSE");
    return 0;
}



