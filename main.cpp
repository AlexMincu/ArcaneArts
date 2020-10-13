#include <iostream>
#include <string>
#include <vector>

class the_arcane_arts{
private:
    unsigned int magic_power_req;
    unsigned int difficulty;
    unsigned int rarity;
public:
};


class Spell : public the_arcane_arts{
private:
    std::vector<std::string> types{"fire", "water", "air", "earth"};
};
class Summon : public the_arcane_arts{
protected:
    bool is_creature_alive;
public:
    void summon_creature(){
        if (is_creature_alive)
            std::cout << "Creature summoned!\n";
        else
            std::cout <<"Undead creature summoned!\n";
    }
};
class Ritual : public the_arcane_arts{
private:
    unsigned int n_objects;
    unsigned int n_sacrifices;
};
class Envision : public the_arcane_arts{
private:
    unsigned int mind_power_req;
};



class Necromancer : public Summon{
private:
public:
    Necromancer(){
        Summon::is_creature_alive = false;
    }
};
class Divination : public Ritual, public Envision{};
class Transmutation : public Spell{};
class Evocation : public Spell{};
class Abjuration : public Spell, public Envision{};
class Ilussion : public Envision{};
class Conjuration : public Summon, public Ritual, public Envision{};
class Enchantment : public Spell, public Envision{};


int main(){

    Necromancer Necro;
    Necro.summon_creature();

    return 0;
}