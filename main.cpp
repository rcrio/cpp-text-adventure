#include <iostream>
#include <string>

int main() {
    while (true) {
        std::cout << "Hello World!" << std::endl;

        std::cout << "Type and enter: " << std::endl;
        std::cout << "1 to play the game." << std::endl;
        std::cout << "0 to exit the game." << std::endl;

        std::string input = "";

        std::cin >> input;

        if (input == "0") {
            exit(0);
        } 
        else if (input == "1") {
            break;
        }
        else {
            std::cout << "Invalid option, please try again." << std::endl;
        }
    }

    std::cout << "This is where the game is supposed to be. Still coding!" << std::endl;
    char temp;
    std::cin >> temp;
    
    return 0;
};