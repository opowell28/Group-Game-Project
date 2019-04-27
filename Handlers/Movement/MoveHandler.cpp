//
// Created by Owen Powell on 2019-02-18.
//

#include "MoveHandler.h"
//#include "../Combat/CombatHandler.h"
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;


//MoveHandler constructor
MoveHandler::MoveHandler() {}

MoveHandler& MoveHandler::getInstance() {

    static MoveHandler instance;
    return instance;

}

int MoveHandler::getX() {
    return XCoordinate;
}

int MoveHandler::getY() {
    return YCoordinate;
}

//this would be created once at the beginning of the program and it would set where
//the player starts and how many rooms there are in the world. Each coordinate is
//supposed to represent an individual room and from each room you can get to the 4
//adjacent ones unless you are at the edge of the MoveHandler or we decide to put up special
//barriers in the future
void MoveHandler::makeMap(int X, int Y, int startingX, int startingY) {
    this->maxX = X;
    this->maxY = Y;
    this->XCoordinate = startingX;
    this->YCoordinate = startingY;
}

//function takes a line of input and sees if a direction is in it. If so, it moves the player in that direction
//input such as 'move east' will work just as much as 'east'
void MoveHandler::getDirectionInputAndMovePlayer() {

    bool moved = false;
    
    while (!moved) {

        getline(cin, directionInput);

        //Help code to print commands.
        string input, cmd;
        ifstream cmds;
        cmds.open("Commands.txt");

        vector<string> commands;

        //Reads "Commands" text file to add all commands to the vector.
        while (!cmds.eof()) {
            getline(cmds, cmd);
            commands.push_back(cmd);
        }
        cmds.close();

        try {
            //Type "help" to print the "commands" vector.
            getline(cin, input);
            if (input == "help" || input == "Help") {
                for (string s : commands) {
                    cout << s << endl;
                }
            }


            for (int i : directionInput) { //if the first letter is equal to one of these inputs, check if the rest of the word matches a directional input

                if ((directionInput[i] == 'n') && (directionInput[i + 1] == 'o')
                    && (directionInput[i + 2] == 'r') && (directionInput[i + 3] == 't')
                    && (directionInput[i + 4] == 'h')) {

                    movePlayerUp();
                    moved = true;

                } else if ((directionInput[i] == 'f') && (directionInput[i + 1] == 'o')
                           && (directionInput[i + 2] == 'r') && (directionInput[i + 3] == 'w')
                           && (directionInput[i + 4] == 'a') && (directionInput[i + 5] == 'r')
                           && (directionInput[i + 6] == 'd')) {

                    movePlayerUp();
                    moved = true;

                } else if ((directionInput[i] == 'u') && (directionInput[i + 1] == 'p')) {

                    movePlayerUp();
                    moved = true;
                } else if ((directionInput[i] == 's') && (directionInput[i + 1] == 'o')
                           && (directionInput[i + 2] == 'u') && (directionInput[i + 3] == 't')
                           && (directionInput[i + 4] == 'h')) {

                    movePlayerDown();
                    moved = true;

                } else if ((directionInput[i] == 'b') && (directionInput[i + 1] == 'a')
                           && (directionInput[i + 2] == 'c') && (directionInput[i + 3] == 'k')
                           && (directionInput[i + 4] == 'w') && (directionInput[i + 5] == 'a')
                           && (directionInput[i + 6] == 'r') && (directionInput[i + 7] == 'd')) {

                    movePlayerDown();
                    moved = true;

                } else if ((directionInput[i] == 'b') && (directionInput[i + 1] == 'a')
                           && (directionInput[i + 2] == 'c') && (directionInput[i + 3] == 'k')) {

                    movePlayerDown();
                    moved = true;

                } else if ((directionInput[i] == 'd') && (directionInput[i + 1] == 'o')
                           && (directionInput[i + 2] == 'w') && (directionInput[i + 3] == 'n')) {

                    movePlayerDown();
                    moved = true;

                } else if ((directionInput[i] == 'e') && (directionInput[i + 1] == 'a')
                           && (directionInput[i + 2] == 's') && (directionInput[i + 3] == 't')) {

                    movePlayerRight();
                    moved = true;

                } else if ((directionInput[i] == 'r') && (directionInput[i + 1] == 'i')
                           && (directionInput[i + 2] == 'g') && (directionInput[i + 3] == 'h')
                           && (directionInput[i + 4] == 't')) {

                    movePlayerRight();
                    moved = true;

                } else if ((directionInput[i] == 'w') && (directionInput[i + 1] == 'e')
                           && (directionInput[i + 2] == 's') && (directionInput[i + 3] == 't')) {

                    movePlayerLeft();
                    moved = true;

                } else if ((directionInput[i] == 'l') && (directionInput[i + 1] == 'e')
                           && (directionInput[i + 2] == 'f') && (directionInput[i + 3] == 't')) {

                    movePlayerLeft();
                    moved = true;
                } else if ((input == "help") || (input == "Help")) {
                    //Help code to print commands.
                    std::string input, cmd;
                    std::ifstream cmds;
                    cmds.open("Commands.txt");

                    std::vector<std::string> commands;

                    //Reads "Commands" text file to add all commands to the vector.
                    while (!cmds.eof()) {
                        getline(cmds, cmd);
                        commands.push_back(cmd);
                    }
                    cmds.close();

                    for (std::string s : commands) {
                        std::cout << s << std::endl;
                    }
                }
            }
        }

        catch (...) {
            cout << "Please enter a valid movement command. Type 'Help' or 'help' to display a list of commands.";
        }

        if (!moved) {
            cin.clear();
        }
    }
}

