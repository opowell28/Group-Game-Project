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
/*    IT MAY NOT BE NECESSARY TO USE THIS INSTEAD OF Character::attack
int Player::attack() {
    int atkDamage;
    //generate number between 1 and 5 for light damage
    if (atkStrength == "light" || atkStrength == "Light") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 5) + 1;
            return atkDamage;
        }
    }
    //generate random number between 6 and 10 for heavy damage
    else if (atkStrength == "heavy" || atkStrength == "Heavy") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 10) + 6;
            return atkDamage;
        }
    }
}
 */
