//
// Created by Owen Powell on 2019-02-18.
//

#include "../Player/Player.h"
#include "../Character/Character.h"
#include "../Character/Enemy.h"
#include "../Movement/MoveHandler.h"
#include "CombatHandler.h"
#include <iostream>

//create a singleton of CombatHandler
CombatHandler::CombatHandler() {}

CombatHandler& CombatHandler::getInstance() {

    static CombatHandler instance;
    return instance;

}

//call this function when entering a combat situation in a room in moveHandler
void CombatHandler::inCombat(Player player, Enemy enemy) {

    //create a combat situation
    //CombatSituation combat;    this may not be necessary

    bool InCombat = true;
    int turn = 1;
    std::string input;

    std::cout << "You have entered into battle with " << enemy.getName() << "." << std::endl;

    getWeaponChoiceAndEquip(player);

    while(InCombat)
    {
        if(turn % 2 == 1) //player goes when turn is odd
        {
            std::cout << "Your turn. Do you do a light or heavy attack?" << std::endl;

            getline(std::cin, input);

            if((input == "light") || (input == "Light"))
            {
                player.Attack(enemy, defaultDamage, defaultDamage + dexterity, 10, player.use()); //this function defines the target, minimum and maximum damage, and the chance of missing
            }

            else if((input == "heavy") || (input == "Heavy"))
            {
                player.Attack(enemy, defaultDamage + 5, defaultDamage + dexterity + 5, 20, player.use());
            }

            else if((input == "help") || (input == "Help"))
            {
                //TODO: make function to print the help commands
            }

            else
            {
                std::cout << "Please enter a valid attack command. Type 'Help' or 'help' to view a list of commands." << std::endl;
            }
        }

        else
        {
            enemy.Attack(player, 5, 20, 10, 0); //TODO: make these attributes of individual enemies that would be passed in instead of constant values
        }

        turn++;

        if((enemy.getHealth() <= 0) || (player.getHealth() <= 0))
        {
            InCombat = false;
        }
    }
}