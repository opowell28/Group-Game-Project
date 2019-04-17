//
// Created by agreene17021 on 3/27/2019.
//

#include "Character.h"

Character::Character() {
    this->characterHealth = 0;
    this->equippedItem = "";
    this->equippedWeapon = "";
}

Character::Character(int health, std::string equippedItem, std::string equippedWeapon) {
    this->characterHealth = health;
    this->equippedItem = equippedItem;
    this->equippedWeapon = equippedWeapon;
}

int Character::getHealth(int health) {
    health = this->characterHealth;
    return health;
}

int Character::enemyAttack(int damage) {
    //generate random damage between 1 and 5
    srand((unsigned)time(0));
    for(int index = 0; index < 1; index++) {
        damage = (rand() % 5) + 1;
        return damage;
    }
    //subtract generated damage from opponent's health
    playerHealth -= damage;
    return playerHealth;
}

int Character::enemyHeal(int health) {
    this->characterHealth += health;
    return this->characterHealth;
}