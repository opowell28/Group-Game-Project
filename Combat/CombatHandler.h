//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>
#include <map>
#include <algorithm>
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Character/Enemy.h"


class CombatHandler : virtual public Character,  virtual public Player, virtual public Weapon {
private:
    CombatHandler();
protected:
    std::string atkStrength;
public:
    CombatHandler& getInstance();
    void inCombat(Player player, std::string enemyName);
    Enemy createEnemyObjectFromName(std::string enemyName);

    void pickUp();
};

#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H