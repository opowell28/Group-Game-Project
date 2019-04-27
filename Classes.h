//
// Created by AJ on 4/24/2019.
//

#ifndef INC_4_GROUPPROJECT_CLASSES_H
#define INC_4_GROUPPROJECT_CLASSES_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Weapon { //: virtual public Player
protected:

    std::string weaponName;
    int defaultDamage;
    int durability;
    float weight;

    /*
    //define weapons like this
    Weapon* flimsyDagger = new Weapon (3, "Flimsy Dagger", 17, 4.0);
    Weapon* weakSword = new Weapon (8, "Weak Sword", 25, 8.0);
    Weapon* axe = new Weapon (12, "Axe", 30, 12.0);
    Weapon* crossbow = new Weapon (10, "Crossbow", 35, 7.0);
*/
public:

    Weapon();
    Weapon(int defaultDamage, std::string name, int durability, float weight);
    ~Weapon();

    virtual std::string getWeaponName();
    //virtual Weapon* getWeaponStats(std::string weaponName);
    virtual int getWeaponDamage();

    //virtual int use();
    virtual void lowerDurability(int min, int max);

    std::vector<Weapon> playerInventory;

};
/*
class test : public Weapon {
private:
    int one, two;
public:
    test();
    test(int o, int t);
};
 */

class Dagger : virtual Weapon {
public:
    Weapon returnDagger();
};

class Sword : virtual  Weapon {
public:
    Weapon returnSword();
};

class Axe : virtual Weapon {
public:
    Weapon returnAxe();
};

class Crossbow : virtual Weapon {
public:
    Weapon returnBow();
};


class Character : virtual public Weapon {

protected:
    std::string name;
    int health, strength, dexterity;
    std::string equippedWeapon;
    //double carryCapacity;      NOT USED; INVENTORY IS INFINITE
    //double currentCapacity;

public:
    Character();
    Character(std::string playerName, int health, int strength, int dexterity, std::string equippedWeapon);

    int getHealth();
    void setHealth(int health);
    int getStrength();
    void setStrength(int strength);
    int getDexterity();
    void setDexterity(int dexterity);
    std::string getEquippedWeapon();
    void setEquippedWeapon(std::string weaponName);
    void setName(std::string name);
    std::string getName();
    /* NOT USED
    double getCurrentCapacity();
    void setCurrentCapacity();
    double getCarryCapacity(double carryCapacity);
     */
    void Attack(Character &target, int minDamage, int maxDamage, int missChance, int weaponDamage);
    void getWeaponChoiceAndEquip(Character player);

};

class Wolf : virtual Character {
public:
    Character returnWolf();
};

class Bear : virtual Character {
public:
    Character returnBear();
};

class Bat : virtual Character {
public:
    Character returnBat();
};

class Skeleton : virtual Character {
public:
    Character returnSkeleton();
};

class Boss : virtual Character {
public:
    Character returnBoss();
};
/*
class Player : virtual public Character {

public:

    Player();
    Player(std::string name, int health, int strength, int dexterity);

    std::string getWeaponChoiceAndEquip(Player player);
};

class Enemy: virtual public Character {

public:
    Enemy();
    Enemy(std::string name, int health, int strength, int dexterity);

    //int getWeaponDamage();

};
*/






#endif //INC_4_GROUPPROJECT_CLASSES_H