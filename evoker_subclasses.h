#ifndef ARCANEARTS_EVOKER_SUBCLASSES_H
#define ARCANEARTS_EVOKER_SUBCLASSES_H
#include "the_arcane_arts.h"

class Fire_user : virtual public Evoker {
    friend std::ostream &operator<<(std::ostream &os,const Fire_user &obj);
protected:
    int fire_power; // 0 - low, 1 - medium, 2 - high
public:
    Fire_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0);
    void cast_Fireball() const;
};



class Earth_user : virtual public Evoker {
    friend std::ostream &operator<<(std::ostream &os,const Earth_user &obj);
private:
    int stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
public:
    Earth_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int stamina = 0);
    void cast_Earthquake() const;
};



class Air_user : virtual public Evoker{
    friend std::ostream &operator<<(std::ostream &os,const Air_user &obj);
protected:
    int wind_speed_control;
public:
    Air_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int wind_speed_control = 0);
    void cast_Flying_cloud() const;
};


#endif //ARCANEARTS_EVOKER_SUBCLASSES_H
