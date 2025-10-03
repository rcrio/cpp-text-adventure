#pragma once
#include <vector>
#include "Item.h"

class Room {
    // Room uses ptrs as nullptr rooms indicate dead-ends.
public:
    Room(int id);
    Room(int id, Room* north, Room* south, Room* west, Room* east);

    int getId() const;
    Room* getNorth() const;
    Room* getSouth() const;
    Room* getWest() const;
    Room* getEast() const;
    void setNorth(Room* room);
    void setSouth(Room* room);
    void setWest(Room* room);
    void setEast(Room* room);
    const std::vector<Item>& getItems() const;
    // probably need methods to add or remove items here

private:
    int id;
    Room* north;
    Room* south;
    Room* west;
    Room* east;
    std::vector<Item> items;
};