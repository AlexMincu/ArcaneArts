#include "Ash_user.h"

Ash_user::Ash_user(std::string name, int mana, int ability_power, int fire_power, int wind_speed_control)
        : Evoker(name, mana, ability_power),
          Fire_user(name, mana, ability_power, fire_power),
          Air_user(name, mana, ability_power, wind_speed_control){
}

std::ostream &operator<<(std::ostream &os,const Ash_user &obj){
    os << "Ash Evoker " << obj.name << " has:\n" << obj.mana << " Mana left\n" <<
       obj.ability_power << " Ability power\n" <<
       obj.fire_power << " Fire power\n" <<
       obj.wind_speed_control << " Wind speed control\n\n";
    return os;
};

void Ash_user::cast_Ash_tornado() const{
    if(this->fire_power > 0 && this->wind_speed_control > 50)
        std::cout << this->name << " just smoked you.\n";
}