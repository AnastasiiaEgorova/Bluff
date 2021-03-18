#include "AIPlayer.h"

AIPlayer::AIPlayer(int players) : Player()
{
	numberOfPlayers = players;
}

Bid AIPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}
