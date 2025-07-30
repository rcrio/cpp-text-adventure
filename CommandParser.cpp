#include "CommandParser.h"
#include "Room.h"
#include <iostream>

CommandParser::CommandParser(Room* room) : room(room), endGame(false) {}

void CommandParser::printRoomExits() {
    std::cout << "You are currently in room " << room->getId() << ".\n";
    if (room->getNorth() != nullptr) {
        std::cout << "There is a way north. ";
    }
    if (room->getSouth() != nullptr) {
        std::cout << "There is a way south. ";
    }
    if (room->getWest() != nullptr) {
        std::cout << "There is a way west. ";
    }
    if (room->getEast() != nullptr) {
        std::cout << "There is a way east. ";
    }
    std::cout << "\n\n";
}

void CommandParser::processCommand() {
    printRoomExits();
    std::cout << "Your input: ";
    std::getline(std::cin, this->input);
    std::cout << "\n";
    if (input == "help") {
        std::cout << "Nothing here at the moment...\n";
    }
    else if (input == "go north") {
        if (room->getNorth() != nullptr) {
            room = room->getNorth();
            std::cout << "You moved north.\n";
        } else {
            std::cout << "You can't go north. It's a wall.\n";
        }
    }
    else if (input == "go south") {
        if (room->getSouth() != nullptr) {
            room = room->getSouth();
            std::cout << "You moved south.\n";
        } else {
            std::cout << "You can't go south. It's a wall.\n";
        }
    }
    else if (input == "go west") {
        if (room->getWest() != nullptr) {
            room = room->getWest();
            std::cout << "You moved west.\n";
        } else {
            std::cout << "You can't go west. It's a wall.\n";
        }
    }
    else if (input == "go east") {
        if (room->getEast() != nullptr) {
            room = room->getEast();
            std::cout << "You moved east.\n";
        } else {
            std::cout << "You can't go east. It's a wall.\n";
        }
    }
    else if (input == "exit") {
        this->endGame = true;
    }
    else {
            std::cout << "\nInvalid command, please try again or type and enter 'help' to get a list of commands.\n\n";
    }
}

const bool CommandParser::isEndGame() const {
    return this->endGame;
}