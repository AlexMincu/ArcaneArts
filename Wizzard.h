#ifndef ARCANEARTS_WIZZARD_H
#define ARCANEARTS_WIZZARD_H
#include "I_Print.h"


class Wizzard : public I_Print{
protected:
    std::string name;
    int HP;
    int mana;
public:
    Wizzard(std::string name = "Dummy", int HP = 0, int mana = 0);  //Constructor
    ~Wizzard();                                         //Destructor
    Wizzard (const Wizzard &wiz);                       //Copy Ctor
    Wizzard &operator=(const Wizzard &wiz);             //Copy assignment
    const std::string &getName() const;

    void print (std::ostream &os) const override;

    virtual void show_status() const;
};


#endif //ARCANEARTS_WIZZARD_H
