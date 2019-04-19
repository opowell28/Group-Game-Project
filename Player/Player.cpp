//
// Created by agreene17021 on 3/27/2019.
//

#include "Player.h"

int Player::getHealth() {
    return this->health;
}

void Player::setHealth(int health) {
    this->health = health;
}

int Player::getStrength() {
    return this->strength;
}

void Player::setStrength(int strength) {
    this->strength = strength;
}

int Player::getDexterity() {
    return this->dexterity;
}

void Player::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}

int Player::getConstitution() {
    return this->constitution;
}

void Player::setConstitution(int constitution) {
    this->constitution = constitution;
}

std::string Player::getName() {
    return this->name;
}

//get the players carry capacity
double Player::getCarryCapacity(double carryCapacity) {
    return this->carryCapacity;
}
/*    IT MAY NOT BE NECESSARY TO USE THIS INSTEAD OF Character::attack
int Player::attack() {
    int atkDamage;
    //generate number between 1 and 5 for light damage
    if (atkStrength == "light" || atkStrength == "Light") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 5) + 1;
            return atkDamage;
        }
    }
    //generate random number between 6 and 10 for heavy damage
    else if (atkStrength == "heavy" || atkStrength == "Heavy") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 10) + 6;
            return atkDamage;
        }
    }
}
 */
