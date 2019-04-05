//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>

class CombatSituation {
protected:
    std::string combatCommands;

public:
    void inCombat();
    void playerActions();
    void enemyActions();
};

#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H