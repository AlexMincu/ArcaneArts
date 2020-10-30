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

void Wizzard::print(std::ostream &os) const {
    os << "Wizzard " << name << " has: " << mana << " Mana left ";
};



/**
 * Evoker Class
 */
Evoker::Evoker(std::string name, int mana, int ability_power)
    : Wizzard{name, mana}, ability_power{ability_power} {
}

void Evoker::print(std::ostream &os) const {
    Wizzard::print(os);
    os << ", " << ability_power << " Ability power ";
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


