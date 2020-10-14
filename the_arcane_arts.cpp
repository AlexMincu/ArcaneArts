#include "the_arcane_arts.h"

Evoker::Evoker() {
    this->ability_power = 0;
}

int Evoker::getAbilityPower() const {
    return ability_power;
}

Fire_user::Fire_user(string name, int mana, int ability_power, int fire_power) {
    this->name = name;
    this->mana = mana;
    this->ability_power = ability_power;
    this->fire_power = fire_power;
};

void Fire_user::cast_Fireball() {
    cout << "I tell her baby, baby, baby. I'm a fireball... - Mr.Worldwide Pitbull\n" <<
    this->name << " cast Fireball!\n";

    int burn_chance = 20 * (1 + this->fire_power);
    int burning = rand() % burn_chance + 1;
    if(burning <= burn_chance)
        cout << "You also have a burning effect on you.\n";
}

Earth_user::Earth_user(string name, int mana, int ability_power, int stamina) {
    this->name = name;
    this->mana = mana;
    this->ability_power = ability_power;
    this->stamina = stamina;
}

void Earth_user::cast_Earthquake() {
    switch (this->stamina){
        case 0: cout << this->name << " cast a 1 second Earthquake..\n";
        case 1: cout << this->name << " cast a 10 second Earthquake\n";
        case 2: cout << "Warning: Rockfall!\n" << this->name << " cast a magnitude 10 Earthquake!\n";
        case 3: cout << this->name << " just destroyed this planet and himself. :(\n";
    }
}

Air_user::Air_user(string name, int mana, int ability_power, int wind_speed_control) {
    this->name = name;
    this->mana = mana;
    this->ability_power = ability_power;
    this->wind_speed_control = wind_speed_control;
}

void Air_user::cast_Flying_cloud() {
    if(this->wind_speed_control < 25)
        cout << "Brr, we CHILLing\n";
    else if(this->wind_speed_control < 80)
        cout << "Gone with the wind\n";
        else
            cout << "Unlimited speeeed!!\n";
}