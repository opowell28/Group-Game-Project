//
// Created by agreene17021 on 3/27/2019.
//

#ifndef UNTITLED_CHARACTER_H
#define UNTITLED_CHARACTER_H

#include <iostream>

class Character {
private:
    int health;
    std::string equippedItem;
    std::string equippedWeapon;

public:
    virtual int getHealth(int health);
    virtual int Attack(int damage, int opponentHealth);
    virtual int Heal(int health);
    virtual int Damaged(int health);

};


#endif //UNTITLED_CHARACTER_H
