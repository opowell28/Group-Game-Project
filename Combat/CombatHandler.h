//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>
#include "../Character/Character.h"
#include "../Player/Player.h"

//create a player object and assign it to a pointer
/*
Player player1("Player 1", 50, 100.0);
Player* player = &player1;
*/
class CombatSituation : public Character, public Player {
protected:
    std::string atkStrength;
public:
    virtual void inCombat();
};

#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H