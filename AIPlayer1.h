#pragma once
#include "AIPlayer.h"
#include <algorithm>

class AIPlayer1 : public AIPlayer
{
public:
					AIPlayer1(int n);
	Bid				makeMove(Bid currentBid) override;

private:
	Bid				makeBid(Bid currentBid) override;
	//Bid				callBluff() override;

private:
	Dice::Face		topFace;
	int				amountTopFace;
};

