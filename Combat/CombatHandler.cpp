//
// Created by Owen Powell on 2019-02-18.
//

#include "../Player/Player.h"
#include "../Character/Character.h"
#include "../Character/Enemy.h"
#include "../Movement/MoveHandler.h"
#include "CombatHandler.h"
#include <iostream>

//call this function when entering a combat situation in a room in moveHandler
void CombatSituation::inCombat() {

    //create a combat situation
    CombatSituation combat;
    MoveHandler MoveHdlr;
    Player player;
    Enemy enemy;
    bool InCombat;
    int turn;
    std::string input;
    //Placeholder Comment

    std::cout << MoveHdlr.getNameOfEnemyInRoom(MoveHdlr.getX(), MoveHdlr.getY()) << std::endl;

    while(InCombat)
    {
        if(turn % 0)
        {
            getline(std::cin, input);

            if(input == "light" || input == "Light")
            {
                player.Attack(enemy, 5, 10, 10);
            }

            else if(input == "heavy" || input == "Heavy")
            {
                player.Attack(enemy, 10, 20, 20);
            }

            else
            {
                std::cout << "Please enter a valid attack command. Type 'Help' or 'help' to view a list of commands." << std::endl;
            }
        }

        else
        {
            enemy.Attack(player, 5, 20, 10);
        }

        turn++;

        if(enemy.getHealth() <= 0 || player.getHealth() <= 0)
        {
            InCombat = false;
        }
    }

}