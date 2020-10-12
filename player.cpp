#include "vectors.h"
#include "rooms.h"
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

void Player::catacombs() {
    std::vector<std::string> choices{ "run", "sneak", "fight" };
    std::string input;

    std::cout << "How do you get past the dragon? {run, sneak, fight}:" << std::endl;
    std::getline(std::cin, input);

    while (vectors::findItem(choices, input)) {
        std::cout << "Enter a valid option" << std::endl;
        std::getline(std::cin, input);
    }

    if (input == choices[0]) {
        caught("You try to run past but the dragon awakens and blocks your path. You attempt to run back but you are not fast enough and you are killed by the dragon.");
    }
    else if (input == choices[1]) {
        caught("You crouch and began to slowly make your way up to the dragon, hugging the wall. But the dragon smells you in its sleep. You try to run back but you are not fast enough and are killed by the dragon.");
    }
    else {
        fightDragon();
    }
}

void Player::fightDragon() {
    std::string input;

    std::cout << "You decide to fight the dragon." << std::endl;
    std::cout << "What do you use?" << std::endl;
    vectors::print(items);

    std::getline(std::cin, input);
    while (vectors::findItem(items, input)) {
        std::cout << "You don't have that" << std::endl;
        std::getline(std::cin, input);
    }

    if (input == "wand") {
        win("You wip out your magic wand and blast the dragon with a magical beam, transforming it into a frog. You walk past the it as it croaks angrily at you, escaping through the catacombs");
    }
    else {
        win("You drink the mysterious potion and begin to see yourself slowly disappearing. You walk pass the dragon with ease, and escape through the catacombs.");
    }
}

void Player::challenge(std::vector<std::string> completed, std::vector<std::string> failed, std::string task, std::vector<std::string> choices, unsigned int dif) {
    if (task == choices[0]) {
        if (attributes["stealth"] >= dif + level) {
            caught(failed[0]);
        }
        else {
            std::cout << completed[0] << std::endl;
        }
    }
    else if (task == choices[1]) {
        if (attributes["speed"] >= dif + level) {
            caught(failed[1]);
        }
        else {
            std::cout << completed[1] << std::endl;
        }
    }
    else if (task == choices[2]) {
        if (attributes["luck"] >= dif + level) {
            caught(failed[2]);
        }
        else {
            std::cout << completed[2] << std::endl;
        }
     }
}

void Player::caught(std::string message) {
    std::cout << message << std::endl;
    std::cout << "You lose :(" << std::endl;
}

void Player::win(const char* message) {
    std::string input;

    std::cout << "Congratulations! You win!" << std::endl;
    std::cout << "Would you like to play again?" << std::endl;
    std::getline(std::cin, input);
}
