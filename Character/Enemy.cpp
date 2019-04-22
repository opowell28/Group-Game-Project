//
// Created by AJ on 4/17/2019.
//

#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int strength) {
    this->name = name;
    this->health = health;
    this->strength = strength;
}

std::string Character::getName() {
    return this->name;
}

int Enemy::getHealth() {
    return this->health;
}

void Enemy::setHealth(int health) {
    this->health = health;
}