//move player to room to the right by adding 1 to x coordinate
void MoveHandler::movePlayerRight() {
    if (this->XCoordinate != this->maxX) {
        this->XCoordinate += 1;
    } else {
        cout << "You can't go this way." << endl;
    }
}

//move player to room to the left by subtracting 1 from the x coordinate
void MoveHandler::movePlayerLeft() {
    if (this->XCoordinate != 0) {
        this->XCoordinate -= 1;
    } else {
        cout << "You can't go this way." << endl;
    }
}

//move player up by adding 1 to y coordinate
void MoveHandler::movePlayerUp() {
    if (this->YCoordinate != this->maxY) {
        this->YCoordinate += 1;
    } else {
        cout << "You can't go this way." << endl;
    }
}

//move player down by subtracting 1 from the y coordinate
void MoveHandler::movePlayerDown() {
    if (this->YCoordinate != 0) {
        this->YCoordinate -= 1;
    } else {
        cout << "You can't go this way." << endl;
    }
}

//function adds a coordinate to vector of rooms that have been visited before
void MoveHandler::addToVisitedVector(int xCoordinate, int yCoordinate) {
    room r;
    r.x = xCoordinate;
    r.y = yCoordinate;
    visitedRooms.push_back(r);
}

//function to see if a room has been visited
bool MoveHandler::checkIfVisitedBefore(int x, int y) {
    if (visitedRooms.empty()) {
        return false;
    }
    for (int i = 0; i <= visitedRooms.size(); i++) {
        if ((visitedRooms[i].x == x) && (visitedRooms[i].y == y)) {
            return true; //return true if it has been visited
        }
    }
    return false;        //return false otherwise
}


void MoveHandler::fillWorldWithEnemies() {
    //repeat these 2 lines for every room containing an enemy, leave an empty string in std::string weaponName for rooms with no weapons
    Room room_0_3(0, 3, "0,3", "slime", "", false, false);
    roomsWithEnemy.push_back(room_0_3);
}

void MoveHandler::fillRoomsWithItems() {
    Room room_2_0(2, 0, "1,0", "", "flimsyDagger", false, false);
    roomsWithItem.push_back(room_2_0);
}

/*
bool MoveHandler::isThereAnEnemyInRoom(int x, int y) {
    for (int i = 0; i <= roomsWithEnemy.size(); i++) {
        for (int j = 0; j <= roomsWithEnemy.size(); j++) {
            if ((XCoordinate == roomsWithEnemy[i].getX()) && (YCoordinate == roomsWithEnemy[i].getY())) {
                return true;
            }
        }
    }
    return false;
}

//returns the name of enemy in specified room
//meant to be run after isThereAnEnemyInRoom
string MoveHandler::getNameOfEnemyInRoom(int x, int y) {
    //find the room with specified coordinates
    for (int i = 0; i <= roomsWithEnemy.size(); i++) {
        if ((roomsWithEnemy[i].getX() == x) && (roomsWithEnemy[i].getY() == y)) {
            //return enemy that is there
            return roomsWithEnemy[i].getEnemy();
        }
    }
    return " ";
}
*/



