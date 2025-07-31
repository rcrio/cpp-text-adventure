#include <iostream>
#include <string>
#include "CommandParser.h"
#include "MapGenerator.h"
#include "Map.h"

int main() {
    CommandParser commandParser;
    MapGenerator mapGenerator;
    Map* map = mapGenerator.createMap();
    Room* currentRoom = map->getCurrentRoom();


    std::cout << "===========================================\n";
    std::cout << "Welcome to rcrio's C++ Text Adventure game\n";
    std::cout << "===========================================\n\n";

    // Main game loop
    while (true) {
        if (commandParser.isInMenu()) {
            commandParser.processMenuCommand();
        }
        if (commandParser.isInGame()) {
            mapGenerator.updateMinimap(map);
            std::cout << map->getMinimap();
            commandParser.processGameCommand(map);
        }
        if (!commandParser.isInGame() && !commandParser.isInMenu()) {
            break;
        }
    }

    
    return 0;
};