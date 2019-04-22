//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"
#include "../Inventory/Inventory.h"

class Player : public Character, public Weapon, public Inventory {
protected:
/*   these dont need to be redeclared
    int health, strength, dexterity, constitution;
    std::string name, weaponChoice;
    */
    double carryCapacity;
public:
    Player();
    Player(std::string name, int health, int strength, int dexterity);

    int getHealth();
    void setHealth(int health);
    int getStrength();
    void setStrength(int strength);
    int getDexterity();
    void setDexterity(int dexterity);
    int getConstitution();
    void setConstitution(int constitution);
    std::string setPlayerName(std::string name);
    std::string getPlayerName();
    std::string getWeaponChoiceAndEquip(Player player);
    int playerAttack();
    double getCarryCapacity(double carryCapacity);
};


#endif //INC_4_GROUPPROJECT_PLAYER_H