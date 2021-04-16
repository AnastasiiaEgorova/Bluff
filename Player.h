#pragma once
#include <SFML/Window/Event.hpp>
#include "Command.h"
#include "Dice.h"
#include "Bid.h"
#include <map>

// forward declaration
class CommandQueue;

class Player
{
public:
						Player();
	virtual				~Player() {};

	virtual Bid			makeMove(Bid currentBid) = 0;

	void				throwDice();
	std::vector<Dice>	showDice();

private:
	virtual Bid			makeBid(Bid currentBid) = 0;
	virtual Bid			callBluff() = 0;

protected:
	std::vector<Dice>	playersDice;
};

