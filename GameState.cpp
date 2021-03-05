#include "GameState.h"
#include "MusicPlayer.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include <algorithm>

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, world(*context.window, *context.fonts, *context.sounds)
	, player(*context.player)
	, currentPlayer(0)
	, board()
	, isBluffCalled(false)
{
	//TO DO
	//context.music->play(MusicID::MissionTheme);

	players.push_back(&player);
	players.push_back(new AIPlayer());

	btnCallBluff = new Button(10.f, 10.f, 100.f, 50.f, *context.fonts, "Call Bluff");

	world.drawDice(players.front()->showDice());
}

void GameState::draw()
{
	world.draw();
	btnCallBluff->render(&world.getRenderTarget());
}

bool GameState::update(sf::Time dt)
{
	world.update(dt);
	world.updateCurrentBidText(board.getCurrentBid());

	play();

	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	CommandQueue& commands = world.getCommands();
	//player.handleEvent(event, commands);

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		requestStackPush(StateID::Pause);

	return false;
}

void GameState::nextPlayer()
{
	currentPlayer = (currentPlayer + 1) % players.size();
}

bool GameState::isValidMove()
{
	return true;
}

void GameState::play()
{
	if (!isBluffCalled) {

		//if (currentPlayer == 0)
		//	handleEvent();
		//else 
			Bid newBid = players[currentPlayer]->makeMove();

		if (newBid.getNumber() != BLUFF) {

			if (board.isMoveValid(newBid)) {
				board.setCurrentBid(newBid);
				nextPlayer();
			}
			else
				errorMessage = "Invalid move. Please try again";
		}
		else
			isBluffCalled = true;

		draw();
	}
}