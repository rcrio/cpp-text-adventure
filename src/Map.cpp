#include "Map.h"

Map::Map(Room* room, std::map<int, std::string>* minimapRooms) {
    this->currentRoom = room;
    this->minimapRooms = minimapRooms;
}

void Map::updateCurrentRoom(Room* room) {
    (*minimapRooms)[currentRoom->getId()] = "O";
    (*minimapRooms)[room->getId()] = "X";
    this->currentRoom = room;
}

Room* Map::getCurrentRoom() {
    return this->currentRoom;
}

std::map<int, std::string>* Map::getMinimapRooms() {
    return this->minimapRooms;
}

std::string Map::getMinimap() {
    return this->minimap;
}

void Map::setMinimap(std::string minimap) {
    this->minimap = minimap;
}