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
    //TODO: possibly add ability to randomly generate durability drop on a small range
    lowerDurability(1);
    return this->defaultDamage;
}

//function which lowers durability by the amount passed to i
void Weapon::lowerDurability(int i) {
    this->durability -= i;
}