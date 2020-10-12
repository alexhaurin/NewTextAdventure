#include "rooms.h"
#include "rooms.h"

Room::Room(std::vector<std::string> com, std::vector<std::string> f, std::vector<std::string> ch, std::vector<std::string> p, std::string it, const char* in) {
    completed = com;
    failed = f;
    choices = ch;
	places = p;
    item = it;
	intro = in;
}

std::vector<std::string> com1 = {
	"You search under the floor and find a box with a set of keys - these might be useful later.",
	"You open up the closet and find a box with a set of keys in it - these might be useful later.",
	"You ligft up the wooden bed frame and find a box with a set of keys under it- these might be useful later.",
};
std::vector<std::string> f1 = {
	"You open up a floorboard just as a gaurd passes by, who notices the disturbance and enters the house.",
	"You open up the closet door, waking up a person sleeping upstairs, who alerts the guards, capturing you.",
	"You lift up the bed frame, which is heavier than it looked, making you drop it and creating a large bang throughout the house. A guard outside notices and decideds to check the distburbance and enters the house.",
};
std::vector<std::string> c1 = { "floor", "closet", "bed" };
std::vector<std::string> p1 = { "alleys", "tower" };
std::string it1 = "keys";
const char* in1 = "There might be something in here - enter places you would like to search or enter travel to go somewhere else.";
Room house(com1, f1, c1, p1, it1, in1);

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



std::vector<std::string> com4 = {
	"You wait quietly inside of tower as the guards pass you.",
	"You sprint out the door, the guards notice you, but are too slow and you escape!",
	"You walk out of the tower - confidence is key - the guards hardly bat an eye at your presence as you calmly walk past.",

};
std::vector<std::string> f4 = {
	"You wait quietly inside of tower as the guards pass you - but something falls out of your pocket creating a large sound! The guards notice and enter the tower, capturing you.",
	"You sprint out the door, the guards notice you and start to follow closely behind - but as you look behind at them you trip on a rock and the guards capture you!",
	"You walk out of the tower - confidence is key - but one of the guards is suspicious of you and asks who you are. You stutter and try to run away but the guards are too close and capture you!",
};
std::vector<std::string> c4 = { "hide", "run", "fake" };
std::vector<std::string> p4 = { "house", "catacombs" };
std::string it4 = "wand";
const char* in4 = "You use your keys to quietly unlock the door, and inside you find a mysterious looking stick - this might be useful later. Before leaving, you peek out the door and see a group of guards patrolling the outside area. What do you do? {hide, run, fake";
Room tower(com4, f4, c4, p4, it4, in4);





void travel(Player& player, std::vector<std::string> choices) {
    std::string input;

    std::cout << "Where do you go next?:" << std::endl;
    std::getline(std::cin, input);

    while (!vectors::findItem(choices, input)) {
        std::cout << "Pick a valid option:" << std::endl;
        vectors::print(choices);
        std::getline(std::cin, input);
    }

    if (input == "walls") {
        walls.start(player);
    }
    else if (input == "alleys") {
        alleys.start(player);
    }
    else if (input == "tower") {
		std::vector<std::string> choices = { "house", "catacombs" };
		std::vector<std::string> choices2 = { "yes", "no" };
		std::string keys = "keys";
		std::string input2;
		std::cout << "You make your way into the tower and find a closed door. You try to open it but find that it is locked. Do you keep trying to open it? {yes, no}:" << std::endl;
		std::getline(std::cin, input2);

		while (!vectors::findItem(choices2, input2)) {
			std::cout << "Pick a valid option" << std::endl;
			std::getline(std::cin, input2);
		}

		if (input2 == "no") {
			travel(player, choices);
		}
		else {
			if (vectors::findItem(player.items, keys)) {
				tower.start(player);
			}
			else {
				player.caught("You slam yourself into the door, attempting to break it. You crash through creating a loud sound that alerts the nearby guards, who run up and capture you!");
			}
		}
    }
    else if (input == "room") {
        house.start(player);
    }
	else if (input == "catacombs") {
		std::vector<std::string> choices = { "alleys", "walls" };
		std::vector<std::string> choices2 = { "yes", "no" };
		std::string potion = "potion";
		std::string wand = "wand";
		std::string input2;
		std::cout << "Congratulations! You have succesfully esca - wait, you see something in the distance. All you can make out is its large figure, so you walk closer to get a better look. Its a dragon! It's still asleep, so you can come back later if you're not ready. Do you keep going> {yes, no}:" << std::endl;
		std::getline(std::cin, input2);
		while (!vectors::findItem(choices2, input2)) {
			std::cout << "Pick a valid option" << std::endl;
			std::getline(std::cin, input2);
		}

		if (input2 == "no") {
			travel(player, choices);
		}
		else {
			if ((vectors::findItem(player.items, potion)) || (vectors::findItem(player.items, wand))) {
				player.catacombs();
			}
			else {
				player.caught("You slowly approach the dragon, considering what to do. Having no useful items, you try to sneak past the dragon in its sleep. Hugging the wall, you get closer and closer to the dragon, but it smells you! The dragon wakes up, angrily, and swats you away into the wall.");
			}
		}
	}
}



void Room::start(Player& player) {
	std::string input;
	std::cout << intro << std::endl;
	std::getline(std::cin, input);

	while (!vectors::findItem(choices, input)) {
		std::cout << "test" << std::endl;
		std::cout << "Pick a valid option:" << std::endl;
		vectors::print(choices);
		std::getline(std::cin, input);
	}

	player.level += 0.2;

	player.challenge(completed, failed, input, choices, 3);

	travel(player, places);
}