//room object with variables
Room::Room(int x, int y, string roomName, string enemy, string weapon, bool isEmpty, bool visitedBefore) {
    this->xcoordinate = x;
    this->ycoordinate = y;
    this->roomName = roomName;
    this->enemy = enemy;
    this->isEmpty = isEmpty;
    this->visitedBefore = visitedBefore;
}

int Room::getX() {
    return this->xcoordinate;
}

int Room::getY() {
    return this->ycoordinate;
}


//function splits string into different rows so it can be read easier and words are not split when printed
void MoveHandler::printStory(string story) {
    int counter = 0;
    for (int i = 0; i <= story.size(); i++) {
        cout << story[i];
        counter++;
        if ((story[i] == ' ') && (counter >= 40)) {
            cout << endl;
            counter = 0;
        }
    }
    cout << endl;
}

void MoveHandler::pickUpItemOrNot(int x, int y, std::string weaponName, std::string specificStoryString, Character *player) {
    getline(cin, actionInput);
    if (actionInput == "pick up" || actionInput == "pick it up" || actionInput == "pick up item") {

        if (weaponName == "flimsyDagger") {
            Dagger D;
            player->playerInventory.push_back(D.returnDagger());
        } else if (weaponName == "weakSword") {
            Sword S;
            player->playerInventory.push_back(S.returnSword());
        } else if (weaponName == "axe") {
            Axe A;
            player->playerInventory.push_back(A.returnAxe());
        } else if (weaponName == "crossbow") {
            Crossbow B;
            player->playerInventory.push_back(B.returnBow());
        }

        printStory(specificStoryString);

        for (int i = 0; i <= roomsWithItem.size(); i++) {
            if ((roomsWithItem[i].getX() == x) && (roomsWithItem[i].getY() == y)) {
                roomsWithItem[i].isEmpty = true;
            }
        }

        //remove the room from the vector of rooms with items
        //roomsWithItem.erase(remove(roomsWithItem.begin(), roomsWithItem.end(), Room room_2_0), roomsWithItem.end());
    }
}

