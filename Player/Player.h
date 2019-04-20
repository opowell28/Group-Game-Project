//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"
#include "../Inventory/Inventory.h"

class Player : virtual public Character, virtual public Weapon, virtual public Inventory {
protected:

    int health, strength, dexterity, constitution;
    std::string name, weaponChoice;
    double carryCapacity;
public:
    virtual int getHealth();
    virtual void setHealth(int health);
    virtual int getStrength();
    virtual void setStrength(int strength);
    virtual int getDexterity();
    virtual void setDexterity(int dexterity);
    virtual int getConstitution();
    virtual void setConstitution(int constitution);
    virtual std::string setPlayerName(std::string name);
    virtual std::string getPlayerName();
    virtual std::string getWeaponChoiceAndEquip(Player player);
    virtual int playerAttack();
    virtual double getCarryCapacity(double carryCapacity);
};


#endif //INC_4_GROUPPROJECT_PLAYER_H