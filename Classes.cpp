//
// Created by AJ on 4/24/2019.
//

#include "Classes.h"

//Character Class
Character::Character() {

    this->name = "Player 1";
    this->health = 100;
    this->strength = 50;
    this->dexterity = 0;
}

Character::Character(std::string name, int health, int strength, int dexterity) {
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->dexterity = dexterity;
}

int Character::getHealth() {
    return this->health;
}

void Character::setHealth(int health) {
    this->health = health;
}

int Character::getStrength() {
    return this->strength;
}

void Character::setStrength(int strength) {
    this->strength = strength;
}

int Character::getDexterity() {
    return this->dexterity;
}

void Character::setDexterity(int dexterity) {
    this->dexterity = dexterity;
}

std::string Character::getEquippedWeapon() {
    return this->equippedWeapon;
}

void Character::setEquippedWeapon(std::string weaponName) {
    this->equippedWeapon = weaponName;
}

void Character::setName(std::string name) {
    this->name = name;
}

std::string Character::getName() {
    return this->name;
}

double Character::getCarryCapacity(double carryCapacity) {
    return this->carryCapacity;
}

double Character::getCurrentCapacity() {
    return this->currentCapacity;
}

void Character::setCurrentCapacity() {
    this->currentCapacity = currentCapacity;
}

//attack function
void Character::Attack(Character target, int minDamage, int maxDamage, int missChance, int weaponDamage) {
    int damage = 0;
    int miss;

    damage = ((minDamage + rand() % maxDamage + 1) * getStrength()) + weaponDamage;
    miss = rand() % 100 + 1;

    if (miss <= missChance) {
        std::cout << "The attack misses." << std::endl;
    } else {
        target.setHealth(target.getHealth() - damage);
        std::cout << target.getName() << " has been hit for " << std::to_string(damage) << " points." << std::endl;
    }
}

//equip a weapon to the player
std::string Character::getWeaponChoiceAndEquip(Character player) {

    //if there is something in the inventory:
    if (!player.playerInventory.empty()) {
        std::string userInput;

        std::cout << "Draw a weapon:" << std::endl;

        //print a list of what is in the inventory
        for (int i = 0; i <= player.playerInventory.size(); i++) {
            //IF WE DECIDE TO ADD OTHER ITEMS THIS WILL NEED CHANGED SO THAT NON-WEAPON ITEMS ARE NOT DISPLAYED
            std::cout << i + 1 << ".   " << playerInventory[i]->getWeaponName() << std::endl;
        }
        std::cout << "Enter any other key to fight with your bare hands." << std::endl;

        std::getline(std::cin, userInput);

        //see if the number entered corresponds to an inventory spot with a weapon
        for (int j = 0; j <= userInput.size(); j++) {
            if (std::to_string(userInput[j]) == std::to_string(j + 1)) {
                player.setEquippedWeapon(playerInventory[userInput[j - 1]]->getWeaponName());

                break;
            }
        }
    } else {
        std::cout << "You don't have any weapons." << std::endl;
    }

}

/*
//Player Class
Player::Player():Character() {
    this->name = "Player 1";
    this->health = 100;
    this->strength = 50;
    this->dexterity = 0;
}

Player::Player(std::string name, int health, int strength, int dexterity) :Character(){
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->dexterity = dexterity;
}

//equip a weapon to the player
std::string Player::getWeaponChoiceAndEquip(Player player) {

    //if there is something in the inventory:
    if (!player.playerInventory.empty()) {
        std::string userInput;

        std::cout << "Draw a weapon:" << std::endl;

        //print a list of what is in the inventory
        for (int i = 0; i <= player.playerInventory.size(); i++) {
            //IF WE DECIDE TO ADD OTHER ITEMS THIS WILL NEED CHANGED SO THAT NON-WEAPON ITEMS ARE NOT DISPLAYED
            std::cout << i + 1 << ".   " << playerInventory[i]->getWeaponName() << std::endl;
        }
        std::cout << "Enter any other key to fight with your bare hands." << std::endl;

        std::getline(std::cin, userInput);

        //see if the number entered corresponds to an inventory spot with a weapon
        for (int j = 0; j <= userInput.size(); j++) {
            if (std::to_string(userInput[j]) == std::to_string(j + 1)) {
                player.setEquippedWeapon(playerInventory[userInput[j - 1]]->getWeaponName());

                break;
            }
        }
    } else {
        std::cout << "You don't have any weapons." << std::endl;
    }

}
*/

