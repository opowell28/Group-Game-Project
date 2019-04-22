//
// Created by Owen Powell on 2019-02-13.
//

#ifndef INC_4_GROUPPROJECT_WEAPON_H
#define INC_4_GROUPPROJECT_WEAPON_H

#include <string>
#include <map>
#include "../Player/Player.h"

class Weapon: virtual public Inventory, virtual public Player {
protected:
    int defaultDamage;
    std::string weaponName;
    int durability;
    float weight;
    std::map<reference_wrapper<Weapon*, std::string>> allWeapons; //map of all weapons in the game, use reference_wrapper to allow references to objects to be stored
public:
    Weapon();
    Weapon(int defaultDamage, std::string name, int durability, float weight);
    ~Weapon();
    std::string getWeaponName();
    Weapon* getWeaponStats(std::string weaponName);
    int use();
    void lowerDurability(int min, int max);
    void pickUp();
    void fillWeaponMap() const;
};

#endif //INC_4_GROUPPROJECT_WEAPON_H
