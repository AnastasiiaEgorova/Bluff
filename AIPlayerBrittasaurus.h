#pragma once
#include "AIPlayer.h"
#include <algorithm>

class AIPlayerBrittasaurus : public AIPlayer
{
public:
					AIPlayerBrittasaurus(int n);
	Bid				makeMove(Bid currentBid) override;

private:
	Bid				makeBid(Bid currentBid) override;
	std::string     getName() override;

	Dice::Face		findTopFaceInHand(std::map<Dice::Face, int> &counters);

private:
	Dice::Face		topFace;
	int				amountTopFace;
};

