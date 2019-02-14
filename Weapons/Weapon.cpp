//
// Created by Owen Powell on 2019-02-13.
//

#include "Weapon.h"
#include <iostream>

using namespace std;

Weapon::Weapon() {
    this->defaultDamage = 0;
    this->name = "";
    this->durability = 0;
    this->weight = 0;
}

Weapon::Weapon(int defaultDamage, std::string name, int durability, float weight) {
    this->defaultDamage = defaultDamage;
    this->name = name;
    this->durability = durability;
    this->weight = weight;
}

Weapon::~Weapon() {
    cout << "Destroying weapon" << this->name << endl;
}

int Weapon::use() {
    lowerDurability(1);
    return this->defaultDamage;
}

void Weapon::lowerDurability(int i) {
    this->durability -= i;
}