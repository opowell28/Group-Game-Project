#include <iostream>
#include "Weapons/Weapon.h"
#include "Movement/MoveHandler.h"
#include "Combat/CombatHandler.h"
#include "Player/Player.h"

using namespace std;


int main() {

    MoveHandler MoveHdlr;
    CombatSituation CombatHdlr;

    MoveHdlr.makeMap(5,10,0,2); //5 by 10 map and player starts at 0,2 (middle of 1st row)

    int playerXLocation = 2;
    int playerYLocation = 0;

    //main game loop
    while(true) {
        MoveHdlr.RunStoryEvent(playerXLocation, playerYLocation);

        //call function to take directional input
        MoveHdlr.getDirectionInputAndMovePlayer();
        if (enemyInRoom) {
            CombatHdlr.inCombat();
        } else if (itemInRoom) {
            //item handler
        }
    }
    return 0;
}