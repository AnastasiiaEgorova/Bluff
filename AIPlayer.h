#pragma once
#include "Player.h"

class AIPlayer : public Player
{
public:
							AIPlayer(int opponents);
	virtual std::string		getName() = 0;

protected:
	Bid						callBluff() override;

protected:
	int						numberOfPlayers;
};

