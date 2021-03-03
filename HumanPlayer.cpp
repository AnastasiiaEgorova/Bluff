#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player()
{
	initializeKeyBindings();
	//initializeActions();
}

void HumanPlayer::initializeKeyBindings()
{   // map from key to action
	keyBindings[sf::Keyboard::M] = Action::MakeMove;
	keyBindings[sf::Keyboard::B] = Action::CallBluff;
}

Bid HumanPlayer::makeMove()
{
	// will do makeBid OR callBluff
	return Bid(2, Dice::Face::Star);
}

Bid HumanPlayer::makeBid()
{
	return Bid(2, Dice::Face::Star);
}

Bid HumanPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}
