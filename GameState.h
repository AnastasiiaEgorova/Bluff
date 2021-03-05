#pragma once
#include "State.h"
#include "World.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Dice.h"
#include "Board.h"
#include "Button.h"

class GameState : public State
{
public:

					GameState(StateStack& stack, Context context);

	virtual void	draw() override;
	virtual bool	update(sf::Time dt) override;
	virtual bool	handleEvent(const sf::Event& event) override;

	void			updateMousePosition();

private:
	void			nextPlayer();
	bool			isValidMove();

	void			play();

private:
	sf::RenderWindow& window;

	World			world;

	//sf::Vector2i	mousePosScreen;
	sf::Vector2i	mousePosition;

	std::vector<Player*> players;
	HumanPlayer& player;

	Board			board;

	Button*			btnCallBluff;

	int				currentPlayer;
	bool			isBluffCalled;
	std::string		errorMessage;

	const int		BLUFF = 0;

};

