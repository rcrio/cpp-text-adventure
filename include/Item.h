#pragma once
#include <string>

class Item {
public:
    Item(std::string name);
    const std::string getName() const;
private:
    std::string name;
};