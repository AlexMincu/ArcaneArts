#ifndef ARCANEARTS_ASH_USER_H
#define ARCANEARTS_ASH_USER_H
#include "evoker_subclasses.h"

class Ash_user : public Fire_user, public Air_user {
public:
    Ash_user(std::string name = "Dummy", int mana = 0, int ability_power = 0, int fire_power = 0, int wind_speed_control = 0);
    void cast_Ash_tornado() const;
    void print (std::ostream &os) const override;
};


#endif //ARCANEARTS_ASH_USER_H
