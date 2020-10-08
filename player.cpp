#include <iostream>
#include <string>
#include <vector>
#include "vectors.h"
#include "player.h"


void Player::getAttribute(const char* att) {
    std::string input;
    unsigned int points;

	std::cout << "How many points will you add to your " << att << " attribute?:";

    while (true) {
        std::getline(std::cin, input);
        try {
            points = std::stoi(input);
        }
        catch (std::invalid_argument) {
            print("Enter a number.");
            continue;
        }

        if (points > totalPoints) {
            print("You don't have enough points");
            continue;
        }
        else {
            totalPoints -= points;
            break;
        }
    }

    attributes[att] = points;
}