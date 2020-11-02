#ifndef ARCANEARTS_I_MENU_H
#define ARCANEARTS_I_MENU_H
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Ash_user.h"
//#include <ncurses.h>


void clrscr(void) {std::cout << "\033[2J\033[1;1H" << std::flush;};

std::vector <std::unique_ptr<Wizzard>> entities;

class Menu {
public:
    static void start_game();

    static void create_character();
    static void create_character_evoker();

    static void select_character();
    static void list_characters();
    static void actions(int);
};


void Menu::start_game(){
    bool game_status = true;

    while(game_status){
        std::cout << "Welcome to Arcane Arts!" << std::endl;
        std::cout << "===== Menu =====" << std::endl;
        std::cout << "1. Create character" << std::endl;
        std::cout << "2. Select character" << std::endl;
        std::cout << "--> Press 0 to exit the game <--" << std::endl;

        char selection;
        std::cin >> selection;
        switch(selection){
            case '1': {
                clrscr();
                create_character();
                break;
            }
            case '2': {
                clrscr();
                select_character();
                break;
            }
            case '0': {
                clrscr();
                std::cout << "Goodbye!" << std::endl;
                game_status = false;
                break;
            }
            default : {
                clrscr();
                std::cout << "Please try again" << std::endl;
            }
        }
    }
}

void Menu::create_character() {
    std::cout << "===== Character creation =====" << std::endl;
    std::cout << "Choose what type of Arts will your Wizzard master:" << std::endl;
    std::cout << "1. Evoker" << std::endl;
    std::cout << "--> Press 0 to go back <--" << std::endl;

    char selection;
    std::cin >> selection;
    switch (selection) {
        case '1': {
            clrscr();
            create_character_evoker();
            break;
        }
        case '0': {
            clrscr();
            break;
        }
        default: {
            clrscr();
            std::cout << "Please try again" << std::endl;
        }
    }
}

void Menu::create_character_evoker(){
    std::cout << "===== Evoker creation =====" << std::endl;
    std::cout << "Select which specialization will your Evoker have: " << std::endl;
    std::cout << "1. Fire" << std::endl;
    std::cout << "2. Earth" << std::endl;
    std::cout << "3. Air" << std::endl;
    std::cout << "--> Press 0 to go back <--" << std::endl;

    char selection;
    std::cin >> selection;
    switch(selection) {
        case '1': {
            clrscr();
            std::cout << "===== Evoker creation =====" << std::endl;
            std::cout << "You chose Fire specialization" << std::endl;
            std::cout << "Now give your wizzard a name: " << std::endl;

            std::string name;
            std::cin >> name;

            entities.push_back(std::make_unique<Fire_user>(name));

            clrscr();
            break;
        }
        case '2': {
            clrscr();
            std::cout << "===== Evoker creation =====" << std::endl;
            std::cout << "You chose Earth specialization" << std::endl;
            std::cout << "Now give your wizzard a name: " << std::endl;

            std::string name;
            std::cin >> name;

            entities.push_back(std::make_unique<Earth_user>(name));

            clrscr();
            break;
        }
        case '3': {
            clrscr();
            std::cout << "===== Evoker creation =====" << std::endl;
            std::cout << "You chose Air specialization" << std::endl;
            std::cout << "Now give your wizzard a name: " << std::endl;

            std::string name;
            std::cin >> name;

            entities.push_back(std::make_unique<Air_user>(name));

            clrscr();
            break;
        }
        case '0': {
            clrscr();
            break;
        }
        default : {
            clrscr();
            std::cout << "Please try again" << std::endl;
        }
    }
}

void Menu::select_character(){
    while(true) {
        std::cout << "===== Character selection =====" << std::endl;
        std::cout << "Please chose your desired character:" << std::endl;
        list_characters();
        std::cout << "--> Press 0 to exit the game <--" << std::endl;

        char selection;
        std::cin >> selection;
        if (selection == '0')
            break;
        else if (selection >= '1' && selection <= static_cast<char>(entities.size() + '0') ) {
            clrscr();
            actions(static_cast<int>(selection - '0')-1);
            break;
        }
        else {
            clrscr();
            std::cout << "Please try again" << std::endl;
        }
    }
}

void Menu::list_characters(){
    for(int i = 0; i < entities.size(); i++){
        std::cout << i+1 << ": " << *(entities[i]) << std::endl;
    }
    std::cout << std::endl;
}

void Menu::actions(int no){
//    while(true) {
    std::cout << "===== " << entities[no]->getName() << " =====" << std::endl;
    entities[no]->show_status();
//    }
}


#endif //ARCANEARTS_I_MENU_H
