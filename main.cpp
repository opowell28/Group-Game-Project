#include <iostream>
#include "Handlers/Movement/MoveHandler.h"
#include "Handlers/Combat/CombatHandler.h"
#include "Classes.h"

using namespace std;



int main() {

    //test Test(1,2);
    //Character player2();

    Character player1("Player 1", 100, 50, 10, " ");
    Character* player = &player1;
    std::cout << "test";

    /*
    player1.setName("Player 1");
    player1.setHealth(100);      
    player1.setStrength(50);
*/
    MoveHandler *MoveHdlr;
    MoveHdlr = &MoveHdlr->getInstance();

    CombatHandler *CombatHdlr;
    CombatHdlr = &CombatHdlr->getInstance();

    bool gameOver = false;

    MoveHdlr->makeMap(4,9,2,0); //5 by 10 map and player starts at 0,2 (middle of 1st row)
    MoveHdlr->fillWorldWithEnemies(); //fills vector of rooms with enemies
    MoveHdlr->fillRoomsWithItems(); //fills vector of rooms with items and weapons

    //main game loop
    while(!gameOver) {

        //call function to take directional input
        MoveHdlr->getDirectionInputAndMovePlayer();

        //print out story event for room
        MoveHdlr->RunStoryEvent(MoveHdlr->getX(), MoveHdlr->getY(), CombatHdlr, player, gameOver);
        /* THIS WILL NOW BE HANDLED IN Movehandler::runstoryevents
        if (MoveHdlr->isThereAnEnemyInRoom(MoveHdlr->getX(), MoveHdlr->getY())) {

            //this starts a combat situation with the specific monster that is in that room
            // according to what is in vector MoveHandler::roomsWithEnemies
            CombatHdlr->inCombat(player1, MoveHdlr->getNameOfEnemyInRoom(MoveHdlr->getX(), MoveHdlr->getY()));
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
