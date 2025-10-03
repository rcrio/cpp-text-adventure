#pragma once
#include "Room.h"
#include <vector>
#include <map>

class Map {
public:
    Map(Room* room, std::map<int, std::string>* minimapRooms);
    
    Room* getCurrentRoom();
    std::map<int, std::string>* getMinimapRooms();
    std::string getMinimap();
    
    void updateCurrentRoom(Room* room);
    void setMinimap(std::string minimap);

private:
    Room* currentRoom;
    std::vector<Room>* rooms;
    std::map<int, std::string>* minimapRooms; // potentially change map to unordered map
    std::string minimap;
};