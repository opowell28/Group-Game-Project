//
// Created by AJ on 4/24/2019.
//

#ifndef INC_4_GROUPPROJECT_CLASSES_H
#define INC_4_GROUPPROJECT_CLASSES_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Character {

protected:
    int health, strength, dexterity, constitution;
    std::string name;
    std::string equippedItem;
    std::string equippedWeapon;
    double carryCapacity;
    double currentCapacity;

public:
    Character();
    Character(std::string name, int health, int strength, int dexterity);

    int getHealth();
    void setHealth(int health);
    int getStrength();
    void setStrength(int strength);
    int getDexterity();
    void setDexterity(int dexterity);
    int getConstitution();
    void setConstitution(int constitution);
    std::string getEquippedWeapon();
    void setEquippedWeapon(std::string weaponName);
    void setName(std::string name);
    std::string getName();
    double getCurrentCapacity();
    void setCurrentCapacity();
    double getCarryCapacity(double carryCapacity);
    void Attack(Character target, int minDamage, int maxDamage, int missChance, int weaponDamage);

};

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

    int getWeaponDamage();

};

class Weapon : virtual public Player {
protected:

    std::string weaponName;
    int defaultDamage;
    int durability;
    float weight;

    //define weapons like this
    Weapon* flimsyDagger = new Weapon (3, "Flimsy Dagger", 17, 4.0);
    Weapon* weakSword = new Weapon (8, "Weak Sword", 25, 8.0);

public:

    Weapon();
    Weapon(int defaultDamage, std::string name, int durability, float weight);
    ~Weapon();

//    std::vector<Weapon*> allWeapons;
    virtual std::string getWeaponName();
    virtual Weapon* getWeaponStats(std::string weaponName);
//    virtual void fillWeaponVector();

    virtual int use();
    virtual void lowerDurability(int min, int max);

};




#endif //INC_4_GROUPPROJECT_CLASSES_H