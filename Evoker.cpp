#include "Evoker.h"

/**
 * Evoker Class
 */
Evoker::Evoker(std::string name, int HP, int mana, int ability_power)
        : Wizzard{name, HP, mana}, ability_power{ability_power} {
}

void Evoker::print(std::ostream &os) const {
    Wizzard::print(os);
    os << ", " << ability_power << " Ability power ";
}

void Evoker::show_status() const{
    Wizzard::show_status();
    std::cout << "Ability power: " << ability_power << std::endl;
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
