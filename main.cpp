#include <iostream>
#include "Weapons/Weapon.h"
#include "Movement/MoveHandler.h"
#include "Combat/CombatHandler.h"
#include "Player/Player.h"

using namespace std;


int main() {

    MoveHandler MoveHdlr;
    CombatSituation CombatHdlr;
    bool gameOver = false;
    //player; //create a player object using the pointer to player1 in CombatHandler

    MoveHdlr.makeMap(5,10,2,0); //5 by 10 map and player starts at 0,2 (middle of 1st row)
    MoveHdlr.fillWorldWithEnemies(); //fills vector of rooms with enemies

    //main game loop
    while(!gameOver) {
        //print out story event for room (story is located at the bottom of MoveHandler.cpp)
        MoveHdlr.RunStoryEvent(MoveHdlr.getX(), MoveHdlr.getY());

        //call function to take directional input
        MoveHdlr.getDirectionInputAndMovePlayer();

        if (MoveHdlr.isThereAnEnemyInRoom(MoveHdlr.getX(), MoveHdlr.getY())) {

            //this needs to be able to start a combat situation with the specific monster that is in that room
            // according to what is in vector MoveHandler::roomsWithEnemies
            CombatHdlr.inCombat(/* MoveHdlr.getNameOfEnemyInRoom(MoveHdlr.getX(), MoveHdlr.getY()) */); //suggestion for possible implementation
        }

        /*
        if (there is an item to pick up ) {
            //item handler      if we decide to do this
        }
        */

        /*
        if (the game is over (presumably after defeating boss)) {
            gameOver = true;
        }
        */
    }
    return 0;
}