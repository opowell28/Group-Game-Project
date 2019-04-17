//
// Created by agreene17021 on 3/27/2019.
//

#include "Character.h"

int Character::getHealth() {
    return this->health;
}

void Character::setHealth(int health) {
    this->health = health;
}

int Character::getStrength() {
    return this->strength;
}

void Character::setStrength(int strength) {
    this->strength = strength;
}

int Character::getDexterity() {
    return this->dexterity;
}

void Character::setDexterity(int dexterity)() {
    this->dexterity = dexterity;
}

int Character::getConstitution() {
    return this->constitution;
}

void Character::setConstitution(int constitution)() {
    this->constitution = constitution;
}

std::string Character::getName() {
    return this->name;
}

void Character::Attack(Character target, int minDamage, int maxDamage, int missChance) {
    int damage = 0;
    int miss;

    damage = (minDamage + rand() % maxDamage + 1) * getStrength();
    miss = rand() % 100 + 1;

    if(miss <= missChance)
    {
        std::cout << "The attack misses." << std::endl;
    }
    else
    {
        target.setHealth(target.getHealth() - damage);
        std::cout << target.getName() << " has been hit for " << std::to_string(damage) << " points." << std::endl;
    }



}