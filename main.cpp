#include <vector>
#include <memory>
#include "Ash_user.h"
#include "Earth_user.h"

int main(){

    std::cout << "======== Test ========" << std::endl;

    std::vector <std::unique_ptr<Wizzard>> entities;

    entities.push_back(std::make_unique<Wizzard>("Dummy", 100, 100));
    entities.push_back(std::make_unique<Evoker>("Magician", 100, 100, 50));
    entities.push_back(std::make_unique<Fire_user>("Pyro", 100, 100, 50, Fire_user::fire_levels::high));
    entities.push_back(std::make_unique<Earth_user>("Earth bender", 100, 100, 50, Earth_user::stamina_levels::medium));
    entities.push_back(std::make_unique<Air_user>("WindMaster", 100, 100, 50, 15));
    entities.push_back(std::make_unique<Ash_user>("Gandhara", 100, 100, 50, Fire_user::fire_levels::high, 80));

    std::cout << "\n====== Overloaded << from I_Print ======" << std::endl;
    for(auto & entitie : entities) {
        std::cout << *entitie << std::endl;
    }

    std::cout << "\n====== \"Show status\" virtual function ======" << std::endl;
    for(auto & entitie : entities) {
        std::cout << entitie->getName() << " has: " << std::endl;
        entitie->show_status();
        std::cout << std::endl;
    }

    std::cout << "\n====== Subclasses spells ======" << std::endl;

    std::cout << entities[2]->getName() << ": " << std::endl;
    entities[2]->cast_Spells('0');
    std::cout << std::endl << entities[3]->getName() << ": " << std::endl;
    entities[3]->cast_Spells('0');
    std::cout << std::endl << entities[4]->getName() << ": " << std::endl;
    entities[4]->cast_Spells('0');
    std::cout << std::endl << entities[5]->getName() << ": " << std::endl;
    entities[5]->cast_Spells('0');


    std::cout << "\n====== The use of Class Spellbook ======" << std::endl;
    entities[1]->setSpellbook(Spellbook::rarity_level::Common, 100);
    entities[2]->setSpellbook(Spellbook::rarity_level::Legendary, 9999);
    entities[3]->setSpellbook(Spellbook::rarity_level::Epic, 200);
    entities[4]->setSpellbook(Spellbook::rarity_level::Rare, 500);
    entities[5]->setSpellbook(Spellbook::rarity_level::Legendary, 10000);


    for(auto & entitie : entities){
        std::cout << entitie->getName() << ": ";
        entitie->brag();
    }


    std::cout << "\n======== End of Test ========" << std::endl;

//    system("PAUSE");
    return 0;
}



