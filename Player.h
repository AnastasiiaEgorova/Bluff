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
	enum class Action {
		MakeMove,
		CallBluff,
		ActionCount
	};

public:
											Player();
	//void									handleEvent(const sf::Event& event, CommandQueue& commands);

	Bid										makeMove(int numberOfPlayers);
	std::vector<Dice>						showDice();

private:

	Bid										makeBid(int numberOfPlayers);
	Bid										callBluff();

private:
	void									initializeKeyBindings();
	//void									initializeActions();

private:
	//TO DO move to HumanPlayer
	std::map<sf::Keyboard::Key, Action>		keyBindings;
	std::map<Action, Command>				actionBindings;

	std::vector<Dice>						playersDice;
};

