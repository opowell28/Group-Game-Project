//
// Created by Owen Powell on 2019-02-13.
//

#include "Weapon.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

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

//weapon's use function which lowers durability by an amount between 1 and 5 and returns the damage done
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

void Weapon::pickUp() {
    if (currentCapacity + Weapon::weight > carryCapacity) {
        cout << "You cannot carry any more items, you will exceed your carry capacity of " << carryCapacity << ". " << endl;
    }
    if (currentCapacity + Weapon::weight < carryCapacity) {
        playerInventory.push_back(/*put weapon variable here*/);
    }
}

//define weapons like this
Weapon* flimsyDagger = Weapon* (3, "Flimsy Dagger", 17, 4.0);
Weapon* weakSword = Weapon* (8, "Weak Sword", 25, 8.0);

//store weapons in this map, which stores all of the stats of each weapon with a key that should be the same as the weapons name
void Weapon::fillWeaponMap() const{
    allWeapons[flimsyDagger] = 0;
    allWeapons[weakSword] = 1;
}

//use this function to return the weapon by passing its name as it was defined (e.g. 'flimsyDagger') and return all stats
Weapon* Weapon::getWeaponStats(std::string weaponName) {
    return allWeapons.find(weaponName)->first;
}