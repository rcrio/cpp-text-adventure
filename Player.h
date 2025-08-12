#pragma once
#include <vector>
#include "Item.h"

class Player {
public:
std::vector<Item> getInventory();
void removeItemFromInventory(Item*& item);
void addItemToInventory(Item*& item);

private:
std::vector<Item> inventory;
};