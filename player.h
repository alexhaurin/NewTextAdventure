#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>

class Player {
public:
	void getAttribute(const char* att);
	bool challenge(const char* task, unsigned int dif);
	void caught(const char* message);

public:
	std::vector<std::string> items;
	unsigned int totalPoints = 10;
	unsigned int level = 0;

	std::map<const char*, unsigned int> attributes = {
		{ "stealth", 0 },
		{ "luck", 0 },
		{ "speed", 0 }
	};
};
