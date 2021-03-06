#pragma once
#include "State.h"
#include "World.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Dice.h"
#include "Board.h"
#include "Button.h"

#include <algorithm>

class GameState : public State
{
public:

					GameState(StateStack& stack, Context context);

	virtual void	draw() override;
	virtual bool	update(sf::Time dt) override;
	virtual bool	handleEvent(const sf::Event& event) override;

private:
	void			updateMousePosition();

	void			initializeButtons(const FontHolder_t& fonts);
	void			updateMousePositionsForButtons();
	void			drawButtons();

	bool			areButtonsPressedToMakeMove();

	void			nextPlayer();
	bool			isValidMove();

	void			play();

private:
	sf::RenderWindow&			window;

	World						world;

	sf::Vector2i				mousePosition;

	std::vector<Player*>		players;
	HumanPlayer&				player;

	Board						board;

	std::unique_ptr<Button>		btnCallBluff;
	std::unique_ptr<Button>		btnMakeMove;

	std::vector<std::unique_ptr<Button>> numberButtons;
	std::vector<std::unique_ptr<Button>> faceButtons;
	//Button*						btnNumber1;
	//Button*						btnNumber2;
	//Button*						btnFace1;
	//Button*						btnFace2;

	

	int							currentPlayer;
	bool						isBluffCalled;
	std::string					errorMessage;

	const int					BLUFF = 0;

};

