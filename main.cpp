#include "the_arcane_arts.h"

int main(){
    srand(time(NULL));

    Fire_user Dumbledore("Albus Dumbledore", 2000, 100, 0);
    Dumbledore.cast_Fireball();

    Earth_user Alegu("Alegu Marian", 100, 101, 3);
    Alegu.cast_Earthquake();

    Air_user PassatB6("Morun", 100, 102, 1000);
    PassatB6.cast_Flying_cloud();

    return 0;
}