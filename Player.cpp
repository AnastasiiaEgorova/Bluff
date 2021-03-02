#include "Player.h"
#include "Commandqueue.h"
#include <algorithm>

Player::Player()
{
	initializeKeyBindings();
	//initializeActions();

	for (int i = 0; i < 5; ++i) {
		playersDice.push_back(Dice());
	}
}

void Player::initializeKeyBindings()
{   // map from key to action
	keyBindings[sf::Keyboard::M] = Action::MakeMove;
	keyBindings[sf::Keyboard::B] = Action::CallBluff;
}

Bid Player::makeMove(int numberOfPlayers)
{
	// will do makeBid OR callBluff
	return Bid(2, Dice::Face::Star);
}

std::vector<Dice> Player::showDice() 
{
	return playersDice;
}

Bid Player::makeBid(int numberOfPlayers) 
{
	return Bid(2, Dice::Face::Star);
}

Bid Player::callBluff()
{
	return Bid(0, Dice::Face::One);
}

