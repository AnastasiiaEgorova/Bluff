#pragma once
#include "Player.h"
#include <algorithm>

class AIPlayer : public Player
{
public:
					AIPlayer();
	Bid				makeMove(Bid currentBid) override;

private:
	Bid				makeBid(Bid currentBid) override;
	Bid				callBluff() override;

	Dice::Face		topFace;
	int				amountTopFace;
};

