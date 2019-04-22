//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"
#include "../Inventory/Inventory.h"

class Player : public Character, public Inventory { //REMOVED INHERITANCE    , public Weapon
protected:
/*   no reason for these to be redeclared
    int health, strength, dexterity, constitution;
    std::string name, weaponChoice;
    */
    double carryCapacity;
public:
    Player();
    Player(std::string name, int health, int strength, int dexterity);
/*
    int getHealth();
    void setHealth(int health);
    int getStrength();
    void setStrength(int strength);
    int getDexterity();
    void setDexterity(int dexterity);
    int getConstitution();
    void setConstitution(int constitution);
    std::string setName(std::string name);
    std::string getName();
    */
    std::string getWeaponChoiceAndEquip(Player player);
    double getCarryCapacity(double carryCapacity);

    void Attack(Enemy target, int minDamage, int maxDamage, int missChance, int weaponDamage);

};


#endif //INC_4_GROUPPROJECT_PLAYER_H