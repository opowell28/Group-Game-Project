//
// Created by agreene17021 on 3/27/2019.
//

#include "Character.h"

int Character::getHealth(int health) {
    health = this->health;
    return health;
}

int Character::Attack(int damage, int opponentHealth) {
    //generate random damage between 1 and 5
    srand((unsigned)time(0));
    for(int index = 0; index < 1; index++) {
        damage = (rand() % 5) + 1;
        return damage;
    }
    //subtract generated damage from opponent's health
    opponentHealth -= damage;
    return opponentHealth;
}

int Character::Heal(int health) {
    this->health += health;
    return this->health;
}

//TODO: base damage off what weapon is being carried
int Character::Damaged(int health) {
    //removes between 1 and 10 from player's health
    srand((unsigned)time(0));
    for(int index = 0; index < 1; index++) {
        health -= (rand() % 10) + 1;
        return health;
    }
}