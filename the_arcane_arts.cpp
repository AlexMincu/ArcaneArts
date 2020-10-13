#include "the_arcane_arts.h"

 void Summon::summon_creature(){
    if (is_creature_alive)
        std::cout << "Creature summoned!\n";
    else
        std::cout <<"Undead creature summoned!\n";
}