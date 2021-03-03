#include "AIPlayer.h"

AIPlayer::AIPlayer() : Player() 
{
}

Bid AIPlayer::makeMove()
{
	// will do makeBid OR callBluff
	return Bid(2, Dice::Face::Star);
}

Bid AIPlayer::makeBid()
{
	return Bid(2, Dice::Face::Star);
}

Bid	AIPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}