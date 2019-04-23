//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"
#include "../Inventory/Inventory.h"
#include "../Character/Enemy.h"

class Player : virtual public Character, virtual public Inventory, virtual public Enemy { //REMOVED INHERITANCE    , public Weapon
protected:
    double carryCapacity;
public:
    Player();
    Player(std::string name, int health, int strength, int dexterity);
    std::string getWeaponChoiceAndEquip(Player player);
    double getCarryCapacity(double carryCapacity);

    void Attack(Enemy target, int minDamage, int maxDamage, int missChance, int weaponDamage);

};


#endif //INC_4_GROUPPROJECT_PLAYER_H