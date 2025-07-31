#include "MapGenerator.h"
#include "Room.h"
#include <vector>
#include <map>

MapGenerator::MapGenerator() {
    
}

Map* MapGenerator::createMap() {
    std::vector<Room>* rooms = createRooms();
    std::map<int, std::string>* minimapRooms = createMinimapRooms(rooms);
    Map* map = new Map(&rooms->at(0), minimapRooms);

    map->updateCurrentRoom(&rooms->at(0));
    std::string minimap = createMinimap(map->getMinimapRooms());
    map->setMinimap(minimap);
    
    return map;
}

void MapGenerator::updateMinimap(Map* map) {
    std::string minimap = createMinimap(map->getMinimapRooms());
    map->setMinimap(minimap);
}

std::map<int, std::string>* MapGenerator::createMinimapRooms(std::vector<Room>* rooms) {
    std::map<int, std::string>* minimapRooms = new std::map<int, std::string>();

    for (Room &room : *rooms) {
        (*minimapRooms)[room.getId()] = "O";
    }

    return minimapRooms;
}

std::string MapGenerator::createMinimap(std::map<int, std::string>* minimapRooms) {
    std::string OOO = "-";
    std::string UUU = "|";
    std::string nnn = "#";

    std::string x01 = (*minimapRooms)[1];
    std::string x02 = (*minimapRooms)[2];
    std::string x03 = (*minimapRooms)[3];
    std::string x04 = (*minimapRooms)[4];
    std::string x05 = (*minimapRooms)[5];
    std::string x06 = (*minimapRooms)[6];
    std::string x07 = (*minimapRooms)[7];
    std::string x08 = (*minimapRooms)[8];
    std::string x09 = (*minimapRooms)[9];
    std::string x10 = (*minimapRooms)[10];
    std::string x11 = (*minimapRooms)[11];

    std::string minimapRow1 = std::string()  + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + "\n";
    std::string minimapRow2 = std::string()  + nnn + nnn + nnn + nnn + nnn + x11 + nnn + nnn + nnn + nnn + nnn + "\n";
    std::string minimapRow3 = std::string()  + nnn + nnn + nnn + nnn + nnn + UUU + nnn + nnn + nnn + nnn + nnn + "\n";
    std::string minimapRow4 = std::string()  + nnn + nnn + nnn + x09 + OOO + x08 + OOO + x10 + nnn + nnn + nnn + "\n";
    std::string minimapRow5 = std::string()  + nnn + nnn + nnn + nnn + nnn + UUU + nnn + nnn + nnn + nnn + nnn + "\n";
    std::string minimapRow6 = std::string()  + nnn + nnn + nnn + x05 + OOO + x04 + OOO + x06 + OOO + x07 + nnn + "\n";
    std::string minimapRow7 = std::string()  + nnn + nnn + nnn + nnn + nnn + UUU + nnn + nnn + nnn + nnn + nnn + "\n";
    std::string minimapRow8 = std::string() + nnn + x01 + OOO + x02 + OOO + x03 + nnn + nnn + nnn + nnn + nnn + "\n";
    std::string minimapRow9 = std::string() + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + nnn + "\n";

    std::string finalMap = std::string()
    + minimapRow1
    + minimapRow2
    + minimapRow3
    + minimapRow4
    + minimapRow5
    + minimapRow6
    + minimapRow7
    + minimapRow8
    + minimapRow9;

    return finalMap;

}


std::vector<Room>* MapGenerator::createRooms() {
    std::vector<Room>* rooms = new std::vector<Room>();

    // loop that generates 11 rooms without any linked directions
    for (int i = 1; i <= 11; ++i) {
        rooms->emplace_back(i);
    }

    // links all rooms in the vector
    rooms->at(0).setEast(&rooms->at(1));

    rooms->at(1).setWest(&rooms->at(0));
    rooms->at(1).setEast(&rooms->at(2));

    rooms->at(2).setWest(&rooms->at(1));
    rooms->at(2).setNorth(&rooms->at(3));

    rooms->at(3).setWest(&rooms->at(4));
    rooms->at(3).setNorth(&rooms->at(7));
    rooms->at(3).setEast(&rooms->at(5));
    rooms->at(3).setSouth(&rooms->at(2));

    rooms->at(4).setEast(&rooms->at(3));

    rooms->at(5).setWest(&rooms->at(3));
    rooms->at(5).setEast(&rooms->at(6));

    rooms->at(6).setWest(&rooms->at(5));

    rooms->at(7).setWest(&rooms->at(8));
    rooms->at(7).setEast(&rooms->at(9));
    rooms->at(7).setSouth(&rooms->at(3));
    rooms->at(7).setNorth(&rooms->at(10));

    rooms->at(8).setEast(&rooms->at(7));

    rooms->at(9).setWest(&rooms->at(7));

    rooms->at(10).setSouth(&rooms->at(7));

    return rooms;
}
