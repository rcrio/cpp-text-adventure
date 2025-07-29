#pragma once
#include <string>

class CommandParser {
public:
    CommandParser();
    void processCommand();
    const bool isEndGame() const;
private:
    std::string input;
    bool endGame;
};