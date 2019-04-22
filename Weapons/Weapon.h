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

class Weapon { // REMOVED INHERITANCE FROM PLAYER  :  public Inventory ,  public Player
protected:
    std::string weaponName;
    int defaultDamage;
    int durability;
    float weight;
    //map should not be here because every weapon created would then have its own map
    std::map<std::reference_wrapper<Weapon*, std::string>> allWeapons; //map of all weapons in the game, use reference_wrapper to allow references to objects to be stored
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