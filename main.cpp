#include <iostream>
#include "Handlers/Movement/MoveHandler.h"
#include "Handlers/Combat/CombatHandler.h"
#include "Classes.h"

using namespace std;



int main() {

    //create player and pointer
    Character player1("Player", 100, 50, 10, " ");
    Character* player = &player1;

    //move handler singleton
    MoveHandler *MoveHdlr;
    MoveHdlr = &MoveHdlr->getInstance();

    //combat handler singleton
    CombatHandler *CombatHdlr;
    CombatHdlr = &CombatHdlr->getInstance();

    //boolean for whether or not game is over
    bool gameOver = false;

    MoveHdlr->makeMap(4,9,2,0);       //5 by 10 map and player starts at 0,2 (middle of 1st row)
    MoveHdlr->fillWorldWithEnemies(); //fills vector of rooms with enemies
    MoveHdlr->fillRoomsWithItems();   //fills vector of rooms with items and weapons

    //main game loop
    while(!gameOver) {

        //run story events for room
        MoveHdlr->RunStoryEvent(MoveHdlr->getX(), MoveHdlr->getY(), CombatHdlr, player, gameOver);

        //call function to take directional input
        MoveHdlr->getDirectionInputAndMovePlayer();

        /* NOT USED
        if (MoveHdlr->isThereAnEnemyInRoom(MoveHdlr->getX(), MoveHdlr->getY())) {

            //this starts a combat situation with the specific monster that is in that room
            // according to what is in vector MoveHandler::roomsWithEnemies
            CombatHdlr->inCombat(player1, MoveHdlr->getNameOfEnemyInRoom(MoveHdlr->getX(), MoveHdlr->getY()));
        }
        */

    }
    std::cout << "GAME OVER";

    return 0;
}
