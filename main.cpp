#include "the_arcane_arts.h"
#include "evoker_subclasses.h"
#include "Ash_user.h"

int main(){
    srand(time(nullptr));

    Wizzard Shinobu ("Shinobu", 9999);
    Evoker Nothing ("Nothing");
    Evoker Dummy = Nothing;
    Fire_user Dumbledore("Albus Dumbledore", 2000, 100, 2);
    Earth_user Alegu("Alegu Marian", 100, 101, 3);
    Air_user PassatB6("Morun", 100, 102, 50);
    Ash_user Harry("Harry Potah", 150, 103, 2, 80);
    Ash_user newWizz;

//    Dumbledore.cast_Fireball();
//    Alegu.cast_Earthquake();
//    PassatB6.cast_Flying_cloud();
//    Harry.cast_Ash_tornado();
//    newWizz.cast_Flying_cloud();

    std::cout << Shinobu << std::endl;
    std::cout << Nothing << std::endl;
    std::cout << Dummy << std::endl;
    std::cout << Dumbledore << std::endl;
    std::cout << Alegu << std::endl;
    std::cout << PassatB6 << std::endl;
    std::cout << Harry << std::endl;
    std::cout << newWizz << std::endl;


    return 0;
}