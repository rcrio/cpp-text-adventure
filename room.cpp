#include "Room.h"
#include "Item.h"
#include <vector>


Room::Room(int id, Room* north, Room* south, Room* west, Room* east) : id(id), north(north), south(south), west(west), east(east) {}

const Room* Room::getNorth() const {
    return this->north;
}

const Room* Room::getSouth() const {
    return this->south;
}

const Room* Room::getWest() const {
    return this->west;
}

const Room* Room::getEast() const {
    return this->east;
}
const std::vector<Item>& Room::getItems() const {
    return this->items;
}
