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

	world.drawDice(players.front()->showDice());
}

void GameState::draw()
{
	world.draw();
}

bool GameState::update(sf::Time dt)
{
	world.update(dt);
	world.updateCurrentBidText(board.getCurrentBid());
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

void GameState::getNextPlayer()
{
	currentPlayer = (currentPlayer + 1) % players.size();
}

bool GameState::isValidMove()
{
	return true;
}