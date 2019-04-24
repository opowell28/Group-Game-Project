//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"
#include "../Character/Enemy.h"

class Player : virtual public Character {

public:

    Player();
    Player(std::string name, int health, int strength, int dexterity);

    std::string getWeaponChoiceAndEquip(Player player);

    std::vector<Weapon*> playerInventory;

};


#endif //INC_4_GROUPPROJECT_PLAYER_H