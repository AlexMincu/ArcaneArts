#ifndef ARCANEARTS_THE_ARCANE_ARTS_H
#define ARCANEARTS_THE_ARCANE_ARTS_H
#include <iostream>
#include <string>
#include <time.h>
#include "I_Print.h"


class Wizzard : public I_Print{
protected:
    std::string name;
    int mana;
public:
    Wizzard(std::string name = "Dummy", int mana = 0);  //Constructor
    ~Wizzard();                                         //Destructor
    Wizzard (const Wizzard &wiz);                       //Copy Ctor
    Wizzard &operator=(const Wizzard &wiz);             //Copy assignment

    void print (std::ostream &os) const override;
};



/**
 * Evocation Art
 */
class Evoker : public Wizzard {
protected:
    int ability_power;
public:
    Evoker(std::string name = "Dummy", int mana = 0, int ability_power = 0);

    void print (std::ostream &os) const override;
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
