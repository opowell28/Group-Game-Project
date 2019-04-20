//
// Created by Owen Powell on 2019-02-13.
//

#include "Weapon.h"
#include <iostream>

using namespace std;

//weapon with empty variables
Weapon::Weapon() {
    this->defaultDamage = 0;
    this->name = "";
    this->durability = 0;
    this->weight = 0;
}

//weapon with defined variables
Weapon::Weapon(int defaultDamage, std::string name, int durability, float weight) {
    this->defaultDamage = defaultDamage;
    this->name = name;
    this->durability = durability;
    this->weight = weight;
}

//destructor which prints when weapon is no longer being used and is destroyed
Weapon::~Weapon() {
    cout << "Destroying weapon" << this->name << endl;
}

//weapon's use function which lowers durability by 1 and returns the damage done
int Weapon::use() {
    lowerDurability(1, 5);
    return this->defaultDamage;
}

std::string Weapon::getWeaponName() {
    return this->name;
}

//function which lowers durability by the amount passed to i
void Weapon::lowerDurability(int min, int max) {
    this->durability -= (min + rand() % max + 1);
}
/*
void Weapon::pickUp() {
    if (currentWeight + Weapon::weight > maxWeight) {
        cout << "You cannot carry any more. " << endl;
    }
    if (currentWeight + Weapon::weight < maxWeight) {
        playerInventory.push_back(/*put weapon variable here*/);
    }
}
*/