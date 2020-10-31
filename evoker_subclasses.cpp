#include "evoker_subclasses.h"

Fire_user::Fire_user(std::string name, int HP, int mana, int ability_power, int fire_power)
        : Evoker(name, HP, mana, ability_power), fire_power{fire_power} {
}

void Fire_user::print(std::ostream &os) const {
    Evoker::print(os);
    os << ", " << fire_power << " Fire power ";
}

void Fire_user::show_status() const{
    Evoker::show_status();
    std::cout << "Fire power: " << fire_power << std::endl;
}

/// Spells
void Fire_user::cast_Fireball() const{
    std::cout << "I tell her baby, baby, baby. I'm a fireball... - Mr.Worldwide Pitbull\n" <<
              this->name << " cast Fireball!\n";

    int burn_chance = 20 * (1 + this->fire_power);
    if(rand() % 100 + 1 <= burn_chance)
        std::cout << "You also have a burning effect on you.\n";
}



/**
 * Evoker - Earth User Class
 */
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
    switch (this->stamina){
        case 0: std::cout << this->name << " cast a 1 second Earthquake..\n";
        case 1: std::cout << this->name << " cast a 10 second Earthquake\n";
        case 2: std::cout << "Warning: Rockfall!\n" << this->name << " cast a magnitude 10 Earthquake!\n";
        case 3: std::cout << this->name << " just destroyed this planet and himself. :(\n";
    }
}



/**
 * Evoker - Air User Class
 */
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
