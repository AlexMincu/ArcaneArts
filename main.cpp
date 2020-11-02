#include <vector>
#include <memory>
#include "Ash_user.h"
#include "Earth_user.h"

int main(){

    std::cout << "======== Test ========" << std::endl;

    std::vector <std::unique_ptr<Wizzard>> entities;

    entities.push_back(std::make_unique<Wizzard>("Dummy", 100, 100));
    entities.push_back(std::make_unique<Evoker>("Magician", 100, 100, 50));
    entities.push_back(std::make_unique<Fire_user>("Pyro", 100, 100, 50, 50));
    entities.push_back(std::make_unique<Earth_user>("Earth bender", 100, 100, 50, 200));
    entities.push_back(std::make_unique<Air_user>("WindMaster", 100, 100, 50, 15));
    entities.push_back(std::make_unique<Ash_user>("Gandhara", 100, 100, 50, 60, 80));



    std::cout << "======== Test ========" << std::endl;

//    system("PAUSE");
    return 0;
}



