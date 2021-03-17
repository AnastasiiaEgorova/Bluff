#pragma once
#include "Player.h"

class AIPlayer : public Player
{
public:
					AIPlayer(int opponents);

protected:
	Bid				callBluff() override;

protected:
	int				numberOfOpponents;
};

