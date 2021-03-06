#pragma once
#include "Player.h"

class AIPlayer : public Player
{
public:
					AIPlayer();
	Bid				makeMove(Bid currentBid) override;

private:
	Bid				makeBid(Bid currentBid) override;
	Bid				callBluff() override;
};

