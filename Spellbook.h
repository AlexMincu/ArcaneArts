#pragma once
#include <string>
#include <iostream>

class Spellbook{
protected:
    const std::string rarity[4] = {"Common", "Rare", "Epic", "Legendary"};
    int rarity_level; // 0 - Common, 1 - Rare, 2 - Epic, 3 - Legendary
    int power_level;
public:
    Spellbook(int rarity_level = 0, int power_level = 0);
    void setSpellbook(int rarity_level, int power_level);
    void brag();
};

Spellbook::Spellbook(int rarity_level, int power_level)
    : rarity_level{rarity_level}, power_level{power_level} {
    std::cout << "Spellbook constr" << std::endl;
}

void Spellbook::setSpellbook(int rarity_level, int power_level) {
    this->rarity_level = rarity_level;
    this->power_level = power_level;
}

void Spellbook::brag() {
    if(rarity_level < 0 || rarity_level > 3){
        std::cout << "Unknown book. Who are you?" << std::endl;
    }
    else{
        std::cout << "This book it's " << rarity[rarity_level] << " and it has " << power_level << " Power!" << std::endl;
    }
}





