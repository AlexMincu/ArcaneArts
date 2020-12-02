#pragma once

#include "Enemy.h"

class Character {
public:
    struct abilities {
        int strength = 0;
        int endurance = 0;
        int dexterity = 0;
        int agility = 0;
        int magic = 0;
    };
    Character(int hp, int mana, int experience, const abilities &ability);
//
//    ~Character();
//    virtual void Attack(Enemy e);
//    virtual void Escape(Enemy e);

private:
    int hp;
    int mana;
    int experience;
    abilities ability;
};
