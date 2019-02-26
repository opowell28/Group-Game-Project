//
// Created by Owen Powell on 2019-02-18.
//

#include "CombatHandler.h"
#include <iostream>

using namespace std;

//empty player object
Player::Player() {
    this->name = "";
    this->health = 0;
}

//player object with user input variables
Player::Player(std::string name, int health) {
    this->name = name;
    this->health = health;
}

//damage function which lowers players health
//TODO: generate random damage on a range of small numbers
int Player::damaged(int i) {
    this->health -= i;
}



//attack object with empty variables
Attack::Attack() {
    this->atkStrength = "";
}

//attack object with unser input variables
Attack::Attack(std::string atkStrength) {
    this->atkStrength = atkStrength;
}

//ask user what strength of attack to perform
std::string Attack::atkRequest() {
    cout << "Heavy or light attack? " << endl;
    getline(cin, this->atkStrength);
}

//attack function which lowers enemy health by a randomly generated number
/*TODO: add random number generator and enemy health depletion function once
TODO: enemies are implemented*/
int Attack::attack() {

}
