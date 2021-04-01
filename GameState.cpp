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
	//TO DO
	//context.music->play(MusicID::MissionTheme);

	players.push_back(&player);

	for (int i = 0; i < context.opponentPlayers->size(); ++i) {
		switch (i) {
		case 0:
			players.push_back(new AIPlayer1(context.opponentPlayers->size() + 1));
			break;
		case 1:
			players.push_back(new AIPlayer2(context.opponentPlayers->size() + 1));
			break;
		case 2:
			players.push_back(new AIPlayer3(context.opponentPlayers->size() + 1));
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
			world.drawOpponentDice(players[i]->showDice(), i);
		}
	}

	if (currentPlayer != 0 && !isBluffCalled)
		world.drawSandTimer(currentPlayer);
}

bool GameState::update(sf::Time dt)
{
	if (world.getChipPosition().x == world.getNewChipPosition().x && world.getChipPosition().y == world.getNewChipPosition().y)
		play();
	else {
		world.moveChip(board.getCurrentBid());
		world.draw();
		player.drawButtons(&world.getRenderTarget());
	}

	world.updatePlayerAnimationState(currentPlayer);
	world.update(dt);
	
	world.updateCurrentBidText(board.getCurrentBid());
	world.updateErrorMessage(errorMessage);

	updateMousePosition();

	player.updateMousePositionsForButtons(mousePosition);

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

					//TO DO change later
					//if (currentPlayer != 0)
					//	std::this_thread::sleep_for(std::chrono::seconds(1));

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
		std::this_thread::sleep_for(std::chrono::seconds(1));
		requestStackPush(StateID::GameOver);
	}
}

void GameState::updateMoveForPlayers(int currentPlayer, Bid& bid)
{
	for (int i = 0; i < players.size(); ++i) {
		if (currentPlayer != i) {
			if (dynamic_cast<AIPlayer2*>(players[i]) != nullptr)
				(dynamic_cast<AIPlayer2*>(players[i]))->updateInfoForPlayer(bid);
			else if (dynamic_cast<AIPlayer3*>(players[i]) != nullptr)
				(dynamic_cast<AIPlayer3*>(players[i]))->updateInfoForPlayer(bid);
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
	//for (auto d : players[0]->showDice())
	//	allDice.push_back(d);

	//for (auto d : players[1]->showDice())
	//	allDice.push_back(d);

	int numberOfFaceOnTable = 0;

	for (auto& d : allDice)
		if (d.getFace() == board.getCurrentBid().getFace() || d.getFace() == Dice::Face::Star)
			numberOfFaceOnTable++;

	bool isCallingBluffWon = true;
	if (board.getCurrentBid().getNumber() <= numberOfFaceOnTable)
		isCallingBluffWon = false;

	std::stringstream stream;

	if (isCallingBluffWon)
		stream << currentPlayer;
	else
		stream << currentPlayer - 1;

	return stream.str();

	//if ((currentPlayer == 0 && isCallingBluffWon) || (currentPlayer != 0 && !isCallingBluffWon))
	//	player.setStatus(HumanPlayer::Status::Success);
	//else
	//	player.setStatus(HumanPlayer::Status::Failure);
}