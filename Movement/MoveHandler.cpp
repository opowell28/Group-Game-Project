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

    //TODO: maybe add more possible inputs so that inputs like 'up' and 'left' work too
    while (!moved) {

        getline(cin, directionInput);

        //Help code to print commands.
        string input, cmd;
        ifstream cmds;
        cmds.open("Commands.txt");

        vector<string> commands;

        //Reads "Commands" text file to add all commands to the vector.
        while(!cmds.eof())
        {
            getline(cmds, cmd);
            commands.push_back(cmd);
        }
        cmds.close();


        //Type "help" to print the "commands" vector.
        getline(cin, input);
        if(input == "help" || input == "Help")
        {
            for(string s : commands)
            {
                cout << s << endl;
            }
        }


        for (int i : directionInput) {

            if ((directionInput[i] == 'n') && (directionInput[i+1] == 'o')
                && (directionInput[i+2] == 'r') && (directionInput[i+3] == 't')
                && (directionInput[i+4] == 'h')) {

                movePlayerUp();
                moved = true;

            } else if ((directionInput[i] == 's') && (directionInput[i+1] == 'o')
                       && (directionInput[i+2] == 'u') && (directionInput[i+3] == 't')
                       && (directionInput[i+4] == 'h')) {

                movePlayerDown();
                moved = true;

            } else if ((directionInput[i] == 'e') && (directionInput[i+1] == 'a')
                       && (directionInput[i+2] == 's') && (directionInput[i+3] == 't')) {

                movePlayerRight();
                moved = true;

            } else if ((directionInput[i] == 'w') && (directionInput[i+1] == 'e')
                       && (directionInput[i+2] == 's') && (directionInput[i+3] == 't')) {

                movePlayerLeft();
                moved = true;

            }

        }

        if (!moved) {
            cin.clear();
            cout << endl << "Invalid input. Please enter a direction: either north, south, east, or west" << endl;
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
    return xcoordinate;
}

int Room::getY() {
    return ycoordinate;
}

string Room::getEnemy() {
    return enemy;
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

void MoveHandler::pickUpItemOrNot(int x, int y, std::string specificStoryString) {
    getline(cin, actionInput);
    if (actionInput == "pick up" || actionInput == "pick it up" || actionInput == "pick up item") {

        flimsyDagger->pickUp();
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
void MoveHandler::RunStoryEvent(int x, int y, CombatHandler *CombatHndlr) {

    //check if visited. If not visited, run the story events. Otherwise you are going back through an empty room so nothing happens
    if (checkIfVisitedBefore(x, y) == false) {

        //   --ROOM BY ROOM STORY EVENTS--
        //TODO: make more if statements like this for every room we want something to happen in

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
            pickUpItemOrNot(1, 0, "You pick up the object in the corner and see that it is a small,"
                            "weak-looking dagger. ");

        } else if ((x == 0) && (y == 0)) {

        } else if ((x == 3) && (y == 0)) {

                cout << "This room has a dirt floor, and is lit only by a small hole in the high ceiling. It appears to be empty. " << endl;

        } else if ((x == 4) && y == 0) {

            cout << "You walk into the next cavern and see a figure which appears to be a wolf in the shadows. "
                    "It hears you, turns around and snarls at you. " << endl;

            getline(cin, actionInput);
            if (actionInput == "fight" || actionInput == "attack" || actionInput == "draw weapon" || "fight wolf" || "attack wolf") {
                   //TODO: create an enemy object and run inCombat here
            }

        } else if ((x == 0) && (y == 1)) {

        }

        addToVisitedVector(x, y);  //add to visited rooms vector now that story events are over

    } else if (checkIfVisitedBefore(x, y) == true){
        //print room-specific message for if you have already been here
        printVisitedMessage(x, y);
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
void MoveHandler::printVisitedMessage(int x, int y) {
    if ((x == 2) && (y == 0)) {
        printStory("This is where you fell down here. You wish "
                   "you could climb back up and escape this place");

    } else if ((x == 1) && (y == 0)) {
        //if this room is in roomsWithWeapons:
        if (weaponInRoom(1, 0)) {
            printStory("You have already been here. The object in the"
                       " corner is still sitting there.");
            //take input if user wants to pick up the object
            pickUpItemOrNot(1, 0, "You pick up the object in the corner and see that it is a small,"
                                  "weak-looking dagger. ");

        } else {
            cout << "You have already been here" << endl;
        }

    } else if ((x == 1) && (y == 0)) {


        //otherwise print the default message below

        //default message for all rooms where there is not something unusual
    } else {
        cout << "You have already been here" << endl;
    }
}
