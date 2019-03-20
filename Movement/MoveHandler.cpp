//
// Created by Owen Powell on 2019-02-18.
//

#include "MoveHandler.h"
#include <iostream>

using namespace std;

//map with variables
//this would be created once at the beginning of the program and it would set where
//the player starts and how many rooms there are in the world. Each coordinate is
//supposed to represent an individual room and from each room you can get to the 4
//adjacent ones unless you are at the edge of the map or we decide to put up special
//barriers in the future
Map::Map(int X, int Y, int startingX, int startingY) {
    this->maxX = X;
    this->maxY = Y;
    this->XCoordinate = startingX;
    this->YCoordinate = startingY;

}

//move player to room to the right by adding 1 to x coordinate
void Map::movePlayerRight() {
    if (this->XCoordinate != this->maxX) {
        this->XCoordinate += 1;
    } else {
        //something
    }
}

//move player to room to the left by subtracting 1 from the x coordinate
void Map::movePlayerLeft() {
    if (this->XCoordinate != 0) {
        this->XCoordinate -= 1;
    } else {
        //something
    }
}

//move player up by adding 1 to y coordinate
void Map::movePlayerUp() {
    if (this->YCoordinate != this->maxY) {
        this->YCoordinate += 1;
    } else {
        //something
    }
}

//move player down by subtracting 1 from the y coordinate
void Map::movePlayerDown() {
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
    this->visitedBefore = visitedBefore;
}

void Room::runRoomEvents() {
    //upon entering a new room, if we want player to fight an enemy,
    // pick up an item, or something else, we could call the necessary
    // functions from here. We could also print out story elements which
    // are connected to certain rooms from here.

    /*TODO: #include movehandler.h to access functions there to call them in the
     * runRoomEvents function. Use ifs to call functions when in a certain room.*/
}