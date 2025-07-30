#pragma once
#include "Room.h"
#include <vector>

class MapGenerator {
public:
    MapGenerator();
    Room*& getCurrentRoom();
private:
    std::vector<Room> rooms;
    Room* startRoom;
};