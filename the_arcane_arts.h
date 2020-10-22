#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#ifndef ARCANEARTS_THE_ARCANE_ARTS_H
#define ARCANEARTS_THE_ARCANE_ARTS_H

class Wizzard{
  friend ostream &operator<<(ostream &os,const Wizzard &obj);
protected:
    string name;
    int mana;
public:
    Wizzard(string name = "Dummy", int mana = 0);
    ~Wizzard();
    Wizzard(const Wizzard &wiz);
};



/*
 * Evocation Art
 */
class Evoker : public Wizzard {
    friend ostream &operator<<(ostream &os,const Evoker &obj);
protected:
    int ability_power;
public:
    Evoker(string name = "Dummy", int mana = 0, int ability_power = 0);
//    static Evoker *cast_Mirror(Evoker Wizz);
};


/*
 *  Evoker subclasses
 */
class Fire_user : virtual public Evoker {
    friend ostream &operator<<(ostream &os,const Fire_user &obj);
protected:
    int fire_power; // 0 - low, 1 - medium, 2 - high
public:
    Fire_user(string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0);
    void cast_Fireball() const;
};



class Earth_user : virtual public Evoker {
    friend ostream &operator<<(ostream &os,const Earth_user &obj);
private:
    int stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
public:
    Earth_user(string name = "Dummy", int mana = 0, int ability_power = 0, int stamina = 0);
    void cast_Earthquake() const;
};



class Air_user : virtual public Evoker{
    friend ostream &operator<<(ostream &os,const Air_user &obj);
protected:
    int wind_speed_control;
public:
    Air_user(string name = "Dummy", int mana = 0, int ability_power = 0, int wind_speed_control = 0);
    void cast_Flying_cloud() const;
};



class Ash_user : public Fire_user, public Air_user {
    friend ostream &operator<<(ostream &os,const Ash_user &obj);
public:
    Ash_user(string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0, int wind_speed_control = 0);
    void cast_Ash_tornado() const;
};



/**
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
