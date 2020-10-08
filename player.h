#pragma once
#include <string>
#include <map>

class Player {
public:
	void getAttribute(const char* att);

public:
	std::vector<std::string> items;

	unsigned int totalPoints = 10;
	unsigned int difficulty = 0;
	std::map<const char*, unsigned int> attributes = {
		{ "stealth", 0 },
		{ "luck", 0 },
		{ "speed", 0 }
	};
};