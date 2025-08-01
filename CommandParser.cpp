#include "CommandParser.h"
#include "Room.h"
#include <iostream>

CommandParser::CommandParser() : inGame(false), inMenu(true) {}

std::string CommandParser::getInput() {
    std::string input = "";
    std::cout << "\nYour input: ";
    std::getline(std::cin, input);
    std::cout << "\n";
    return input;
}

void CommandParser::printRoomExits(Room* room) {
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
    std::cout << "\n";
}

void CommandParser::processMenuCommand() {
    std::cout << "Type and enter: " << std::endl;
    std::cout << "1 to play the game" << std::endl;
    std::cout << "0 to exit the game" << std::endl;

    std::string input = getInput();

    if (input == "0") {
        exit(0);
    } 
    else if (input == "1") {
        this->inGame = true;
        this->inMenu = false;
    }
    else {
        std::cout << "\nInvalid option, please try again." << std::endl;
    }
}

void CommandParser::processGameCommand(Map* map) {
    Room* room = map->getCurrentRoom();
    printRoomExits(room);

    std::string input = getInput();

    if (input == "help") {
        std::cout << "Objective: No objectives currently in the game. Feel free to move about.\n";
        std::cout << "Type a command and press enter to execute the command. Commands: \n";
        std::cout << "go north: Move north if there is an exit north.\n";
        std::cout << "go south: Move south if there is an exit south.\n";
        std::cout << "go west: Move west if there is an exit west.\n";
        std::cout << "go east: Move east if there is an exit east.\n";
        std::cout << "exit: Go back to the main menu.\n";
    }
    else if (input == "go north") {
        if (room->getNorth() != nullptr) {
            map->updateCurrentRoom(room->getNorth());
            std::cout << "You moved north.\n";
        } else {
            std::cout << "You can't go north. It's a wall.\n";
        }
    }
    else if (input == "go south") {
        if (room->getSouth() != nullptr) {
            map->updateCurrentRoom(room->getSouth());
            std::cout << "You moved south.\n";
        } else {
            std::cout << "You can't go south. It's a wall.\n";
        }
    }
    else if (input == "go west") {
        if (room->getWest() != nullptr) {
            map->updateCurrentRoom(room->getWest());
            std::cout << "You moved west.\n";
        } else {
            std::cout << "You can't go west. It's a wall.\n";
        }
    }
    else if (input == "go east") {
        if (room->getEast() != nullptr) {
            map->updateCurrentRoom(room->getEast());
            std::cout << "You moved east.\n";
        } else {
            std::cout << "You can't go east. It's a wall.\n";
        }
    }
    else if (input == "exit") {
        this->inMenu = true;
        this->inGame = false;
    }
    else {
            std::cout << "Invalid command, please try again or type and enter 'help' to get a list of commands.\n\n";
    }
}

const bool CommandParser::isInMenu() const {
    return this->inMenu;
}

const bool CommandParser::isInGame() const {
    return this->inGame;
}