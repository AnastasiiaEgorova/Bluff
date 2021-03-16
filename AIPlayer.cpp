#include "AIPlayer.h"

AIPlayer::AIPlayer(int opponetns) : Player()
{
	numberOfOpponents = opponetns;
}

Bid AIPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}