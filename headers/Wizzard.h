#pragma once
#include <utility>

#include "I_Print.h"
#include "Spellbook.h"

class Wizzard : public I_Print{
protected:
    std::string name;
    int HP;
    int mana;
    Spellbook book;
public:
    Wizzard(std::string name = "Dummy", int HP = 0, int mana = 0,
            Spellbook::rarity_level rarity = Spellbook::rarity_level::Common, int power_level = 0 );  //Constructor
    virtual ~Wizzard();                                             //Destructor
    Wizzard (const Wizzard &wiz);                                   //Copy Ctor
    Wizzard &operator=(const Wizzard &wiz);                         //Copy assignment
    const std::string &getName() const;

    void print (std::ostream &os) const override;
    virtual void show_status() const;
    virtual void cast_Spells(char) const{};
    void setSpellbook(Spellbook::rarity_level rarity, int power_level);
    void brag();
};


Wizzard::Wizzard(std::string name, int HP, int mana, Spellbook::rarity_level rarity, int power_level)
        : name{std::move(name)}, mana{mana}, HP{HP}, book(rarity, power_level) {

    std::cout << "Initializing " << this->name << std::endl;
}

Wizzard::~Wizzard() {
    std::cout << "Destroying " << this->name << std::endl;
}

Wizzard::Wizzard(const Wizzard &wiz)
        : Wizzard(wiz.name, wiz.HP, wiz.mana) {
    std::cout << "Copy of " << this->name << std::endl;
}

Wizzard &Wizzard::operator=(const Wizzard &wiz) {
    name = wiz.name;
    mana = wiz.mana;
    std::cout << "Copy of " << this->name << " using assignment" << std::endl;

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

void Wizzard::setSpellbook(Spellbook::rarity_level rarity, int power_level) {
    book.setSpellbook(rarity, power_level);
}

void Wizzard::brag(){
    book.brag();
}

