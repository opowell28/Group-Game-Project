#include <iostream>
#include "Weapons/Weapon.h"
#include "Movement/MoveHandler.h"
#include "Combat/CombatHandler.h"
#include "Player/Player.h"
#include "Character/Character.h"
#include "Character/Enemy.h"
#include "Inventory/Inventory.h"

using namespace std;

int main() {

    Player player1;
    Player* player = &player1;

    player1.setName("Player 1"); //maybe allow user to decide this
    player1.setHealth(100);      //maybe allow this to be determined by previously-selected difficulty mode
    player1.setStrength(50);     //maybe allow this to be determined by previously-selected difficulty mode

    MoveHandler *MoveHdlr;
    MoveHdlr = &MoveHdlr->getInstance();

    CombatHandler *CombatHdlr;
    CombatHdlr = &CombatHdlr->getInstance();

    Weapon *weapon;
//    Enemy *enemy;

    bool gameOver = false;

    MoveHdlr->makeMap(4,9,2,0); //5 by 10 map and player starts at 0,2 (middle of 1st row)
    MoveHdlr->fillWorldWithEnemies(); //fills vector of rooms with enemies
    MoveHdlr->fillRoomsWithItems(); //fills vector of rooms with items and weapons
    weapon->fillWeaponVector(); //fills allWeapons map with every weapon that is defined

    //main game loop
    while(!gameOver) {

        //call function to take directional input
        MoveHdlr->getDirectionInputAndMovePlayer();

        //print out story event for room (story is located at the bottom of MoveHandler.cpp)
        MoveHdlr->RunStoryEvent(MoveHdlr->getX(), MoveHdlr->getY(), CombatHdlr, player);
        /* THIS WILL NOW BE HANDLED IN Movehandler::runstoryevents
        if (MoveHdlr->isThereAnEnemyInRoom(MoveHdlr->getX(), MoveHdlr->getY())) {

            //this starts a combat situation with the specific monster that is in that room
            // according to what is in vector MoveHandler::roomsWithEnemies
            CombatHdlr->inCombat(player1, MoveHdlr->getNameOfEnemyInRoom(MoveHdlr->getX(), MoveHdlr->getY()));
        }
        */
        /*
        if (there is an item to pick up ) {
            //item handler      if we decide to do this
        }
        */

        /*
        if (the game is over (presumably after defeating boss or when players health is zero)) {
            gameOver = true;
        }
        */
    }
    return 0;
}