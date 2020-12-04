#include "Characters/Hero.h"

Hero::Hero(int hp, int mana, int experience, const Hero::abilities &ability)
        : hp(hp), mana(mana), experience(experience), ability(ability) { std::cout << "Char creation \n";}