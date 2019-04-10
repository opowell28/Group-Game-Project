//
// Created by agreene17021 on 3/27/2019.
//

#ifndef INC_4_GROUPPROJECT_PLAYER_H
#define INC_4_GROUPPROJECT_PLAYER_H

#include "../Character/Character.h"

class Player: public Character {
protected:
    std::string playerName = "";
    int playerHealth = 0;
    double carryCapacity;
    std::string atkStrength;

public:
    Player();
    Player(std::string playerName, int playerHealth, double carryCapacity);
    virtual double getCarryCapacity(double carryCapacity);
    virtual int attack();
    virtual std::string atkRequest();
    virtual int playerDamaged();
};


#endif //INC_4_GROUPPROJECT_PLAYER_H