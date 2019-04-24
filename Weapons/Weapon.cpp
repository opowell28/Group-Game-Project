//
// Created by Owen Powell on 2019-02-13.
//

#include "Weapon.h"
#include <iostream>
#include <string>
#include <map>
//#include <algorithm>

using namespace std;

//weapon with empty variables
Weapon::Weapon() {
    this->defaultDamage = 0;
    this->weaponName = "";
    this->durability = 0;
    this->weight = 0;
}

//weapon with defined variables
Weapon::Weapon(int defaultDamage, std::string name, int durability, float weight) {
    this->defaultDamage = defaultDamage;
    this->weaponName = name;
    this->durability = durability;
    this->weight = weight;
}

//destructor which prints when weapon is no longer being used and is destroyed
Weapon::~Weapon() {
    cout << "Destroying weapon" << this->weaponName << endl;
}

//weapon's use function which lowers durability by an amount between 1 and 5 and returns the damage done
int Weapon::use() {
    lowerDurability(1, 5);
    return this->defaultDamage;
}

std::string Weapon::getWeaponName() {
    return this->weaponName;
}

//function which lowers durability by the amount passed to i
void Weapon::lowerDurability(int min, int max) {
    this->durability -= (min + rand() % max + 1);
}

////add previously defined weapons to the allWeapons vector, may not need this
//void Weapon::fillWeaponVector() {
//    allWeapons.push_back(flimsyDagger);
//    allWeapons.push_back(weakSword);
//}

//crawl through vector checking if the weaponName passed to the function is equal to a weapon in the vector, and if it is, return the weapon's stats at the same index
Weapon* Weapon::getWeaponStats(std::string weaponName) {
    for (int i = 0; i < playerInventory.size(); ++i) {
        if (playerInventory[i]->getWeaponName() == weaponName) {
            return playerInventory[i];
        }
    }
}