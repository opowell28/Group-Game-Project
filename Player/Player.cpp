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

//equip a weapon to the player
std::string Player::getWeaponChoiceAndEquip(Player player) {

    //if there is something in the inventory:
    if (!player.playerInventory.empty()) {
        std::string userInput;

        std::cout << "Draw a weapon:" << std::endl;

        //print a list of what is in the inventory
        for (int i = 0; i <= player.playerInventory.size(); i++) {
            //IF WE DECIDE TO ADD OTHER ITEMS THIS WILL NEED CHANGED SO THAT NON-WEAPON ITEMS ARE NOT DISPLAYED
            std::cout << i + 1 << ".   " << playerInventory[i]->getWeaponName() << std::endl;
        }
        std::cout << "Enter any other key to fight with your bare hands." << std::endl;

        std::getline(std::cin, userInput);

        //see if the number entered corresponds to an inventory spot with a weapon
        for (int j = 0; j <= userInput.size(); j++) {
            if (std::to_string(userInput[j]) == std::to_string(j + 1)) {
                player.setEquippedWeapon(playerInventory[userInput[j - 1]]->getWeaponName());

                break;
            }
        }
    } else {
        std::cout << "You don't have any weapons." << std::endl;
    }

}