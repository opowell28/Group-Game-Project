//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_CHARACTER_H
#define INC_4_GROUPPROJECT_CHARACTER_H

#include <iostream>
#include "../Player/Player.h"

class Character : public Player {
protected:
    int characterHealth;
    std::string equippedItem;
    std::string equippedWeapon;
public:
    Character();
    Character(int health, std::string equippedItem, std::string equippedWeapon);
    virtual int getHealth(int characterHealth);
    virtual int enemyAttack(int damage);
    virtual int enemyDamaged(int characterHealth);
    virtual int enemyHeal(int characterHealth);
};


#endif //INC_4_GROUPPROJECT_CHARACTER_H