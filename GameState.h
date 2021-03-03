#pragma once
#include "State.h"
#include "World.h"
#include "HumanPlayer.h"
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
	World			world;

	//TO BE std::vector<Player>
	HumanPlayer&    player;

	Board			board;
};

