#pragma once
#include "State.h"
#include "World.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Dice.h"
#include "Board.h"

class GameState : public State
{
public:

					GameState(StateStack& stack, Context context);

	virtual void	draw() override;
	virtual bool	update(sf::Time dt) override;
	virtual bool	handleEvent(const sf::Event& event) override;

private:
	void			nextPlayer();
	//bool			isBluffCalled();
	bool			isValidMove();

	void			play();

private:
	World			world;

	std::vector<Player*> players;
	HumanPlayer& player;

	Board			board;

	int				currentPlayer;
	bool			isBluffCalled;
	std::string		errorMessage;

	const int		BLUFF = 0;
};

