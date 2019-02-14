#include <iostream>
#include "Weapons/Weapon.h"

using namespace std;



int main() {

    //neither of these are needed currently, just used for testing the Weapon class
    Weapon* sword = new Weapon(2, "Sword", 109, 23.4);

    sword->use();



    return 0;
}