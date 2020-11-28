#pragma once

#include "Evoker.h"

class Earth_user : virtual public Evoker {
public:
    enum class stamina_levels {low = 0, medium = 1, high = 2, unlimited = 3};
    Earth_user(std::string name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0, stamina_levels stamina = stamina_levels::low);

    void print (std::ostream &os) const override;
    void show_status() const override;
    void cast_Earthquake() const;
    void cast_Spells(char) const override;

private:
    stamina_levels stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
};


Earth_user::Earth_user(std::string name, int HP, int mana, int ability_power, stamina_levels stamina)
        : Evoker(std::move(name), HP, mana, ability_power), stamina{stamina} {
}


std::ostream& operator<<(std::ostream& os, Earth_user::stamina_levels s) {
    switch(s) {
        case Earth_user::stamina_levels::low        : os << "Low";    break;
        case Earth_user::stamina_levels::medium     : os << "Medium";      break;
        case Earth_user::stamina_levels::high       : os << "High";      break;
        case Earth_user::stamina_levels::unlimited  : os << "Unlimited";      break;
        default                                     : os.setstate(std::ios_base::failbit);
    }
    return os;
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
    char sel = static_cast<int>(stamina);
    switch (sel){
        case '0':
            std::cout << this->name << " cast a 1 second Earthquake.." << std::endl;
            break;
        case '1':
            std::cout << this->name << " cast a 10 second Earthquake" << std::endl;
            break;
        case '2':
            std::cout << "Warning: Rockfall!" << std::endl << this->name << " cast a magnitude 10 Earthquake!" << std::endl;
            break;
        case '3':
            std::cout << this->name << " just destroyed this planet and himself. :(" << std::endl;
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
