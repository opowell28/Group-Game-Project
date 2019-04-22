//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_CHARACTER_H
#define INC_4_GROUPPROJECT_CHARACTER_H

#include <iostream>
//#include "../Player/Player.h"
//#include "../Character/Enemy.h"

class Character {
protected:
    int health, strength, dexterity, constitution;
    std::string name;
    std::string equippedItem;
    std::string equippedWeapon;

public:
    Character();
    Character(std::string name, int health, int strength, int dexterity);

    int getHealth();
    void setHealth(int health);
    int getStrength();
    void setStrength(int strength);
    int getDexterity();
    void setDexterity(int dexterity);
    int getConstitution();
    void setConstitution(int constitution);
    std::string getEquippedWeapon();
    void setEquippedWeapon(std::string weaponName);
    void setName(std::string name);
    std::string getName();
    //void Attack(Player target, int minDamage, int maxDamage, int missChance, int weaponDamage);
    //void Attack(Enemy target, int minDamage, int maxDamage, int missChance, int weaponDamage);


};


#endif //INC_4_GROUPPROJECT_CHARACTER_H