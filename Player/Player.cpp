//
// Created by agreene17021 on 3/27/2019.
//

#include "Player.h"

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
            std::cout << i+1 << ".   " << playerInventory[i].getName() << std::endl;
        }
        std::cout << "Enter any other key to fight with your bare hands." << std::endl;

        std::getline(std::cin, userInput);

        //see if the number entered corresponds to an inventory spot with a weapon
        for (int j = 0; j <= userInput.size(); j++) {
            if (std::to_string(userInput[j]) == std::to_string(j+1)) {
                player.setEquiptedWeapon(playerInventory[userInput[j-1]].getName());
                break;
            }
        }
    } else {
        std::cout << "You don't have any weapons." << std::endl;
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
