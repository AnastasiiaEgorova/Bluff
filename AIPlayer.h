#pragma once
#include "Player.h"

class AIPlayer : public Player
{
public:
					AIPlayer(int opponents);
	//Bid				makeMove(Bid currentBid) override;

protected:
	//Bid				makeBid(Bid currentBid) override;
	Bid				callBluff() override;

protected:
	int				numberOfOpponents;
};

