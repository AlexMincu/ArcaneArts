#include "Characters/Character.h"

#include <iostream>

Character::Character(int hp, int mana, int experience, const Character::abilities &ability)
    : hp(hp), mana(mana), experience(experience), ability(ability) { std::cout << "Char creation \n";}