#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	enum class Action {
		MakeMove,
		CallBluff,
		ActionCount
	};

public:
											HumanPlayer();
	//void									handleEvent(const sf::Event& event, CommandQueue& commands);

	void									initializeKeyBindings();
	//void									initializeActions();

	Bid										makeMove(int numberOfPlayers);// override;

private:
	Bid										makeBid(int numberOfPlayers);// override;
	Bid										callBluff();// override;

private:
	//TO DO move to HumanPlayer
	std::map<sf::Keyboard::Key, Action>		keyBindings;
	std::map<Action, Command>				actionBindings;
};

