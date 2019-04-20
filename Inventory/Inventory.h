//
// Created by Owen Powell on 2019-04-19.
//

#ifndef INC_4__GROUPPROJECT_INVENTORY_H
#define INC_4__GROUPPROJECT_INVENTORY_H

#include <string>
#include <vector>
#include "../Weapons/Weapon.h"

class Inventory {
protected:
    double currentCapacity;
public:
    std::vector<Weapon> playerInventory; //IF WE DECIDE TO ADD OTHER KINDS OF ITEMS, THIS WILL BE A VECTOR OF ITEMS INSTEAD OF WEAPONS
};


#endif //INC_4__GROUPPROJECT_INVENTORY_H