//function contains list of story events for each room coordinate that has a story event
void MoveHandler::RunStoryEvent(int x, int y, CombatHandler *CombatHndlr, Character *player, bool gameOver) {

    gameOver = false;
    //default message prints in all rooms other than starting room
    if (!((x == 2) && (y == 0))) {
        cout << "You are in room: " << x << " " << y << endl;
    }

    //check if visited. If not visited, run the story events. Otherwise you are going back through an empty room so nothing happens
    if (checkIfVisitedBefore(x, y) == false) {

        //   --ROOM BY ROOM STORY EVENTS--

        //the story begins here
        if ((x == 2) && (y == 0)) {

            printStory("You wake up and rub a bruise on your head. You appear to"
                       " have fallen deep underground. You cannot see where you "
                       "fell from, but you can see that you are in a small cavern,"
                       " illuminated by torchlight. There is an opening in front "
                       "of you leading somewhere else, and one to your left and "
                       "right as well. ");

        } else if ((x == 1) && (y == 0)) {

            printStory("This room is the same as the last one. It is empty except "
                       "for a small object in the corner. ");

            //take input if user wants to pick up the object
            pickUpItemOrNot(1, 0, "flimsyDagger", "You pick up the object in the corner and see that it is a small,"
                                  "weak-looking dagger. ", player);

        } else if ((x == 3) && (y == 0)) {

            printStory("This room has a dirt floor, and is lit only by a small hole in the high ceiling. It appears to be empty. ");

        } else if ((x == 4) && y == 0) {

            printStory("You walk into the next cavern and see a figure, which appears to be a wolf, in the shadows. "
                       "It hears you, turns around and snarls at you. What do you do?");

            getline(cin, actionInput);
            if (actionInput == "fight" || actionInput == "attack" || actionInput == "draw weapon" || "fight wolf" || "attack wolf") {
                CombatHndlr->inCombat(*player, "wolf", gameOver);
            } else {
                movePlayerLeft();
                cout << "You ran away. You are now in room 3 0" << endl;
            }

        } else if ((x == 0) && (y == 0)) {
            printStory("This room has only one exit besides the one you came through.");

        } else if ((x == 0) && (y == 1)) {
            printStory("You walk into the next cavern and see a huge bear. It sees you and starts to come toward you, but not very quickly. What do you do?");

            getline(cin, actionInput);
            if (actionInput == "fight" || actionInput == "attack" || actionInput == "draw weapon" || "fight bear" || "attack bear") {
                CombatHndlr->inCombat(*player, "bear", gameOver);
            } else {
                movePlayerLeft();
                cout << "You ran away. You are now in room 1 1" << endl;
            }

        } else if ((x == 3) && (y == 1)) {
            printStory("This room is empty except for an axe leaning against the wall. ");
            pickUpItemOrNot(3, 1, "axe", "You pick up the axe.", player);

        } else if ((x == 2) && (y == 2)) {
            printStory("This room has a dirt floor, and is lit only by a small hole in the high ceiling. It appears to be empty, but as you start walking, man-eating bats pour from the hole in the ceiling. You cannot get away in time.");
            CombatHndlr->inCombat(*player, "bats", gameOver);

        } else if ((x == 4) && (y == 2)) {
            printStory("This room is empty except for a sword lying on the floor.");

        } else if ((x == 1) && (y == 3)) {

        } else if ((x == 3) && (y == 3)) {
            printStory("You walk into the next cavern and see a large wolf. It sees you immediately and starts growling. What do you do?");

            getline(cin, actionInput);
            if (actionInput == "fight" || actionInput == "attack" || actionInput == "draw weapon" || "fight wolf" || "attack wolf") {
                CombatHndlr->inCombat(*player, "wolf", gameOver);
            } else {
                movePlayerLeft();
                cout << "You ran away. You are now in room 2 3" << endl;
            }
        } else if ((x == 1) && (y == 3)) {
            printStory("This room is empty except for an axe leaning against the wall. ");
            pickUpItemOrNot(1, 3, "axe", "You pick up the axe.", player);

        } else if ((x == 0) && (y == 3)) {
            printStory("As you walk into the next room you feel a tug on your foot. You immediately notice that it is a tripwire, and your skin begins to sting as dozens of tiny darts pierce you. You take 10 damage.");
            player->setHealth(player->getHealth() - 15);

        } else if ((x == 0) && (y == 4)) {
            printStory("This cavern is dark. When you begin to walk into it, a skeleton emerges from the darkness and attacks you.");
            CombatHndlr->inCombat(*player, "skeleton", gameOver);
        } else if ((x == 2) && (y == 4)) {
            printStory("This cavern is dark. When you begin to walk into it, a skeleton emerges from the darkness and attacks you.");
            CombatHndlr->inCombat(*player, "skeleton", gameOver);
        } else if ((x == 4) && (y == 4)) {
            printStory("Upon enterring this room, you notice a strange smell and begin to feel light headed. You quickly leave the room, but not before taking 15 damage. You are now in room 3 4");
            player->setHealth(player->getHealth() - 15);
            movePlayerLeft();

        } else if ((x == 1) && (y == 5)) {
            printStory("You walk into the next cavern and see a huge bear. It sees you and starts to come toward you, but not very quickly. What do you do?");

            getline(cin, actionInput);
            if (actionInput == "fight" || actionInput == "attack" || actionInput == "draw weapon" || "fight bear" || "attack bear") {
                CombatHndlr->inCombat(*player, "bear", gameOver);
            } else {
                movePlayerRight();
                cout << "You ran away. You are now in room 2 5" << endl;
            }

        } else if ((x == 4) && (y == 5)) {
            printStory("This room is empty except for a sword lying on the floor.");
            pickUpItemOrNot(4, 5, "weakSword", "You pick up the sword.", player);

        } else if ((x == 3) && (y == 6)) {
            printStory("In the corner of this room there is a spring of cold water. You drink it and gain 30hp.");
            player->setHealth(player->getHealth() + 30);

        } else if ((x == 4) && (y == 6)) {
            printStory("This room has a dirt floor, and is lit only by a small hole in the high ceiling. It appears to be empty, but as you start walking, man-eating bats pour from the hole in the ceiling. You cannot get away in time.");
            CombatHndlr->inCombat(*player, "bats", gameOver);

        } else if ((x == 0) && (y == 6)) {
            printStory("This room is empty except for a crossbow leaning against the wall.");
            pickUpItemOrNot(0, 6, "crossBow", "You pick up the crossbow.", player);

        } else if ((x == 1) && (y == 7)) {
            printStory("You walk into the next cavern and see a huge bear. It sees you and starts to come toward you, but not very quickly. What do you do?");

            getline(cin, actionInput);
            if (actionInput == "fight" || actionInput == "attack" || actionInput == "draw weapon" || "fight bear" || "attack bear") {
                CombatHndlr->inCombat(*player, "bear", gameOver);
            } else {
                movePlayerLeft();
                cout << "You ran away. You are now in room 0 7" << endl;
            }
        } else if ((x == 4) && (y == 7)) {
            printStory("As you walk into the next room you feel a tug on your foot. You immediately notice that it is a tripwire, and your skin begins to sting as dozens of tiny darts pierce you. You take 10 damage.");
            player->setHealth(player->getHealth() - 15);

        } else if ((x == 3) && (y == 8)) {
            printStory("This cavern is dark. When you begin to walk into it, a skeleton emerges from the darkness and attacks you.");
            CombatHndlr->inCombat(*player, "skeleton", gameOver);

        } else if ((x == 0) && (y == 8)) {
            printStory("Upon entering this room, you notice a strange smell and begin to feel light headed. You quickly leave the room, but not before taking 15 damage. You are now in room 3 4");
            player->setHealth(player->getHealth() - 15);
            movePlayerLeft();

        } else if ((x == 0) && (y == 9)) {
            printStory("You cannot go forward anymore, but you can see faint light coming from your left.");
        } else if ((x == 1) && (y == 9)) {
            printStory("You see light coming through the opening to your right. You can also hear something moving around in there. Something big.");
        } else if ((x == 2) && (y == 9)) {   //BOSS ROOM
            printStory(" ");
            CombatHndlr->inCombat(*player, "boss", gameOver);
            if (player->getHealth() > 0) {
                gameOver = true;
                printStory("end");
            }

        } else if ((x == 3) && (y == 9)) {
            printStory("You see light coming through the opening to your left. You can also hear something moving around in there. Something big.");
        } else if ((x == 4) && (y == 9)) {
            printStory("You cannot go forward anymore, but you can see faint light coming from your right.");
        } else {
            cout << "There is nothing interesting about this room." << endl;
        }

        addToVisitedVector(x, y);  //add to visited rooms vector now that story events are over

    } else if (checkIfVisitedBefore(x, y) == true){
        //print room-specific message for if you have already been here
        printVisitedMessage(x, y, player);
    }
}

