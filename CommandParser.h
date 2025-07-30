#pragma once
#include "Room.h"
#include <string>

class CommandParser {
public:
    CommandParser();
    std::string getInput();
    void processMenuCommand();
    void processGameCommand(Room*& room);
    void printRoomExits(Room* room);
    const bool isInMenu() const;
    const bool isInGame() const;
private:
    bool inMenu;
    bool inGame;
};