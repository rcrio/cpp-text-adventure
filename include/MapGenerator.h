#pragma once
#include "Room.h"
#include "Map.h"
#include <vector>

class MapGenerator {
public:
    MapGenerator();
    std::vector<Room>* createRooms();
    Map* createMap();
    std::map<int, std::string>* createMinimapRooms(std::vector<Room>* rooms);
    std::string createMinimap(std::map<int, std::string>* minimapRooms);

    void updateMinimap(Map* map);
    
private:
};