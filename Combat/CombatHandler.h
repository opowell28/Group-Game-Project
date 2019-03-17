//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>

class Player {
protected:
    std::string playerName = "";
    int health = 0;

public:
    Player();
    Player(std::string name, int health);
//function that depletes health when player is hit
    int playerDamaged (int playerDamage);

};


class Enemy {
protected:
    std::string enemyName = "";
    int health = 0;

public:
    Enemy();
    Enemy(std::string name, int health);
};


class Attack {
protected:
//holds strength of attack, either "light" or "heavy"
    std::string atkStrength = "";

public:
    Attack();
    Attack(std::string atkStrength);
//ask user what type of attack to perform when in a combat situation
    std::string atkRequest();
    int attack(int atkDamage);
};


#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H
