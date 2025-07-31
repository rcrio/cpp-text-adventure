#pragma once
#include "Room.h"
#include "Map.h"
#include <string>

class CommandParser {
public:
    CommandParser();
    std::string getInput();
    void processMenuCommand();
    void processGameCommand(Map* map);
    void printRoomExits(Room* room);
    const bool isInMenu() const;
    const bool isInGame() const;
private:
    bool inMenu;
    bool inGame;
};