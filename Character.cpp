//
// Created by agreene17021 on 3/27/2019.
//

#include "Character.h"

int Character::GetHealth(int health) {
    health = this->health;
    return health;
}

int Character::GetDamage(int damage) {
    damage = this->damage;
    return damage;
}

void Character::SetDamage(int damage) {
    this->damage = damage;
}

int Character::Attack(int opponentHealth) {
    opponentHealth -= this->damage;
    return opponentHealth;
}

int Character::Heal(int health) {
    this->health += health;
    return this->health;
}