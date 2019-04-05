//
// Created by Owen Powell on 2019-02-18.
//

#include "../Player/Player.h"
#include "../Character/Character.h"
#include "CombatHandler.h"
#include <iostream>

//call this function when entering a combat situation in a room in moveHandler
void CombatSituation::inCombat() {

    //create a combat situation
    CombatSituation combat;

    CombatSituation::playerActions();
    CombatSituation::enemyActions();
}

void CombatSituation::playerActions() {

}

void CombatSituation::enemyActions() {

}