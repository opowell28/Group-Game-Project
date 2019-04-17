//
// Created by agreene17021 on 3/27/2019.
//

#include "Player.h"
#include<time.h>

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


//ask user what strength of attack to perform
std::string Player::atkRequest() {
    std::cout << "Heavy or light attack? Enter 'heavy' or 'light' " << std::endl;
    getline(std::cin, this->atkStrength);
    return atkStrength;
}

//damage function which lowers players health

int Player::playerDamaged() {
    int playerDamage;
    //removes between 1 and 10 from player's health
    srand((unsigned)time(0));
    for(int index = 0; index < 1; index++) {
        playerDamage = (rand() % 10) + 1;
        return playerDamage;
    }
}
