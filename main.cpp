#include <iostream>
#include <string>
#include "CommandParser.h"

int main() {
    // Starting menu loop
    while (true) {
        std::cout << "Hello World!" << std::endl;

        std::cout << "Type and enter: " << std::endl;
        std::cout << "1 to play the game." << std::endl;
        std::cout << "0 to exit the game." << std::endl;

        std::string input = "";

        std::getline(std::cin, input);

        if (input == "0") {
            exit(0);
        } 
        else if (input == "1") {
            break;
        }
        else {
            std::cout << "Invalid option, please try again." << std::endl;
        }
    }

    std::cout << "Welcome to the game. Please type and enter a command to proceed. Type and enter 'help' for a list of commmands.\n" << std::endl;

    // Game loop
    while (true) {
        CommandParser commandParser;
        commandParser.processCommand();
        if (commandParser.isEndGame()) {
            break;
        }
    }
    
    return 0;
};