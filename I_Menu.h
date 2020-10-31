#ifndef ARCANEARTS_I_MENU_H
#define ARCANEARTS_I_MENU_H
#include <iostream>
#include <vector>
#include <memory>
#include "Ash_user.h"

std::vector <std::unique_ptr<Wizzard>> entities;

class Select_character {
public:
    static void select_character();
    static void list_characters();
    static void actions(int);
};

class Create_character {
public:
    static void create_character();
    static void create_character_evoker();
};

class Menu : public Create_character, public Select_character{
public:
    static void start_game();
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
                system("CLS");
                create_character();
                break;
            }
            case '2': {
                system("CLS");
                select_character();
                break;
            }
            case '0': {
                system("CLS");
                std::cout << "Goodbye!" << std::endl;
                game_status = false;
                break;
            }
            default : {
                system("CLS");
                std::cout << "Please try again" << std::endl;
            }
        }
    }
}

void Create_character::create_character() {
    std::cout << "===== Character creation =====" << std::endl;
    std::cout << "Choose what type of Arts will your Wizzard master:" << std::endl;
    std::cout << "1. Evoker" << std::endl;
    std::cout << "--> Press 0 to go back <--" << std::endl;

    char selection;
    std::cin >> selection;
    switch (selection) {
        case '1': {
            system("CLS");
            create_character_evoker();
            break;
        }
        case '0': {
            system("CLS");
            break;
        }
        default: {
            system("CLS");
            std::cout << "Please try again" << std::endl;
        }
    }
}

void Create_character::create_character_evoker(){
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
            system("CLS");
            std::cout << "===== Evoker creation =====" << std::endl;
            std::cout << "You chose Fire specialization" << std::endl;
            std::cout << "Now give your wizzard a name: " << std::endl;

            std::string name;
            std::cin >> name;

            entities.push_back(make_unique<Fire_user>(name));

            system("CLS");
            break;
        }
        case '2': {
            system("CLS");
            std::cout << "===== Evoker creation =====" << std::endl;
            std::cout << "You chose Earth specialization" << std::endl;
            std::cout << "Now give your wizzard a name: " << std::endl;

            std::string name;
            std::cin >> name;

            entities.push_back(make_unique<Earth_user>(name));

            system("CLS");
            break;
        }
        case '3': {
            system("CLS");
            std::cout << "===== Evoker creation =====" << std::endl;
            std::cout << "You chose Air specialization" << std::endl;
            std::cout << "Now give your wizzard a name: " << std::endl;

            std::string name;
            std::cin >> name;

            entities.push_back(make_unique<Air_user>(name));

            system("CLS");
            break;
        }
        case '0': {
            system("CLS");
            break;
        }
        default : {
            system("CLS");
            std::cout << "Please try again" << std::endl;
        }
    }
}

void Select_character::select_character(){
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
            system("CLS");
            actions(static_cast<int>(selection - '0')-1);
            break;
        }
        else {
            system("CLS");
            std::cout << "Please try again" << std::endl;
        }
    }
}

void Select_character::list_characters(){
    for(int i = 0; i < entities.size(); i++){
        std::cout << i+1 << ": " << *(entities[i]) << std::endl;
    }
    std::cout << std::endl;
}

void Select_character::actions(int no){
//    while(true) {
    std::cout << "===== " << entities[no]->getName() << " =====" << std::endl;
    entities[no]->show_status();
//    }
}


#endif //ARCANEARTS_I_MENU_H
