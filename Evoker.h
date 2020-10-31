#ifndef ARCANEARTS_EVOKER_H
#define ARCANEARTS_EVOKER_H
#include "Wizzard.h"

class Evoker : public Wizzard {
protected:
    int ability_power;
public:
    Evoker(std::string name = "Dummy", int HP = 0, int mana = 0, int ability_power = 0);

    void print (std::ostream &os) const override;
    void show_status() const override;

//    static Evoker *cast_Mirror(Evoker Wizz);
};


#endif //ARCANEARTS_EVOKER_H
