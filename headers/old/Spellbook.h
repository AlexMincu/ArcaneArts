#pragma once
#include <string>
#include <iostream>

class Spellbook {
public:
    enum class rarity_level {Common = 0, Rare = 1, Epic = 2, Legendary = 3};
    Spellbook(rarity_level rarity = rarity_level::Common, int power_level = 0);

    void setSpellbook(rarity_level, int power_level);
    void brag();

protected:
    rarity_level rarity;
    int power_level;
};

std::ostream& operator<<(std::ostream& os, Spellbook::rarity_level r) {
    switch(r) {
        case Spellbook::rarity_level::Common    : os << "Common";    break;
        case Spellbook::rarity_level::Rare      : os << "Rare";      break;
        case Spellbook::rarity_level::Epic      : os << "Epic";      break;
        case Spellbook::rarity_level::Legendary : os << "Legendary"; break;
        default    : os.setstate(std::ios_base::failbit);
    }
    return os;
}

Spellbook::Spellbook(rarity_level rarity, int power_level)
    : rarity{rarity}, power_level{power_level} {
    std::cout << "Spellbook constr" << std::endl;
}

void Spellbook::setSpellbook(rarity_level rarity, int power_level) {
    this->rarity = rarity;
    this->power_level = power_level;
}

void Spellbook::brag() {
    std::cout << "This book it's " << rarity << " and it has " << power_level << " Power!" << std::endl;
}





