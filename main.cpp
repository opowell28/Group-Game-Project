#include <iostream>
#include "Handlers/Movement/MoveHandler.h"
#include "Handlers/Combat/CombatHandler.h"
#include "Classes.h"

using namespace std;

int main() {

    Character player1;
    Character* player = &player1;

    player1.setName("Player 1"); //maybe allow user to decide this
    player1.setHealth(100);      //maybe allow this to be determined by previously-selected difficulty mode
    player1.setStrength(50);     //maybe allow this to be determined by previously-selected difficulty mode

    MoveHandler *MoveHdlr;
    MoveHdlr = &MoveHdlr->getInstance();

    CombatHandler *CombatHdlr;
    CombatHdlr = &CombatHdlr->getInstance();

    Weapon *weapon;

    bool gameOver = false;

    MoveHdlr->makeMap(4,9,2,0); //5 by 10 map and player starts at 0,2 (middle of 1st row)
    MoveHdlr->fillWorldWithEnemies(); //fills vector of rooms with enemies
    MoveHdlr->fillRoomsWithItems(); //fills vector of rooms with items and weapons

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