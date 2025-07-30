#pragma once
#include "Room.h"
#include <string>

class CommandParser {
public:
    CommandParser(Room* room);
    void processCommand();
    void printRoomExits();
    const bool isEndGame() const;
private:
    std::string input;
    bool endGame;
    Room* room;
};