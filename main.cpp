#include <iostream>
#include "vectors.h"
#include "player.h"
#include "rooms.h"

int main() {
	std::vector<std::string> choices{ "walls", "alleys" };
	std::string input;

	Player player;





	std::vector<std::string> com2 = {
		"You began to crawl past the guard, who you find asleep and succesfully make it past him without eveninterupting his nap. You made it past the guards!On your way out you see a mysterious potion and pick it up - this might be useful later",
		"You sprint past the guard who you find asleep, and just as he wakes up you round the corner and he loses you. You made it past the guards!On your way out you see a mysterious potion and pick it up - this might be useful later",
		"You start cutting the ladder just as you hear guards running to follow behind you, and succesfully cut, just as they were about to reach the top. You made it past the guards!On your way out you see a mysterious potion and pick it up - this might be useful later"
	};
	std::vector<std::string> f2 = {
		"As you tried sneaking, you stepped on a dried leaf and were heard by a guard, who captures you.",
		"As you ran past the guard hurried behind you, but you were not fast enough so he caught up and captured you!",
		"You reach for your knife to cut the ladder - but you dropped while escaping the castle! The guards catch up to you."
	};
	std::vector<std::string> c2 = { "hide", "run", "cutladder" };
	std::vector<std::string> p2 = { "tower", "house" };
	std::string it2 = "potion";
	const char* in2 = "Patrolling the wall, you see two more guards on top of the castle walls.How will you get past them? {hide, run, cutladder}:";
	Room walls(com2, f2, c2, p2, it2, in2);


	std::vector<std::string> com3 = {
	"Nice! you succsefully snuck past the guard.",
	"Nice!you succsefully ran past the guard, but now you're being followed - better act fast.",
	"You slip into a shadowy corner just as the guard walks by, escaping him."
	};
	std::vector<std::string> f3 = {
		"You stepped on a dry leaf, alerting the guard who turns around and captures you.",
		"As you ran past the guard hurried behind you, but you were not fast enough so he caught up and captured you!"
		"You try to slip into a corner, but a civlian notices you and alerts the guards."
	};
	std::vector<std::string> c3 = { "sneak", "run", "hide" };
	std::vector<std::string> p3 = { "tower", "walls" };
	std::string it3 = "_";
	const char* in3 = "You see a guard patrolling the front of the alley. He seems alert - you need to get past him. How do you do it? {sneak, run}:";
	Room alleys(com3, f3, c3, p3, it3, in3);


	player.getAttribute("stealth");
	player.getAttribute("luck");
	player.getAttribute("speed");


	std::cout << "Congratulations! You have succesfully stolen the king's precious crown. \n\
Just one tiny thing left to do - escape past all of the king's guards while avoiding countless traps and deadends. \n\
But first you need to choose your attributes. But your better hurry, I think i can hear the guards coming now... \n\
You spring out of the king's chambers and find yourself outside of the castle, where do you try your luck exscaping? {walls, alleys}:" << std::endl;
	/*std::getline(std::cin, input);

	while (!vectors::findItem(choices, input)) {	
		std::cout << "Pick a valid option" << std::endl;
		std::getline(std::cin, input);
	}

	if (input == choices[0]) {
		walls.start(player);
	}
	else {
		alleys.start(player);
	}*/

	walls.start(player);
}
