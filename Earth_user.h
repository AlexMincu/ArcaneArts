#pragma once
#include "Evoker.h"

class Earth_user : virtual public Evoker {
private:
    int stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
public:
    Earth_user(std::string name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0, int stamina = 0);
    void print (std::ostream &os) const override;
    void show_status() const override;
    void cast_Earthquake() const;
    void cast_Spells(char) const override;
};


Earth_user::Earth_user(std::string name, int HP, int mana, int ability_power, int stamina)
        : Evoker(name, HP, mana, ability_power), stamina{stamina} {
}

void Earth_user::print(std::ostream &os) const {
    Evoker::print(os);
    os << ", " << stamina << " Stamina ";
}

void Earth_user::show_status() const {
    Evoker::show_status();
    std::cout << "Stamina: " << stamina << std::endl;
}

/// Spells
void Earth_user::cast_Earthquake() const{
    char sel = stamina + '0';
    switch (sel){
        case '0':
            std::cout << this->name << " cast a 1 second Earthquake..\n";
            break;
        case '1':
            std::cout << this->name << " cast a 10 second Earthquake\n";
            break;
        case '2':
            std::cout << "Warning: Rockfall!\n" << this->name << " cast a magnitude 10 Earthquake!\n";
            break;
        case '3':
            std::cout << this->name << " just destroyed this planet and himself. :(\n";
            break;
        default:
            std::cout << "You got no stamina left.." << std::endl;
            break;
    }
}

void Earth_user::cast_Spells(char selection) const {
    switch(selection){
        case '0':   //cast All spells
            std::cout << "I'm going full power!" << std::endl;
            cast_Earthquake();
            break;
        case '1':   //cast Earthquake
            cast_Earthquake();
            break;
        default:
            std::cout << "I'm not ready for that..." << std::endl;
            break;
    }
}
