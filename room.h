#pragma once
#include <vector>
#include "item.h"

class Room {
    // Room uses ptrs as nullptr rooms indicate dead-ends.
public:
    Room(int id, Room* north, Room* south, Room* west, Room* east);
    int getId() const;
    const Room* getNorth() const;
    const Room* getSouth() const;
    const Room* getWest() const;
    const Room* getEast() const;
    const std::vector<Item>& getItems() const;

private:
    int id;
    Room* north;
    Room* south;
    Room* west;
    Room* east;
    std::vector<Item> items;
};