#pragma once
#include "State.h"
#include "World.h"
#include "Player.h"
#include "Dice.h"

class GameState : public State
{
public:

					GameState(StateStack& stack, Context context);

	virtual void	draw() override;
	virtual bool	update(sf::Time dt) override;
	virtual bool	handleEvent(const sf::Event& event) override;

private:
	World			world;

	//TO BE std::vactor<Player>
	Player&			player;

	std::vector<Dice> playingDice;

	
};

