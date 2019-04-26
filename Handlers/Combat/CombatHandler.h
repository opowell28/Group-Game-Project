//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>
#include <map>
#include <algorithm>
#include "../../Classes.h"


class CombatHandler : virtual public Character, virtual public Weapon { // virtual public Player,
private:
    CombatHandler();
protected:
    std::string atkStrength;
public:
    CombatHandler& getInstance();
    void inCombat(Character player, std::string enemyName);
    Character createEnemyObjectFromName(std::string enemyName);

    void pickUp();
};

#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H