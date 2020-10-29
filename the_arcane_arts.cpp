#include "the_arcane_arts.h"

/**
 * Wizzard Class
 */
Wizzard::Wizzard(std::string name, int mana)
    : name{name}, mana{mana} {
    std::cout << "Initializing " << this->name << "\n";
}

Wizzard::~Wizzard() {
    std::cout << "Destroying " << this->name << "\n";
}

Wizzard::Wizzard(const Wizzard &wiz)
        : Wizzard(wiz.name, wiz.mana) {
    std::cout << "Copy of " << this->name << "\n";
}

std::ostream &operator<<(std::ostream &os,const Wizzard &obj){
    os << "Wizzard " << obj.name << " has:\n" << obj.mana << " Mana left\n\n";
    return os;
};


/**
 * Evoker Class
 */
Evoker::Evoker(std::string name, int mana, int ability_power)
    : Wizzard{name, mana}, ability_power{ability_power} {
}

std::ostream &operator<<(std::ostream &os,const Evoker &obj){
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


