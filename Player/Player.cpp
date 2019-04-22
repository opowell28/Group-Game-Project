//
// Created by agreene17021 on 3/27/2019.
//

#include "Player.h"

Player::Player():Character() {
    this->name = "Player 1";
    this->health = 100;
    this->strength = 50;
    this->dexterity = 0;
}

Player::Player(std::string name, int health, int strength, int dexterity)
    :Character(){
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->dexterity = dexterity;
}

//ALL OF THESE FUNCTIONS ARE ALREADY IN CHARACTER
/*
int Player::getHealth() {
    return this->health;
}

void Player::setHealth(int health) {
    this->health = health;
}

int Player::getStrength() {
    return this->strength;
}

void Player::setStrength(int strength) {
    this->strength = strength;
}

int Player::getDexterity() {
    return this->dexterity;
}

void Player::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}

int Player::getConstitution() {
    return this->constitution;
}

void Player::setConstitution(int constitution) {
    this->constitution = constitution;
}

std::string Player::getName() {
    return this->name;
}

std::string Player::setName(std::string name) {
    this->name = name;
}
*/

double Player::getCarryCapacity(double carryCapacity) {
    return this->carryCapacity;
}

//equip a weapon to the player
std::string Player::getWeaponChoiceAndEquip(Player player) {

    //if there is something in the inventory:
    if (!player.playerInventory.empty()) {
        std::string userInput;

        std::cout << "Draw a weapon:" << std::endl;

        //print a list of what is in the inventory
        for (int i = 0; i <= player.playerInventory.size(); i++) {
            //IF WE DECIDE TO ADD OTHER ITEMS THIS WILL NEED CHANGED SO THAT NON-WEAPON ITEMS ARE NOT DISPLAYED
            std::cout << i+1 << ".   " << playerInventory[i].getWeaponName() << std::endl;
        }
        std::cout << "Enter any other key to fight with your bare hands." << std::endl;

        std::getline(std::cin, userInput);

        //see if the number entered corresponds to an inventory spot with a weapon
        for (int j = 0; j <= userInput.size(); j++) {
            if (std::to_string(userInput[j]) == std::to_string(j+1)) {
                player.setEquippedWeapon(playerInventory[userInput[j-1]].getWeaponName());

                break;
            }
        }
    } else {
        std::cout << "You don't have any weapons." << std::endl;
    }

}

//attack function for if player attacks enemy
void Player::Attack(Enemy target, int minDamage, int maxDamage, int missChance, int weaponDamage) {
    int damage = 0;
    int miss;

    damage = ((minDamage + rand() % maxDamage + 1) * getStrength()) + weaponDamage;
    miss = rand() % 100 + 1;

    if (miss <= missChance) {
        std::cout << "The attack misses." << std::endl;
    } else {
        target.setHealth(target.getHealth() - damage);
        std::cout << target.getName() << " has been hit for " << std::to_string(damage) << " points." << std::endl;
    }
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
