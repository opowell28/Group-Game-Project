//
// Created by Owen Powell on 2019-02-18.
//

#include "CombatHandler.h"
#include <iostream>

using namespace std;

//empty player object
Player::Player() {
    this->playerName = "";
    this->health = 0;
}

//player object with user input variables
Player::Player(std::string name, int health) {
    this->playerName = playerName;
    this->health = health;
}

//damage function which lowers players health
int Player::playerDamaged(int playerDamage) {
    //removes between 1 and 10 from player's health
    srand((unsigned)time(0));
    for(int index = 0; index < 1; index++) {
        playerDamage = (rand() % 10) + 1;
        return playerDamage;
    }
}


Enemy::Enemy() {
    this->enemyName = "";
    this->health = 0;
}

Enemy::Enemy(std::string name, int health) {
    this->enemyName = enemyName;
    this->health = health;
}



//attack object with empty variables
Attack::Attack() {
    this->atkStrength = "";
}

//attack object with user input variables
Attack::Attack(std::string atkStrength) {
    this->atkStrength = atkStrength;
}

//ask user what strength of attack to perform
std::string Attack::atkRequest() {
    cout << "Heavy or light attack? Enter 'heavy' or 'light' " << endl;
    getline(cin, this->atkStrength);
}

//attack function which lowers enemy health by a randomly generated number
int Attack::attack(int atkDamage) {
    //generate random number between 6 and 10 for heavy damage
    if (atkStrength == "heavy" || atkStrength == "Heavy") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 10) + 6;
            return atkDamage;
        }
    }
    //generate number between 1 and 5 for light damage
    else if (atkStrength == "light" || atkStrength == "Light") {
        srand((unsigned)time(0));
        for(int index = 0; index < 1; index++) {
            atkDamage = (rand() % 5) + 1;
            return atkDamage;
        }
    }
}
