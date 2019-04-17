//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"
#include "../Weapons/Weapon.h"

class Player : public Character, public Weapon {
protected:
    std::string playerName = "";
    double carryCapacity;
public:
    Player();
    Player(std::string playerName, int playerHealth, double carryCapacity);
    virtual int playerAttack();
    virtual double getCarryCapacity(double carryCapacity);
};


#endif //INC_4_GROUPPROJECT_PLAYER_H