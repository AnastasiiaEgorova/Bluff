#include "AIPlayer.h"

AIPlayer::AIPlayer() : Player() 
{
}

Bid AIPlayer::makeMove(Bid currentBid)
{
	if ((++currentBid).getNumber() > 5)
		return callBluff();
	else
		return makeBid(currentBid);
}

Bid AIPlayer::makeBid(Bid currentBid)
{
	return Bid(++currentBid);
}

Bid	AIPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}