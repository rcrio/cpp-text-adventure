#include "MapGenerator.h"
#include "Room.h"

MapGenerator::MapGenerator() : rooms() {
    // loop that generates 11 rooms without any linked directions
    for (int i = 1; i <= 11; ++i) {
        rooms.emplace_back(i);
    }

    this->rooms[0].setEast(&this->rooms[1]);

    this->rooms[1].setWest(&this->rooms[0]);
    this->rooms[1].setEast(&this->rooms[2]);

    this->rooms[2].setWest(&this->rooms[1]);
    this->rooms[2].setNorth(&this->rooms[3]);

    this->rooms[3].setWest(&this->rooms[4]);
    this->rooms[3].setNorth(&this->rooms[7]);
    this->rooms[3].setEast(&this->rooms[5]);
    this->rooms[3].setSouth(&this->rooms[2]);

    this->rooms[4].setEast(&this->rooms[3]);

    this->rooms[5].setWest(&this->rooms[3]);
    this->rooms[5].setEast(&this->rooms[6]);

    this->rooms[6].setWest(&this->rooms[5]);

    this->rooms[7].setWest(&this->rooms[8]);
    this->rooms[7].setEast(&this->rooms[9]);
    this->rooms[7].setSouth(&this->rooms[3]);
    this->rooms[7].setNorth(&this->rooms[10]);

    this->rooms[8].setEast(&this->rooms[7]);

    this->rooms[9].setWest(&this->rooms[7]);

    this->rooms[10].setSouth(&this->rooms[7]);

    this->startRoom = &this->rooms[0];
}

Room*& MapGenerator::getCurrentRoom() {
    return this->startRoom;
}