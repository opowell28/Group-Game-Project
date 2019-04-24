
//
// Created by AJ on 4/17/2019.
//

#ifndef INC_4_GROUPPROJECT_ENEMY_H
#define INC_4_GROUPPROJECT_ENEMY_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"
#include "../Player/Player.h"


class Enemy: virtual public Character {

public:

    Enemy();
    Enemy(std::string name, int health, int strength, int dexterity);

    int getWeaponDamage();

};


#endif //INC_4_GROUPPROJECT_ENEMY_H