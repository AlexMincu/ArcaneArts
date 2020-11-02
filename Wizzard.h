#pragma once
#include "I_Print.h"
#include "Spellbook.h"

class Wizzard : public I_Print, public Spellbook{
protected:
    std::string name;
    int HP;
    int mana;
    class Spellbook;
public:
    Wizzard(std::string name = "Dummy", int HP = 0, int mana = 0);  //Constructor
    virtual ~Wizzard();                                         //Destructor
    Wizzard (const Wizzard &wiz);                       //Copy Ctor
    Wizzard &operator=(const Wizzard &wiz);             //Copy assignment
    const std::string &getName() const;

    void print (std::ostream &os) const override;

    virtual void show_status() const;
    virtual void cast_Spells(char) const{};
};


Wizzard::Wizzard(std::string name, int HP, int mana)
        : name{name}, mana{mana}, HP{HP} {
    this->rarity_level = 0;
    this->power_level = 0;

    std::cout << "Initializing " << this->name << "\n";
}

Wizzard::~Wizzard() {
    std::cout << "Destroying " << this->name << "\n";
}

Wizzard::Wizzard(const Wizzard &wiz)
        : Wizzard(wiz.name, wiz.HP, wiz.mana) {
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

void Wizzard::show_status() const {
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Mana: " << this->mana << std::endl;
}
