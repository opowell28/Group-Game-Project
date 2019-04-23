//
// Created by Owen Powell on 2019-02-13.
//

#ifndef INC_4_GROUPPROJECT_WEAPON_H
#define INC_4_GROUPPROJECT_WEAPON_H

#include <string>
#include <vector>
#include <map>
#include "../Inventory/Inventory.h"
#include "../Player/Player.h"

class Weapon : virtual public Inventory, virtual public Player {
protected:

    std::string weaponName;
    int defaultDamage;
    int durability;
    float weight;

    //define weapons like this
    Weapon* flimsyDagger = new Weapon (3, "Flimsy Dagger", 17, 4.0);
    Weapon* weakSword = new Weapon (8, "Weak Sword", 25, 8.0);

public:

    Weapon();
    Weapon(int defaultDamage, std::string name, int durability, float weight);
    ~Weapon();

//    std::vector<Weapon*> allWeapons;
    std::string getWeaponName();
    Weapon* getWeaponStats(std::string weaponName);
    void fillWeaponVector();

    int use();
    void lowerDurability(int min, int max);
    void pickUp();

};

#endif //INC_4_GROUPPROJECT_WEAPON_H