#pragma once
#include <vector>
#include <string>
#include "vectors.h"
#include "player.h"

class Room {
public:
	Room(std::vector<std::string> com, std::vector<std::string> f, std::vector<std::string> choices, std::vector<std::string> places, std::string item, const char* in);
	void start(Player& player);
public:
	std::vector<std::string> completed;
	std::vector<std::string> failed;
	std::vector<std::string> choices;
	std::vector<std::string> places;
	std::string item;
	const char* intro;
};

void travel(Player& player, std::vector<std::string> choices);
