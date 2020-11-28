#pragma once
#include <utility>

#include "Wizzard.h"

class Evoker : public Wizzard {
protected:
    int ability_power;
public:
    Evoker(std::string name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0);

    void print (std::ostream &os) const override;
    void show_status() const override;
    void cast_Spells(char) const override{};
};

Evoker::Evoker(std::string name, int HP, int mana, int ability_power)
        : Wizzard{std::move(name), HP, mana}, ability_power{ability_power} {
}

void Evoker::print(std::ostream &os) const {
    Wizzard::print(os);
    os << ", " << ability_power << " Ability power ";
}

void Evoker::show_status() const {
    Wizzard::show_status();
    std::cout << "Ability power: " << ability_power << std::endl;
}