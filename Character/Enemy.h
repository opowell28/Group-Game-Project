//
// Created by AJ on 4/17/2019.
//

#ifndef INC_4_GROUPPROJECT_ENEMY_H
#define INC_4_GROUPPROJECT_ENEMY_H

#include "../Character/Character.h"

class Enemy: public Character {
protected:
    std::string enemyName;

public:
    Enemy(std::string name, int health, int stregnth);


};


#endif //INC_4_GROUPPROJECT_ENEMY_H
