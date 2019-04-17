//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_CHARACTER_H
#define INC_4_GROUPPROJECT_CHARACTER_H

#include <iostream>

class Character {
protected:
    int health, strength, dexterity, constitution;
    std::string equippedItem;
    std::string equippedWeapon;

public:
    virtual int getHealth();
    virtual int getStrength();
    virtual void setStrength(int strength);
    virtual int getDexterity();
    virtual void setDexterity(int dexterity);
    virtual int getConstitution();
    virtual void setConstitution(int constitution);
    virtual int enemyAttack(int damage, int opponentHealth);
    virtual int enemyHeal(int health);
    virtual int enemyDamaged(int health);

};


#endif //INC_4_GROUPPROJECT_CHARACTER_H