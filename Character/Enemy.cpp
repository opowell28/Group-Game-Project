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

//attack function for if an enemy attacks player
void Enemy::Attack(Player target, int minDamage, int maxDamage, int missChance, int weaponDamage) {
    int damage = 0;
    int miss;

    damage = ((minDamage + rand() % maxDamage + 1) * getStrength()) + weaponDamage;
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
