//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Character/Enemy.h"

//create a player object and assign it to a pointer     MOVED TO MAIN
/*
Player player1("Player 1", 50, 100.0);
Player* player = &player1;
*/
class CombatHandler : public Character, public Player {
private:
    CombatHandler();
protected:
    std::string atkStrength;
public:
    CombatHandler& getInstance();
    virtual void inCombat(Player player, Enemy enemy);
};

#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H