//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_CHARACTER_H
#define INC_4_GROUPPROJECT_CHARACTER_H

#include <iostream>

class Character {
protected:
    int health, strength, dexterity, constitution;
    std::string name;
    std::string equippedItem;
    std::string equippedWeapon;

public:
    virtual int getHealth();
    virtual void setHealth(int health);
    virtual int getStrength();
    virtual void setStrength(int strength);
    virtual int getDexterity();
    virtual void setDexterity(int dexterity);
    virtual int getConstitution();
    virtual void setConstitution(int constitution);
    virtual std::string getEquiptedWeapon();
    virtual void setEquiptedWeapon(std::string weaponName);
    virtual void setName(std::string name);
    virtual std::string getName();
    virtual void Attack(Character target, int minDamage, int maxDamage, int missChance, int weaponDamage);

};


#endif //INC_4_GROUPPROJECT_CHARACTER_H