//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_COMBATHANDLER_H
#define INC_4_GROUPPROJECT_COMBATHANDLER_H

#include <string>

class Player {
protected:
    std::string name = "";
    int health = 0;

public:
    Player();
    Player(std::string name, int health);
    int damaged (int i);                     //function that depletes health when player is hit

};

class Attack {
protected:
    std::string atkStrength = "";                     //holds strength of attack, either "light" or "heavy"

public:
    Attack();
    Attack(std::string atkStrength);
    std::string atkRequest();                             //ask user what type of attack to perform when in a combat situation
    int attack();
};


#endif //INC_4_GROUPPROJECT_COMBATHANDLER_H
