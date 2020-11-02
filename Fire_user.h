#pragma once
#include <utility>

#include "Evoker.h"

class Fire_user : virtual public Evoker {
protected:
    int fire_power; // 0 - low, 1 - medium, 2 - high
public:
    Fire_user(std::string name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0, int fire_power = 0);
    void print (std::ostream &os) const override;
    void show_status() const override;

    void cast_Fireball() const;
    void cast_Spells(char) const override;
};



Fire_user::Fire_user(std::string name, int HP, int mana, int ability_power, int fire_power)
        : Evoker(std::move(name), HP, mana, ability_power), fire_power{fire_power} {
}

void Fire_user::print(std::ostream &os) const {
    Evoker::print(os);
    os << ", " << fire_power << " Fire power ";
}

void Fire_user::show_status() const {
    Evoker::show_status();
    std::cout << "Fire power: " << fire_power << std::endl;
}

/// Spells
void Fire_user::cast_Fireball() const{
    std::cout << "I tell her baby, baby, baby. I'm a fireball... - Mr.Worldwide Pitbull" << std::endl <<
              this->name << " cast Fireball!" << std::endl;

    int burn_chance = 20 * (1 + this->fire_power);
    if(rand() % 100 + 1 <= burn_chance)
        std::cout << "You also have a burning effect on you." << std::endl;
}

void Fire_user::cast_Spells(char selection) const {
    switch(selection){
        case '0':   //cast All spells
            std::cout << "I'm going full power!" << std::endl;
            cast_Fireball();
            break;
        case '1':   //cast Fireball
            cast_Fireball();
            break;
        default:
            std::cout << "I'm not ready for that..." << std::endl;
            break;
    }
}
