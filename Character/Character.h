//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_CHARACTER_H
#define INC_4_GROUPPROJECT_CHARACTER_H

#include <iostream>

class Character {
protected:
    int health;
    std::string equippedItem;
    std::string equippedWeapon;

public:
    virtual int getHealth(int health);
    virtual int enemyAttack(int damage, int opponentHealth);
    virtual int enemyHeal(int health);
    virtual int enemyDamaged(int health);

};


#endif //INC_4_GROUPPROJECT_CHARACTER_H