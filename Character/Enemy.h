//
// Created by AJ on 4/17/2019.
//

#ifndef INC_4_GROUPPROJECT_ENEMY_H
#define INC_4_GROUPPROJECT_ENEMY_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"

class Enemy: virtual public Character, virtual public Weapon{
protected:
    std::string enemyName;

public:

    virtual std::string getName();
    virtual int getHealth();
    virtual void setHealth(int health);

    Enemy(std::string name, int health, int strength);


};


#endif //INC_4_GROUPPROJECT_ENEMY_H
