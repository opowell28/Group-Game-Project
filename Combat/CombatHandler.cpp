//
// Created by Owen Powell on 2019-02-18.
//

#include "../Player/Player.h"
#include "../Character/Character.h"
#include "../Character/Enemy.h"
#include "../Movement/MoveHandler.h"
#include "CombatHandler.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//create a singleton of CombatHandler
CombatHandler::CombatHandler() {}

CombatHandler& CombatHandler::getInstance() {

    static CombatHandler instance;
    return instance;

}

Enemy CombatHandler::createEnemyObjectFromName(std::string enemyName) {
    if (enemyName == "wolf") {
        return Enemy("wolf", 50, 10, 10);
    } else if (enemyName == "[other enemy names]") {
        //TODO: replicate the above return statement for all types of enemies
    }
}

//call this function when entering a combat situation in a room in moveHandler
void CombatHandler::inCombat(Player player, std::string enemyName) {

    Enemy Opponent = createEnemyObjectFromName(enemyName);

    bool InCombat = true;
    int turn = 1;
    std::string input;

    std::cout << "You have entered into battle with " << Opponent.getName() << "." << std::endl;

    player.getWeaponChoiceAndEquip(player);

    while(InCombat)
    {
        if(turn % 2 == 1) //player goes when turn is odd
        {
            std::cout << "Your turn. Do you do a light or heavy attack?" << std::endl;

            getline(std::cin, input);

            if((input == "light") || (input == "Light"))
            {
                player.Attack(Opponent, defaultDamage, defaultDamage + dexterity, 10, 10); //this function defines the target, minimum and maximum damage, and the chance of missing
            }

            else if((input == "heavy") || (input == "Heavy"))
            {
                player.Attack(Opponent, defaultDamage + 5, defaultDamage + dexterity + 5, 20, player.use());
            }

            else if((input == "help") || (input == "Help"))
            {
                //Help code to print commands.
                std::string input, cmd;
                std::ifstream cmds;
                cmds.open("Commands.txt");

                std::vector<std::string> commands;

                //Reads "Commands" text file to add all commands to the vector.
                while(!cmds.eof())
                {
                    getline(cmds, cmd);
                    commands.push_back(cmd);
                }
                cmds.close();


                //Type "help" to print the "commands" vector.
                getline(std::cin, input);
                if(input == "help" || input == "Help")
                {
                    for(std::string s : commands)
                    {
                        std::cout << s << std::endl;
                    }
                }

            }

            else
            {
                std::cout << "Please enter a valid attack command. Type 'Help' or 'help' to view a list of commands." << std::endl;
            }
        }

        else
        {
            Opponent.Attack(player, 5, 20, 10, 0); //TODO: make these attributes of individual enemies that would be passed in instead of constant values
        }

        turn++;

        if(Opponent.getHealth() <= 0)
        {
            std::cout << "You died " << std::endl;
            InCombat = false;
        }

        else if(player.getHealth() <= 0)
        {
            std::cout << "You won this fight " << std::endl;
            InCombat = false;
        }
    }
}