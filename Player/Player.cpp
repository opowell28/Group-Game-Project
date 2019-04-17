//
// Created by agreene17021 on 3/27/2019.
//

#include "Player.h"

//empty player object
Player::Player() {
    this->playerName = "";
    this->playerHealth = 0;
    this->carryCapacity = 0.0;
}

//player object with parameters
Player::Player(std::string playerName, int playerHealth, double carryCapacity) {
    this->playerName = playerName;
    this->playerHealth = playerHealth;
    this->carryCapacity = carryCapacity;
}

//get the players carry capacity
double Player::getCarryCapacity(double carryCapacity) {
    carryCapacity = this->carryCapacity;
    return carryCapacity;
}


int Player::playerAttack() {
    //holds the input from the player when they want to attack
    std::string atkStrength;
    getline(std::cin, atkStrength);
    //holds the integer value of damage to be dealt to the character
    int atkDamage;
    //generate number between 1 and 3 for light damage
    if (atkStrength == "light" || atkStrength == "Light") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 3) + 1;
            return atkDamage;
        }
        characterHealth -= atkDamage;
        return characterHealth;
    }
        //generate random number between 8 and 10 for heavy damage
    else if (atkStrength == "heavy" || atkStrength == "Heavy") {
        srand((unsigned) time(0));
        for (int index = 0; index < 1; index++) {
            atkDamage = (rand() % 10) + 8;
            return atkDamage;
        }
        characterHealth -= atkDamage;
        return characterHealth;
    } else {
        srand((unsigned) time(0));
        for (int index = 0; index < 1; index++) {
            atkDamage = (rand() % 7) + 4;
            return atkDamage;
        }
        characterHealth -= atkDamage;
        return characterHealth;
    }
}