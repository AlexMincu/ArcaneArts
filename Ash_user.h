#pragma once
#include "Fire_user.h"
#include "Air_user.h"

class Ash_user : public Fire_user, public Air_user {
public:
    Ash_user(const std::string& name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0, int fire_power = 0, int wind_speed_control = 0);
    void cast_Ash_tornado() const;
    void print (std::ostream &os) const override;
    void show_status() const override;
    void cast_Spells(char) const override;
};


Ash_user::Ash_user(const std::string& name, int HP, int mana, int ability_power, int fire_power, int wind_speed_control)
        : Evoker(name, HP, mana, ability_power),
          Fire_user(name, HP, mana, ability_power, fire_power),
          Air_user(name, HP, mana, ability_power, wind_speed_control){
}

void Ash_user::print(std::ostream &os) const {
    Fire_user::print(os);
    os << ", " << wind_speed_control << " Wind speed control ";
}

void Ash_user::show_status() const{
    Fire_user::show_status();
    std::cout << "Wind Speed Control: " << wind_speed_control << std::endl;
}

/// Spells
void Ash_user::cast_Ash_tornado() const{
    if(this->fire_power > 0 && this->wind_speed_control > 50)
        std::cout << this->name << " just smoked you.\n";
}

void Ash_user::cast_Spells(char selection) const {
    switch(selection){
        case '0':   //cast All spells
            std::cout << "I'm going full power!" << std::endl;
            cast_Fireball();
            cast_Flying_cloud();
            cast_Ash_tornado();
            break;
        case '1':   //cast Fireball
            cast_Fireball();
            break;
        case '2':   //cast Flying Cloud
            cast_Flying_cloud();
            break;
        case '3':   //cast Ash Tornado Spell
            cast_Ash_tornado();
            break;
        default:
            std::cout << "I'm not ready for that..." << std::endl;
            break;
    }
}