/*
//Enemy Class
Enemy::Enemy() {
    this->name = "Enemy";
    this->health = 100;
    this->strength = 50;
    this->dexterity = 0;
}

Enemy::Enemy(std::string name, int health, int strength, int dexterity) {

    this->name = name;
    this->health = health;
    this->strength = strength;
    this->dexterity = dexterity;
}
*/


//Weapon Class
Weapon::Weapon() {
    this->defaultDamage = 0;
    this->weaponName = "";
    this->durability = 0;
    this->weight = 0;
}

//weapon with defined variables
Weapon::Weapon(int defaultDamage, std::string name, int durability, float weight) {
    this->defaultDamage = defaultDamage;
    this->weaponName = name;
    this->durability = durability;
    this->weight = weight;
}

//destructor which prints when weapon is no longer being used and is destroyed
Weapon::~Weapon() {
    std::cout << this->weaponName << " broke. " << std::endl;
}

std::string Weapon::getEquippedWeapon() {
    return this->equippedWeapon;
}

//weapon's use function which lowers durability by an amount between 1 and 5 and returns the damage done
int Weapon::use() {
    lowerDurability(1, 5);
    if (durability <= 0) {
        delete(getWeaponStats(getEquippedWeapon()));
    }
    return this->defaultDamage;
}

std::string Weapon::getWeaponName() {
    return this->weaponName;
}

//function which lowers durability by the amount passed to i
void Weapon::lowerDurability(int min, int max) {
    this->durability -= (min + rand() % max + 1);
}

int Weapon::getWeaponDamage() {
    return this->defaultDamage;
}

////add previously defined weapons to the allWeapons vector, may not need this
//void Weapon::fillWeaponVector() {
//    allWeapons.push_back(flimsyDagger);
//    allWeapons.push_back(weakSword);
//}

//crawl through vector checking if the weaponName passed to the function is equal to a weapon in the vector, and if it is, return the weapon's stats at the same index
Weapon* Weapon::getWeaponStats(std::string weaponName) {
    for (int i = 0; i < playerInventory.size(); ++i) {
        if (playerInventory[i]->getWeaponName() == weaponName) {
            return playerInventory[i];
        }
    }
}
/*
Dagger::Dagger() {
    this->defaultDamage = 3;
    this->weaponName = "flimsy dagger";
    this->defaultDamage = 17;
    this->weight = 4.0;
}
*/
//classes used as a way to create and return a weapon with desired attributes
Weapon Dagger::returnDagger() {
    Weapon w(3, "flimsy dagger", 17, 4.0);
    return w;
}
Weapon Sword::returnSword() {
    Weapon w(8, "Weak Sword", 25, 8.0);
    return w;
}
Weapon Axe::returnAxe() {
    Weapon w(12, "Axe", 30, 12.0);
    return w;
}
Weapon Crossbow::returnBow() {
    Weapon w(10, "Crossbow", 35, 7.0);
    return w;
}


Character Wolf::returnWolf() {
    Character w("wolf", 50, 10, 10);
    return w;
}

Character Bear::returnBear() {
    Character b("bear", 75, 20, 10);
    return b;
}

Character Bat::returnBat() {
    Character b("bats", 30, 10, 10);
    return b;
}

Character Skeleton::returnSkeleton() {
    Character s("skeleton", 50, 25, 10);
    return s;
}

Character Boss::returnBoss() {
    Character b("Dire Wolf", 250, 25, 10);
    return b;
}