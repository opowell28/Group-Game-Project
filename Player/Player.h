//
// Created by agreene17021 on 3/27/2019.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "../Character/Character.h"

class Player : public Character{
private:
    double carryCapacity;


public:
    Player();
    double GetCarryCapacity(double carryCapacity);
};


#endif //UNTITLED_PLAYER_H
