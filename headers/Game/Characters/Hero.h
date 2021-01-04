#pragma once


class Hero {
public:
    struct Abilities {
        int strength;
        int endurance;
        int dexterity;
        int agility;
        int magic;
    };
private:
    Abilities abilities;
    int experience;
//    Inventory *inventory;
};
