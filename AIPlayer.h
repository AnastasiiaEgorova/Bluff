#pragma once
#include "Player.h"

class AIPlayer : public Player
{
public:
					AIPlayer();
	Bid				makeMove() override;

private:
	Bid				makeBid() override;
	Bid				callBluff() override;
};

