//
// Created by Owen Powell on 2019-02-18.
//

#include "MoveHandler.h"
//include CombatHandler.h
#include "../Combat/CombatHandler.h"
#include <iostream>

using namespace std;


//MoveHandler constructor
MoveHandler::MoveHandler() {}

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

        for (int i : directionInput) {

            if ((directionInput[i] == 'n') && (directionInput[i+1] == 'o')
            && (directionInput[i+2] == 'r') && (directionInput[i+3] == 't')
            && (directionInput[i+4] == 't')) {

                movePlayerUp();
                moved = true;

            } else if ((directionInput[i] == 's') && (directionInput[i+1] == 'o')
            && (directionInput[i+2] == 'u') && (directionInput[i+3] == 't')
            && (directionInput[i+4] == 't')) {

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
        //something
    }
}

//move player to room to the left by subtracting 1 from the x coordinate
void MoveHandler::movePlayerLeft() {
    if (this->XCoordinate != 0) {
        this->XCoordinate -= 1;
    } else {
        //something
    }
}

//move player up by adding 1 to y coordinate
void MoveHandler::movePlayerUp() {
    if (this->YCoordinate != this->maxY) {
        this->YCoordinate += 1;
    } else {
        //something
    }
}

//move player down by subtracting 1 from the y coordinate
void MoveHandler::movePlayerDown() {
    if (this->YCoordinate != 0) {
        this->YCoordinate -= 1;
    } else {
        //something
    }
}

//room object with variables
Room::Room(int x, int y, string roomName, bool isEmpty, bool visitedBefore) {
    this->xcoordinate = x;
    this->ycoordinate = y;
    this->roomName = roomName;
    this->isEmpty = isEmpty;
    this->visitedBefore = visitedBefore;
}

void Room::runRoomEvents() {
    //upon entering a new room, if we want player to fight an enemy,
    // pick up an item, or something else, we could call the necessary
    // functions from here. We could also print out story elements which
    // are connected to certain rooms from here.


    if (isEmpty == false && visitedBefore == false) {
        if(xcoordinate > 0 && ycoordinate > 0) {
            visitedBefore = true;
            //call other functions here
        }
    }
    else if(isEmpty == true) {
        cout << "This room is empty" << endl;
    }
    else if(visitedBefore == true) {
        cout << "You have already visited this room" << endl;
    }
}