//
// Created by agreene17021 on 3/27/2019.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "../Character/Character.h"

class Player: public Character {
protected:
    std::string playerName = "";
    int playerHealth = 0;
    double carryCapacity;
    std::string atkStrength;

public:
    Player();
    Player(std::string playerName, int playerHealth);
    double GetCarryCapacity(double carryCapacity);
    int attack(int atkDamage);
    std::string atkRequest();
    int playerDamaged(int playerDamage);
};


#endif //UNTITLED_PLAYER_H
