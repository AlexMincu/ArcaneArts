#include "Wizzard.h"

Wizzard::Wizzard(std::string name, int HP, int mana)
        : name{name}, mana{mana}, HP{HP} {
    std::cout << "Initializing " << this->name << "\n";
}

Wizzard::~Wizzard() {
    std::cout << "Destroying " << this->name << "\n";
}

Wizzard::Wizzard(const Wizzard &wiz)
        : Wizzard(wiz.name, wiz.mana, wiz.HP) {
    std::cout << "Copy of " << this->name << "\n";
}

Wizzard &Wizzard::operator=(const Wizzard &wiz) {
    name = wiz.name;
    mana = wiz.mana;
    std::cout << "Copy of " << this->name << " using assignment\n";

    return *this;
}

const std::string &Wizzard::getName() const {
    return name;
}

void Wizzard::print(std::ostream &os) const {
    os << "Wizzard " << name << " has: " << HP << " HP, " << mana << " Mana left";
}

void Wizzard::show_status() const{
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Mana: " << this->mana << std::endl;
}