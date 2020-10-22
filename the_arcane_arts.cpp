#include "the_arcane_arts.h"

/**
 * Wizzard Class
 */
Wizzard::Wizzard(string name, int mana) {
    this->name = name;
    this->mana = mana;
    cout << "Initializing " << this->name << "\n";
}

Wizzard::~Wizzard() {
    cout << "Destroying " << this->name << "\n";
}

Wizzard::Wizzard(const Wizzard &wiz)
        : Wizzard(wiz.name, wiz.mana) {
    cout << "Copy of " << this->name << "\n";
}

ostream &operator<<(ostream &os,const Wizzard &obj){
    os << "Wizzard " << obj.name << " has:\n" << obj.mana << " Mana left\n\n";
    return os;
};


/**
 * Evoker Class
 */
Evoker::Evoker(string name, int mana, int ability_power)
: Wizzard(name, mana) {
    this->ability_power = ability_power;
}

ostream &operator<<(ostream &os,const Evoker &obj){
    os << "Evoker " << obj.name << " has:\n" << obj.mana << " Mana left\n" <<
    obj.ability_power << " Ability power\n\n";
    return os;
};

/****** To do
Evoker * Evoker::cast_Mirror(Evoker w)  {
    Evoker *Obj;
    *Obj = w;
    Obj->name += " Copy";
    return Obj;
}

int Evoker::getAbilityPower() const {
    return ability_power;
}
*/


/**
 * Evoker - Fire User Class
 */
Fire_user::Fire_user(string name, int mana, int ability_power, int fire_power)
: Evoker(name, mana, ability_power) {
    this->fire_power = fire_power;
}

ostream &operator<<(ostream &os,const Fire_user &obj){
    os << "Fire Evoker " << obj.name << " has:\n" << obj.mana << " Mana left\n" <<
       obj.ability_power << " Ability power\n" <<
       obj.fire_power << " Fire power\n\n";
    return os;
};

void Fire_user::cast_Fireball() const{
    cout << "I tell her baby, baby, baby. I'm a fireball... - Mr.Worldwide Pitbull\n" <<
    this->name << " cast Fireball!\n";

    int burn_chance = 20 * (1 + this->fire_power);
    if(rand() % 100 + 1 <= burn_chance)
        cout << "You also have a burning effect on you.\n";
}


/**
 * Evoker - Earth User Class
 */
Earth_user::Earth_user(string name, int mana, int ability_power, int stamina)
: Evoker(name, mana, ability_power) {
    this->stamina = stamina;
}

ostream &operator<<(ostream &os,const Earth_user &obj){
    os << "Earth Evoker " << obj.name << " has:\n" << obj.mana << " Mana left\n" <<
       obj.ability_power << " Ability power\n" <<
       obj.stamina << " Stamina\n\n";
    return os;
};

void Earth_user::cast_Earthquake() const{
    switch (this->stamina){
        case 0: cout << this->name << " cast a 1 second Earthquake..\n";
        case 1: cout << this->name << " cast a 10 second Earthquake\n";
        case 2: cout << "Warning: Rockfall!\n" << this->name << " cast a magnitude 10 Earthquake!\n";
        case 3: cout << this->name << " just destroyed this planet and himself. :(\n";
    }
}


/**
 * Evoker - Air User Class
 */
Air_user::Air_user(string name, int mana, int ability_power, int wind_speed_control)
:Evoker(name, mana, ability_power) {
    this->wind_speed_control = wind_speed_control;
}

ostream &operator<<(ostream &os,const Air_user &obj){
    os << "Air Evoker " << obj.name << " has:\n" << obj.mana << " Mana left\n" <<
       obj.ability_power << " Ability power\n" <<
       obj.wind_speed_control << " Wind speed control\n\n";
    return os;
};

void Air_user::cast_Flying_cloud() const{
    if(this->wind_speed_control < 25)
        cout << "Brr, we CHILLing\n";
    else if(this->wind_speed_control < 80)
        cout << this->name << "'s gone with the wind\n";
    else
            cout << "Unlimited speeeed!!\n";
}


/**
 * Evoker - Air User Class
 */
Ash_user::Ash_user(string name, int mana, int ability_power, int fire_power, int wind_speed_control)
: Evoker(name, mana, ability_power),
  Fire_user(name, mana, ability_power, fire_power),
  Air_user(name, mana, ability_power, wind_speed_control){
}

ostream &operator<<(ostream &os,const Ash_user &obj){
    os << "Ash Evoker " << obj.name << " has:\n" << obj.mana << " Mana left\n" <<
       obj.ability_power << " Ability power\n" <<
       obj.fire_power << " Fire power\n" <<
       obj.wind_speed_control << " Wind speed control\n\n";
    return os;
};

void Ash_user::cast_Ash_tornado() const{
    if(this->fire_power > 0 && this->wind_speed_control > 50)
        cout << this->name << " just smoked you.\n";
}