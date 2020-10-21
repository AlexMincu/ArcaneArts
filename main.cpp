#include "the_arcane_arts.h"

int main(){
    srand(time(nullptr));

    Fire_user Dumbledore("Albus Dumbledore", 2000, 100, 2);
    Dumbledore.cast_Fireball();

    Earth_user Alegu("Alegu Marian", 100, 101, 3);
    Alegu.cast_Earthquake();

    Air_user PassatB6("Morun", 100, 102, 50);
    PassatB6.cast_Flying_cloud();

    Ash_user Harry("Harry Potah", 150, 103, 2, 80);
    Harry.cast_Ash_tornado();

    Wizzard wiz1("Ozzy");
    Evoker wiz2;

    wiz1.show_stats();
    wiz2.show_stats();
    Dumbledore.show_stats();
    Alegu.show_stats();
    PassatB6.show_stats();
    Harry.show_stats();

    Evoker *Santa = new Evoker;
    Santa = Evoker::cast_Mirror(Harry);
    Santa->show_stats();
    return 0;
}