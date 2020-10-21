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
    Wizzard(string name = "Dummy", int mana = 0);
    void show_stats();
};



/*
 * Evocation Art
 */
class Evoker : public Wizzard {
protected:
    int ability_power;
public:
    Evoker(string name = "Dummy", int mana = 0, int ability_power = 0);
    void show_stats();
};

/*
 *  Evoker subclasses
 */
class Fire_user : virtual public Evoker {
protected:
    int fire_power; // 0 - low, 1 - medium, 2 - high
public:
    Fire_user(string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0);
    void show_stats();
    void cast_Fireball();

};

class Earth_user : virtual public Evoker {
protected:
    int stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
public:
    Earth_user(string name = "Dummy", int mana = 0, int ability_power = 0, int stamina = 0);
    void show_stats();
    void cast_Earthquake();
};

class Air_user : virtual public Evoker{
protected:
    int wind_speed_control;
public:
    Air_user(string name = "Dummy", int mana = 0, int ability_power = 0, int wind_speed_control = 0);
    void show_stats();
    void cast_Flying_cloud();
};

class Ash_user : public Fire_user, public Air_user {
public:
    Ash_user(string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0, int wind_speed_control = 0);
    void show_stats();
    void cast_Ash_tornado();
};



/*
/*
 * Necromancy Art
class Necromancer : public Wizzard {
    private:
        int life_force;
    public:
};


    Necromancer subclasses

class Dark_user : public Necromancer {};
class Curse_user : public Necromancer {};
 */

#endif //ARCANEARTS_THE_ARCANE_ARTS_H
