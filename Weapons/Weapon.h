//
// Created by Owen Powell on 2019-02-13.
//

#ifndef INC_4_GROUPPROJECT_WEAPON_H
#define INC_4_GROUPPROJECT_WEAPON_H

#include <string>
#include <vector>
#include "../Player/Player.h"


class Inventory {
protected:
    //max carry weight
    double maxWeight;
    //current carry weight
    double currentWeight;
public:
    //vector to hold inventory items
    std::vector<std::string> playerInventory;
};

class Weapon: public Inventory {
protected:
    int defaultDamage;
    std::string name;
    int durability;
    float weight;
public:
    Weapon();
    Weapon(int defaultDamage, std::string name, int durability, float weight);
    ~Weapon();
    int use();
    void lowerDurability(int i);
    void pickUp();
};

#endif //INC_4_GROUPPROJECT_WEAPON_H
