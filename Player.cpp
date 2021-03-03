#include "Player.h"
#include "Commandqueue.h"
#include <algorithm>

Player::Player()
{
	for (int i = 0; i < 5; ++i) {
		playersDice.push_back(Dice());
	}
}

std::vector<Dice> Player::showDice() 
{
	return playersDice;
}

