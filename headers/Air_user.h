#pragma once
#include "Evoker.h"

class Air_user : virtual public Evoker{
protected:
    int wind_speed_control;
public:
    Air_user(std::string name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0, int wind_speed_control = 0);
    void print (std::ostream &os) const override;
    void show_status() const override;
    void cast_Flying_cloud() const;
    void cast_Spells(char) const override;
};


Air_user::Air_user(std::string name, int HP, int mana, int ability_power, int wind_speed_control)
        : Evoker(name, HP, mana, ability_power), wind_speed_control{wind_speed_control} {
}

void Air_user::print(std::ostream &os) const {
    Evoker::print(os);
    os << ", " << wind_speed_control << " Wind speed control ";
}

void Air_user::show_status() const {
    Evoker::show_status();
    std::cout << "Wind Speed Control: " << wind_speed_control << std::endl;
}

/// Spells
void Air_user::cast_Flying_cloud() const{
    if(this->wind_speed_control < 25)
        std::cout << "Brr, we CHILLing\n";
    else if(this->wind_speed_control < 80)
        std::cout << this->name << "'s gone with the wind\n";
    else
        std::cout << "Unlimited speeeed!!\n";
}

void Air_user::cast_Spells(char selection) const {
    switch(selection){
        case '0':   //cast All spells
            std::cout << "I'm going full power!" << std::endl;
            cast_Flying_cloud();
            break;
        case '1':   //cast Flying cloud
            cast_Flying_cloud();
            break;
        default:
            std::cout << "I'm not ready for that..." << std::endl;
            break;
    }
}
