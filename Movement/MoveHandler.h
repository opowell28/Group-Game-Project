//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_MOVEHANDLER_H
#define INC_4_GROUPPROJECT_MOVEHANDLER_H

#include <string>

//TODO: set maxX and maxY, initialize xcoord and ycoord to 0
class MoveHandler {
private:
    int XCoordinate;
    int YCoordinate;
    int maxX;
    int maxY;

public:
    MoveHandler();

    void makeMap(int X, int Y, int startingX, int startingY);

    //functions move player to adjacent rooms
    void movePlayerRight();
    void movePlayerLeft();
    void movePlayerUp();
    void movePlayerDown();

};

//whereas map holds all the rooms, Room class allows
// properties for individual rooms to be set
class Room {
protected:
    std::string roomName = "";
    int xcoordinate;
    int ycoordinate;
    bool isEmpty;
    bool visitedBefore;

public:
    Room(int x, int y, std::string roomName, bool isEmpty, bool visitedBefore);
    //run any events for the room
    void runRoomEvents();
};


#endif //INC_4_GROUPPROJECT_MOVEHANDLER_H