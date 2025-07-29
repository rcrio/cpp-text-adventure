#include "CommandParser.h"
#include "Room.h"
#include <iostream>

CommandParser::CommandParser(Room* room) : room(room), endGame(false) {}

void CommandParser::processCommand() {
    std::getline(std::cin, this->input);

    if (input == "help") {
        std::cout << "help lol" << std::endl;
    }
    else if (input == "go north") {
        if (room->getNorth() != nullptr) {
            room = room->getNorth();
            std::cout << "You moved south. You are now in room " << room->getId() << "." << std::endl;
        } else {
            std::cout << "You can't go north. It's a wall." << std::endl;
        }
    }
    else if (input == "go south") {
        if (room->getSouth() != nullptr) {
            room = room->getSouth();
            std::cout << "You moved south. You are now in room " << room->getId() << "." << std::endl;
        } else {
            std::cout << "You can't go south. It's a wall." << std::endl;
        }
    }
    else if (input == "go west") {
        if (room->getWest() != nullptr) {
            room = room->getWest();
            std::cout << "You moved west. You are now in room " << room->getId() << "." << std::endl;
        } else {
            std::cout << "You can't go west. It's a wall." << std::endl;
        }
    }
    else if (input == "go east") {
        if (room->getEast() != nullptr) {
            room = room->getEast();
            std::cout << "You moved east. You are now in room " << room->getId() << "." << std::endl;
        } else {
            std::cout << "You can't go east. It's a wall." << std::endl;
        }
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