//return true if there is a weapon in the room with the specified coordinates
bool MoveHandler::weaponInRoom(int x, int y) {
    for (int i = 0; i <= roomsWithItem.size(); i++) {
        if ((roomsWithItem[i].getX() == x) && (roomsWithItem[i].getY() == y)) {
            if (roomsWithItem[i].isEmpty == false) {
                return true;
            }
        }
    }
    return false;
}

//function takes room coordinates and prints appropriate visited-before message
void MoveHandler::printVisitedMessage(int x, int y, Character *player) {
    if ((x == 2) && (y == 0)) {
        printStory("This is where you fell down here. You wish "
                   "you could climb back up and escape this place");

    } else if ((x == 1) && (y == 0)) {
        //if this room is in roomsWithWeapons:
        if (weaponInRoom(1, 0)) {
            printStory("You have already been here. The object in the"
                       " corner is still sitting there.");
            //take input if user wants to pick up the object
            pickUpItemOrNot(1, 0, "flimsyDagger", "You pick up the object in the corner and see that it is a small,"
                                                  "weak-looking dagger. ", player);

        } else {
            cout << "You have already been here" << endl;
        }

            //otherwise print the default message below

            //default message for all rooms where there is not something unusual
    } else {
            cout << "You have already been here" << endl;
    }

}
