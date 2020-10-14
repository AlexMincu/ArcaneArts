#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#ifndef ARCANEARTS_THE_ARCANE_ARTS_H
#define ARCANEARTS_THE_ARCANE_ARTS_H

class Wizzard{
protected:
    string name;
    int mana;
public:
};

/*
 * For demonstration purposes I will only declare 2 of the Arcane Arts user
 */
class Evoker : public Wizzard {
protected:
    int ability_power;
    Evoker();
public:
    int getAbilityPower() const;
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
class Fire_user : public Evoker {
protected:
    int fire_power; // 0 - low, 1 - medium, 2 - high
public:
    Fire_user(string name, int mana, int ability_power, int fire_power);
    void cast_Fireball();

};
class Earth_user : public Evoker {
protected:
    int stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
public:
    Earth_user(string name, int mana, int ability_power, int stamina);
    void cast_Earthquake();
};
class Air_user : public Evoker{
protected:
    int wind_speed_control;
public:
    Air_user(string name, int mana, int ability_power, int wind_speed_control);
   void cast_Flying_cloud();
};

class Ash_user : public Fire_user, public Earth_user {};

/*
 *  Necromancer subclasses

class Dark_user : public Necromancer {};
class Curse_user : public Necromancer {};
 */
#endif //ARCANEARTS_THE_ARCANE_ARTS_H
