//
// Created by Owen Powell on 2019-02-18.
//

#include "../../Classes.h"
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


//call this function when entering a combat situation in a room in moveHandler
void CombatHandler::inCombat(Character player, std::string enemyName, bool lost) {

    //create an enemy with preset stats
    //Character opponent = createEnemyObjectFromName(enemyName);
    Character opponent;
    if (enemyName == "wolf") {
        Wolf w;
        opponent = w.returnWolf();
    } else if (enemyName == "bear") {
        Bear b;
        opponent = b.returnBear();
    } else if (enemyName == "bat") {
        Bat b;
        opponent = b.returnBat();
    } else if (enemyName == "skeleton") {
        Skeleton s;
        opponent = s.returnSkeleton();
    } else if (enemyName == "boss") {
        Boss b;
        opponent = b.returnBoss();
    }

    lost = false;
    bool InCombat = true;
    int turn = 1;
    std::string input;

    std::cout << "You have entered into battle with " << opponent.getName() << "." << std::endl;

    player.getWeaponChoiceAndEquip(player);

    while(InCombat)
    {

        if(turn % 2 == 1) //player goes when turn is odd
        {
            std::cout << "Your turn. Do you do a light or heavy attack?" << std::endl;
                getline(std::cin, input);

                if ((input == "light") || (input == "Light")) {
                    player.Attack(opponent, defaultDamage, defaultDamage + dexterity, 10,
                                  10); //this function defines the target, minimum and maximum damage, and the chance of missing
                } else if ((input == "heavy") || (input == "Heavy")) {
                    player.Attack(opponent, defaultDamage + 5, defaultDamage + dexterity + 5, 20, getWeaponDamage());
                } else if ((input == "help") || (input == "Help")) {
                    //Help code to print commands.
                    std::string input, cmd;
                    std::ifstream cmds;
                    cmds.open("Commands.txt");

                    std::vector<std::string> commands;

                    //Reads "Commands" text file to add all commands to the vector.
                    while (!cmds.eof()) {
                        getline(cmds, cmd);
                        commands.push_back(cmd);
                    }
                    cmds.close();

                    for (std::string s : commands) {
                        std::cout << s << std::endl;
                    }
                }
        }



        else
        {
            opponent.Attack(player, opponent.getStrength(), opponent.getStrength() + opponent.getDexterity(), 20, 0); //set target, min damage, max damage, miss chance, and weapon damage
        }

        turn++;

        if(opponent.getHealth() <= 0)
        {
            std::cout << "You won this fight " << std::endl;
            InCombat = false;
        }

        else if(player.getHealth() <= 0)
        {
            std::cout << "You died " << std::endl;
            InCombat = false;
            lost = true;
        }
    }
}

/*
void CombatHandler::pickUp() {
    if (currentCapacity + Weapon::weight > carryCapacity) {
        std::cout << "You cannot carry any more items, you will exceed your carry capacity of " << carryCapacity << ". " << std::endl;
    }
    if (currentCapacity + Weapon::weight < carryCapacity) {
        playerInventory.push_back();
    }
}
 */