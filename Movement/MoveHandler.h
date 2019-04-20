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
    int xcoordinate = 0;
    int ycoordinate = 0;
    std::string enemy;
    bool isEmpty;
    bool visitedBefore;

public:
    Room(int x, int y, std::string roomName, std::string enemy, bool isEmpty, bool visitedBefore);
    //run any events for the room
    void runRoomEvents();

    std::string getEnemy();
    int getX();
    int getY();
};



//TODO: set maxX and maxY
class MoveHandler {
private:
    MoveHandler();

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
    MoveHandler& getInstance();
    int getX();
    int getY();

    void makeMap(int X, int Y, int startingX, int startingY);

    void getDirectionInputAndMovePlayer(); //handles user input and controls directional movement

    void fillWorldWithEnemies();
    bool isThereAnEnemyInRoom(int x, int y);
    std::string getNameOfEnemyInRoom(int x, int y);

    //functions move player to adjacent rooms
    void movePlayerRight();
    void movePlayerLeft();
    void movePlayerUp();
    void movePlayerDown();


    void RunStoryEvent(int x, int y);
    void addToVisitedVector(int x, int y);
    bool checkIfVisitedBefore(int x, int y);
    void printVisitedMessage(int x, int y);


};


#endif //INC_4_GROUPPROJECT_MOVEHANDLER_H