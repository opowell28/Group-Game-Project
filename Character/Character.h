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
    double carryCapacity;
    double currentCapacity;

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
    double getCurrentCapacity();
    void setCurrentCapacity();
    double getCarryCapacity(double carryCapacity);
    void Attack(Character target, int minDamage, int maxDamage, int missChance, int weaponDamage);

};


#endif //INC_4_GROUPPROJECT_CHARACTER_H