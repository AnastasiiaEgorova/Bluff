#pragma once
#include "State.h"
#include "World.h"
#include "HumanPlayer.h"
#include "AIPlayer1.h"
#include "Dice.h"
#include "Board.h"
#include "Button.h"

#include <algorithm>
#include <chrono>
#include <thread>

class GameState : public State
{
public:

					GameState(StateStack& stack, Context context);

	virtual void	draw() override;
	virtual bool	update(sf::Time dt) override;
	virtual bool	handleEvent(const sf::Event& event) override;

private:
	void			updateMousePosition();

	void			nextPlayer();
	bool			isValidMove();

	void			setIsHumanPlayerWon();

	void			play();

private:
	sf::RenderWindow&			window;

	World						world;

	sf::Vector2i				mousePosition;

	std::vector<Player*>		players;
	HumanPlayer&				player;

	Board						board;

	int							currentPlayer;
	bool						isBluffCalled;
	std::string					errorMessage;

	const int					BLUFF = 0;

};

