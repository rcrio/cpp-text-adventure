#include "item.h"
#include <string>

Item::Item(std::string name) : name(name) {}

const std::string Item::getName() const {
    return this->name;
}