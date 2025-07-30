#include <iostream>
#include <string>
#include "CommandParser.h"
#include "MapGenerator.h"

int main() {
    // Starting menu loop
    while (true) {
        std::cout << "===========================================\n";
        std::cout << "Welcome to rcrio's C++ Text Adventure game\n";
        std::cout << "===========================================\n\n";

        std::cout << "===========================================\n";
        std::cout << "Type and enter: " << std::endl;
        std::cout << "1 to play the game" << std::endl;
        std::cout << "0 to exit the game" << std::endl;
        std::cout << "===========================================\n\n";

        std::string input = "";

        std::cout << "Your input: ";
        std::getline(std::cin, input);

        if (input == "0") {
            exit(0);
        } 
        else if (input == "1") {
            break;
        }
        else {
            std::cout << "\nInvalid option, please try again." << std::endl;
        }
    }

    MapGenerator mapGenerator;
    CommandParser commandParser(mapGenerator.getStartRoom());
    std::cout << "\nWelcome to the game. Please type and enter a command to proceed. Type and enter 'help' for a list of commmands.\n" << std::endl;
    // Game loop
    while (true) {
        commandParser.processCommand();
        if (commandParser.isEndGame()) {
            break;
        }
    }
    
    return 0;
};