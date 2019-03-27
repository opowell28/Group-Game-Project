//
// Created by agreene17021 on 3/27/2019.
//

#ifndef UNTITLED_CHARACTER_H
#define UNTITLED_CHARACTER_H


class Character {
private:
    int health, damage;
    string equippedItem;
    string equippedWeapon;

public:
    virtual int GetHealth(int health);
    virtual int GetDamage(int damage);
    virtual int SetDamage(int damage);
    virtual int Attack(int opponentHealth);
    virtual int Heal(int health);

};


#endif //UNTITLED_CHARACTER_H
