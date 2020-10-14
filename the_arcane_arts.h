#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef ARCANEARTS_THE_ARCANE_ARTS_H
#define ARCANEARTS_THE_ARCANE_ARTS_H

class Wizzard{
    protected:
        string name;
        bool gender; //0 - male & 1 - female
        int mana;
    public:
};

/*
 * For demonstration purposes I will only declare 2 of the Arcane Arts user
 */
class Evoker : public Wizzard {
    private:
        int ability_power;
    public:
        Evoker(int ability_power, string name, bool gender, int mana);
};

/*class Necromancer : public Wizzard {
    private:
        int life_force;
    public:
};
*/

/*
 *  Evoker subclasses
 */
class Fire_user : public Evoker {};
class Earth_user : public Evoker {};

class Ash_user : public Fire_user, public Earth_user {};

/*
 *  Necromancer subclasses

class Dark_user : public Necromancer {};
class Curse_user : public Necromancer {};
 */
#endif //ARCANEARTS_THE_ARCANE_ARTS_H
