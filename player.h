#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>

class Player {
public:
	void getAttribute(const char* att);
	void challenge(std::vector<std::string> completed, std::vector<std::string> failed, std::string task, std::vector<std::string> choices, unsigned int dif);
	void catacombs();
	void fightDragon();
	void caught(std::string message);
	void win(const char* message);

public:
	std::vector<std::string> items = { "_" };
	unsigned int totalPoints = 10;
	double level = 0.0;

	std::map<std::string, unsigned int> attributes = {
		{ "stealth", 0 },
		{ "luck", 0 },
		{ "speed", 0 }
	};
};
