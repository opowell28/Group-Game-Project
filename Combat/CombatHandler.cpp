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
//TODO: generate random damage on a range of small numbers
int Player::playerDamaged(int i) {
    this->health -= i;
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
    cout << "Heavy or light attack? " << endl;
    getline(cin, this->atkStrength);
}

//attack function which lowers enemy health by a randomly generated number
int Attack::attack(int atkStrength) {
    //generate random number between 2 and 9 for damage
    atkStrength = rand() % 9 + 2;
}
