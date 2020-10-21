#include "the_arcane_arts.h"

/*
 * Wizzard Class
 */
Wizzard::Wizzard(string name, int mana) {
    this->name = name;
    this->mana = mana;
}

void Wizzard::show_stats() const{
    printf("\nVrajitorul %s are %d Mana", name.c_str(), mana);
}


/*
 * Evoker Class
 */
Evoker::Evoker(string name, int mana, int ability_power)
: Wizzard(name, mana) {
    this->ability_power = ability_power;
}

void Evoker::show_stats() const{
    Wizzard::show_stats();
    printf(", %d Ability Power", ability_power);
}


/*
 * Evoker - Fire User Class
 */
Fire_user::Fire_user(string name, int mana, int ability_power, int fire_power)
: Evoker(name, mana, ability_power) {
    this->fire_power = fire_power;
};

void Fire_user::show_stats() const{
    Evoker::show_stats();
    printf(", %d Fire Power", fire_power);
}


void Fire_user::cast_Fireball() const{
    cout << "I tell her baby, baby, baby. I'm a fireball... - Mr.Worldwide Pitbull\n" <<
    this->name << " cast Fireball!\n";

    int burn_chance = 20 * (1 + this->fire_power);
    if(rand() % 100 + 1 <= burn_chance)
        cout << "You also have a burning effect on you.\n";
}


/*
 * Evoker - Earth User Class
 */
Earth_user::Earth_user(string name, int mana, int ability_power, int stamina)
: Evoker(name, mana, ability_power) {
    this->stamina = stamina;
}

void Earth_user::show_stats() const{
    Evoker::show_stats();
    printf(", %d Stamina", stamina);
}

void Earth_user::cast_Earthquake() const{
    switch (this->stamina){
        case 0: cout << this->name << " cast a 1 second Earthquake..\n";
        case 1: cout << this->name << " cast a 10 second Earthquake\n";
        case 2: cout << "Warning: Rockfall!\n" << this->name << " cast a magnitude 10 Earthquake!\n";
        case 3: cout << this->name << " just destroyed this planet and himself. :(\n";
    }
}



/*
 * Evoker - Air User Class
 */
Air_user::Air_user(string name, int mana, int ability_power, int wind_speed_control)
:Evoker(name, mana, ability_power) {
    this->wind_speed_control = wind_speed_control;
}

void Air_user::show_stats() const{
    Evoker::show_stats();
    printf(", %d Wind Speed Control", wind_speed_control);
}

void Air_user::cast_Flying_cloud() const{
    if(this->wind_speed_control < 25)
        cout << "Brr, we CHILLing\n";
    else if(this->wind_speed_control < 80)
        cout << this->name << "'s gone with the wind\n";
    else
            cout << "Unlimited speeeed!!\n";
}

/*
 * Evoker - Air User Class
 */
Ash_user::Ash_user(string name, int mana, int ability_power, int fire_power, int wind_speed_control)
: Evoker(name, mana, ability_power),
  Fire_user(name, mana, ability_power, fire_power),
  Air_user(name, mana, ability_power, wind_speed_control){
}

void Ash_user::show_stats() const{
    Evoker::show_stats();
    printf(",%d Fire Power, %d Wind Speed Control", fire_power, wind_speed_control);
}

void Ash_user::cast_Ash_tornado() const{
    if(this->fire_power > 0 && this->wind_speed_control > 50)
        cout << this->name << " just smoked you.\n";
}