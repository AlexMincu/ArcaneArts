#ifndef ARCANEARTS_EVOKER_SUBCLASSES_H
#define ARCANEARTS_EVOKER_SUBCLASSES_H
#include "the_arcane_arts.h"

class Fire_user : virtual public Evoker {
protected:
    int fire_power; // 0 - low, 1 - medium, 2 - high
public:
    Fire_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0);
    void print (std::ostream &os) const override;
    void cast_Fireball() const;
};



class Earth_user : virtual public Evoker {
private:
    int stamina; // 0 - low, 1 - medium, 2 - high, 3 - unlimited
public:
    Earth_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int stamina = 0);
    void print (std::ostream &os) const override;
    void cast_Earthquake() const;
};



class Air_user : virtual public Evoker{
protected:
    int wind_speed_control;
public:
    Air_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int wind_speed_control = 0);
    void print (std::ostream &os) const override;
    void cast_Flying_cloud() const;
};


#endif //ARCANEARTS_EVOKER_SUBCLASSES_H
