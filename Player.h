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

	//virtual Bid			makeMove(int numberOfPlayers) = 0;
	std::vector<Dice>	showDice();

private:
	//virtual Bid			makeBid(int numberOfPlayers) = 0;
	//virtual Bid			callBluff() = 0;

protected:
	std::vector<Dice>	playersDice;
};

