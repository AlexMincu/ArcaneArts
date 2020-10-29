#ifndef ARCANEARTS_THE_ARCANE_ARTS_H
#define ARCANEARTS_THE_ARCANE_ARTS_H
#include <iostream>
#include <string>
#include <time.h>


class Wizzard{
  friend std::ostream &operator<<(std::ostream &os,const Wizzard &obj);
protected:
    std::string name;
    int mana;
public:
    Wizzard(std::string name = "Dummy", int mana = 0);
    ~Wizzard();
    Wizzard(const Wizzard &wiz);
};



/**
 * Evocation Art
 */
class Evoker : public Wizzard {
    friend std::ostream &operator<<(std::ostream &os,const Evoker &obj);
protected:
    int ability_power;
public:
    Evoker(std::string name = "Dummy", int mana = 0, int ability_power = 0);
//    static Evoker *cast_Mirror(Evoker Wizz);
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
