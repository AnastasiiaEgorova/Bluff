#include "GameState.h"
#include "MusicPlayer.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include <algorithm>

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, window(*context.window)
	, world(*context.window, *context.fonts, *context.sounds, *context.opponentPlayers)
	, player(*context.player)
	, currentPlayer(0)
	, board()
	, isBluffCalled(false)
	, errorMessage("")
{
	context.music->play(MusicID::GameTheme);
	
	player.throwDice();
	players.push_back(&player);

	for (int i = 0; i < context.opponentPlayers->size(); ++i) {
		switch (context.opponentPlayers->at(i)) {
		case 0:
			players.push_back(new AIPlayerBrittasaurus(context.opponentPlayers->size() + 1));
			break;
		case 1:
			players.push_back(new AIPlayerDean(context.opponentPlayers->size() + 1));
			break;
		case 2:
			players.push_back(new AIPlayerTroyAndAbed(context.opponentPlayers->size() + 1));
			break;
		}
	}

	player.initializeButtons(*context.fonts);	

	world.drawDice(players.front()->showDice());

	world.moveChip(board.getCurrentBid());
}

void GameState::draw()
{
	world.draw();
	player.drawButtons(&world.getRenderTarget());

	if (isBluffCalled) {
		for (int i = 0; i < players.size()- 1; ++i) {
			world.drawOpponentDice(players[i+1]->showDice(), i);
		}
	}
}

bool GameState::update(sf::Time dt)
{
	if (world.getChipPosition().x == world.getNewChipPosition().x && world.getChipPosition().y == world.getNewChipPosition().y) {

		if (currentPlayer == 0 || world.getOpponent(currentPlayer - 1)->getState() != Actor::State::Think)   // play() possible only when it's human player or opponent in idle state
			play();

		world.updatePlayerAnimationState(currentPlayer);
		world.update(dt);
	}
	else {
		world.moveChip(board.getCurrentBid());
		world.draw();
		player.drawButtons(&world.getRenderTarget());
	}
	
	world.updateCurrentBidText(board.getCurrentBid());
	world.updateErrorMessage(errorMessage);

	updateMousePosition();

	player.updateMousePositionsForButtons(mousePosition);

	return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		requestStackPop();
		requestStackPush(StateID::Menu);
	}

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
		requestStackPush(StateID::Instruction);
		

	return false;
}

void GameState::updateMousePosition()
{
	this->mousePosition = sf::Mouse::getPosition(this->window);
}

void GameState::nextPlayer()
{
	currentPlayer = (currentPlayer + 1) % players.size();
}

void GameState::play()
{
	if (!isBluffCalled) {

		Bid newBid = players[currentPlayer]->makeMove(board.getCurrentBid());

		if (newBid.getNumber() != -1) {
			if (newBid.getNumber() != BLUFF) {

				if (board.isMoveValid(newBid)) {
					board.setCurrentBid(newBid);

					updateMoveForPlayers(currentPlayer, newBid);

					errorMessage = "";
					world.setChipTexture(newBid.getFace());

					world.setChipNewPosition(newBid);
					world.setNewChipAngle(newBid);
					nextPlayer();
				}
				else
					errorMessage = "Invalid move. Please try again";
			}
			else {
				isBluffCalled = true;
				setWinner(getWinner());
			}
			draw();

		}
	}
	else {
		requestStackPush(StateID::GameOver);
	}
}

void GameState::updateMoveForPlayers(int currentPlayer, Bid& bid)
{
	for (int i = 0; i < players.size(); ++i) {
		if (currentPlayer != i) {
			if (dynamic_cast<AIPlayerDean*>(players[i]) != nullptr)
				(dynamic_cast<AIPlayerDean*>(players[i]))->updateInfoForPlayer(bid);
			else if (dynamic_cast<AIPlayerTroyAndAbed*>(players[i]) != nullptr)
				(dynamic_cast<AIPlayerTroyAndAbed*>(players[i]))->updateInfoForPlayer(bid);
		} 
	}
}

std::string GameState::getWinner()
{
	std::vector<Dice> allDice;

	for (auto& p : players) {							// check all dice
		for (auto& d : p->showDice())
			allDice.push_back(d);
	}

	int numberOfFaceOnTable = 0;

	for (auto& d : allDice)
		if (d.getFace() == board.getCurrentBid().getFace() || d.getFace() == Dice::Face::Star)
			numberOfFaceOnTable++;

	bool isCallingBluffWon = true;
	if (board.getCurrentBid().getNumber() <= numberOfFaceOnTable)
		isCallingBluffWon = false;

	int winningPlayer;

	if (isCallingBluffWon) 
		winningPlayer = currentPlayer;
	else
	{
		if (currentPlayer == 0)
			winningPlayer = players.size() - 1;
		else
			winningPlayer = currentPlayer - 1;
	}
		

	std::stringstream stream;
	if (winningPlayer == 0)
		stream << "You";
	else {
		stream << dynamic_cast<AIPlayer*>(players[winningPlayer])->getName();
	}

	return stream.str();
}