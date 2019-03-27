//
// Created by agreene17021 on 3/27/2019.
//

#include "Character.h"

int Character::getHealth(int health) {
    health = this->health;
    return health;
}

int Character::Attack(int damage, int opponentHealth) {
    opponentHealth -= damage;
    return opponentHealth;
}

int Character::Heal(int health) {
    this->health += health;
    return this->health;
}