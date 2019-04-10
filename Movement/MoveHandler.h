//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_MOVEHANDLER_H
#define INC_4_GROUPPROJECT_MOVEHANDLER_H

#include <string>
#include <vector>

//Room class allows properties for individual rooms to be set
class Room {
protected:
    std::string roomName = "";
    int xcoordinate;
    int ycoordinate;
    std::string enemy;
    bool isEmpty;
    bool visitedBefore;

public:
    Room(int x, int y, std::string roomName, std::string enemy, bool isEmpty, bool visitedBefore);
    //run any events for the room
    void runRoomEvents();
    int getX();
    int getY();
};



//TODO: set maxX and maxY, initialize xcoord and ycoord to 0
class MoveHandler {
private:
    int XCoordinate;
    int YCoordinate;
    int maxX;
    int maxY;
    std::string directionInput; //gets user input for direction
    struct room {
        int x;
        int y;
    };
    std::vector<Room> roomsWithEnemy;
    std::vector<room> visitedRooms;

public:
    MoveHandler();
    int getX();
    int getY();

    void makeMap(int X, int Y, int startingX, int startingY);

    void getDirectionInputAndMovePlayer(); //handles user input and controls directional movement

    void fillWorldWithEnemies();
    bool isThereAnEnemyInRoom(int x, int y);

    //functions move player to adjacent rooms
    void movePlayerRight();
    void movePlayerLeft();
    void movePlayerUp();
    void movePlayerDown();


    void RunStoryEvent(int x, int y);
    void addToVisitedVector(int x, int y);
    bool checkIfVisitedBefore(int x, int y);

};


#endif //INC_4_GROUPPROJECT_MOVEHANDLER_H