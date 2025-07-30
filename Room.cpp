#include "Room.h"
#include "Item.h"
#include <vector>

Room::Room(int id) : id(id), north(nullptr), south(nullptr), west(nullptr), east(nullptr), items() {}

Room::Room(int id, Room* north, Room* south, Room* west, Room* east) : id(id), north(north), south(south), west(west), east(east), items() {}

// getters

Room* Room::getNorth() const {
    return this->north;
}

Room* Room::getSouth() const {
    return this->south;
}

Room* Room::getWest() const {
    return this->west;
}

Room* Room::getEast() const {
    return this->east;
}

const std::vector<Item>& Room::getItems() const {
    return this->items;
}

int Room::getId() const {
    return this->id;
}

// setters

void Room::setNorth(Room* room) {
    this->north = room;
}

void Room::setSouth(Room* room) {
    this->south = room;
}

void Room::setWest(Room* room) {
    this->west = room;
}

void Room::setEast(Room* room) {
    this->east = room;
}


