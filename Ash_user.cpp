#include "Ash_user.h"

Ash_user::Ash_user(std::string name, int mana, int ability_power, int fire_power, int wind_speed_control)
        : Evoker(name, mana, ability_power),
          Fire_user(name, mana, ability_power, fire_power),
          Air_user(name, mana, ability_power, wind_speed_control){
}

void Ash_user::cast_Ash_tornado() const{
    if(this->fire_power > 0 && this->wind_speed_control > 50)
        std::cout << this->name << " just smoked you.\n";
}

void Ash_user::print(std::ostream &os) const {
    Fire_user::print(os);
    os << ", " << wind_speed_control << " Wind speed control ";
}
