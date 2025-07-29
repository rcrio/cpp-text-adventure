#include "CommandParser.h"
#include <iostream>

CommandParser::CommandParser() : endGame(false) {}

void CommandParser::processCommand() {
    std::getline(std::cin, this->input);

    if (input == "help") {
        std::cout << "help lol" << std::endl;
    }
    else if (input == "go north") {
        std::cout << "help lol 1" << std::endl;
    }
    else if (input == "go south") {
        std::cout << "help lol 2" << std::endl;
    }
    else if (input == "go west") {
        std::cout << "help lol 3" << std::endl;
    }
    else if (input == "go east") {
        std::cout << "help lol 4" << std::endl;
    }
    else if (input == "exit") {
        this->endGame = true;
    }
    else {
            std::cout << "Invalid command, please try again or type and enter 'help' to get a list of commands.";
    }

}

const bool CommandParser::isEndGame() const {
    return this->endGame;
}