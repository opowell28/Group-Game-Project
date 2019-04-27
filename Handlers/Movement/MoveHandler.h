//
// Created by Owen Powell on 2019-02-18.
//

#ifndef INC_4_GROUPPROJECT_MOVEHANDLER_H
#define INC_4_GROUPPROJECT_MOVEHANDLER_H

#include <string>
#include <vector>
#include "../Combat/CombatHandler.h"
#include "../../Classes.h"

//Room class allows properties for individual rooms to be set
class Room : virtual public Weapon {

protected:
    std::string roomName = "";
    int xcoordinate = 0;
    int ycoordinate = 0;
    std::string enemy;
    bool visitedBefore;
    std::string weaponName;

public:
    bool isEmpty;

    Room(int x, int y, std::string roomName, std::string enemy, std::string weaponName, bool isEmpty, bool visitedBefore);
    int getX();
    int getY();

};

class MoveHandler : virtual public Weapon {
private:
    MoveHandler();

    int XCoordinate;
    int YCoordinate;
    int maxX;
    int maxY;
    std::string directionInput; //stores user input for direction
    std::string actionInput; //gets input for actions other than moving
    struct room {
        int x;
        int y;
    };
    std::vector<Room> roomsWithEnemy;
    std::vector<Room> roomsWithItem;
    std::vector<room> visitedRooms;

public:
    MoveHandler& getInstance();
    int getX();
    int getY();

    void makeMap(int X, int Y, int startingX, int startingY);

    void getDirectionInputAndMovePlayer(); //handles user input and controls directional movement

    void fillWorldWithEnemies();
    void fillRoomsWithItems();
    bool isThereAnEnemyInRoom(int x, int y);
    std::string getNameOfEnemyInRoom(int x, int y);

    //functions move player to adjacent rooms
    void movePlayerRight();
    void movePlayerLeft();
    void movePlayerUp();
    void movePlayerDown();


    void printStory(std::string story);
    void RunStoryEvent(int x, int y, CombatHandler *CombatHndlr, Character *player, bool gameOver);
    void addToVisitedVector(int x, int y);
    bool checkIfVisitedBefore(int x, int y);
    bool weaponInRoom(int x, int y);
    void pickUpItemOrNot(int x, int y, std::string weaponName, std::string specificStoryString, Character *player);
    void printVisitedMessage(int x, int y, Character *player);


};


#endif //INC_4_GROUPPROJECT_MOVEHANDLER_H