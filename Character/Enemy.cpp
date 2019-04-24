//
// Created by AJ on 4/17/2019.
//

#include "Enemy.h"

Enemy::Enemy() {
    this->name = "Enemy";
    this->health = 100;
    this->strength = 50;
    this->dexterity = 0;
}

Enemy::Enemy(std::string name, int health, int strength, int dexterity) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->dexterity = dexterity;
}