#include "Dice.h"

std::mt19937 Dice::rEng{
	std::random_device{}()
};

Dice::Dice() {
	face = rollDice();
}

Dice::Face Dice::rollDice() {

	auto roll = dist(Dice::rEng);

	switch (roll) {
		case 1:
			return Face::One;
		case 2:
			return Face::Two;
		case 3:
			return Face::Three;
		case 4:
			return Face::Four;
		case 5:
			return Face::Five;
		default:
			return Face::Star;
	}
}