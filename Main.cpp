#include <iostream>
#include <string>
#include "CommandParser.h"
#include "MapGenerator.h"

int main() {
    CommandParser commandParser;
    MapGenerator MapGenerator;
    Room* room = MapGenerator.getCurrentRoom();

    std::cout << "===========================================\n";
    std::cout << "Welcome to rcrio's C++ Text Adventure game\n";
    std::cout << "===========================================\n\n";

    // Main game loop
    while (true) {
        if (commandParser.isInMenu()) {
            commandParser.processMenuCommand();
        }
        if (commandParser.isInGame()) {
            commandParser.processGameCommand(room);
        }
        if (!commandParser.isInGame() && !commandParser.isInMenu()) {
            break;
        }
    }

    
    return 0;
};