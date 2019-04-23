
//
// Created by AJ on 4/17/2019.
//

#ifndef INC_4_GROUPPROJECT_ENEMY_H
#define INC_4_GROUPPROJECT_ENEMY_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"
#include "../Player/Player.h"

class Enemy: virtual public Character { //REMOVED INHERITANCE   ,  public Weapon
protected:

public:
    Enemy();
    Enemy(std::string name, int health, int strength, int dexterity);

    void Attack(Player target, int minDamage, int maxDamage, int missChance, int weaponDamage);


};


#endif //INC_4_GROUPPROJECT_ENEMY_H