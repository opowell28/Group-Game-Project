//
// Created by agreene17021 on 3/27/2019.
//

#include "Character.h"

Character::Character() {
    this->name = "Player 1";
    this->health = 100;
    this->strength = 50;
    this->dexterity = 0;
}

Character::Character(std::string name, int health, int strength, int dexterity) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->dexterity = dexterity;
}

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

void Character::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}

int Character::getConstitution() {
    return this->constitution;
}

void Character::setConstitution(int constitution) {
    this->constitution = constitution;
}

std::string Character::getEquippedWeapon() {
    return this->equippedWeapon;
}

void Character::setEquippedWeapon(std::string weaponName) {
    this->equippedWeapon = weaponName;
}

void Character::setName(std::string name) {
    this->name = name;
}

std::string Character::getName() {
    return this->name;
}

