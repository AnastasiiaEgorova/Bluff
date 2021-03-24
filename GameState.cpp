#include "GameState.h"
#include "MusicPlayer.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include <algorithm>

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, window(*context.window)
	, world(*context.window, *context.fonts, *context.sounds)
	, player(*context.player)
	, currentPlayer(0)
	, board()
	, isBluffCalled(false)
	, errorMessage("")
{
	//TO DO
	//context.music->play(MusicID::MissionTheme);

	players.push_back(&player);
	players.push_back(new AIPlayer1(3));
	players.push_back(new AIPlayer3(3));

	player.initializeButtons(*context.fonts);	

	world.drawDice(players.front()->showDice());

	world.moveChip(board.getCurrentBid());
}

void GameState::draw()
{
	world.draw();
	player.drawButtons(&world.getRenderTarget());
	world.drawCup();
	world.drawChip();

	if (isBluffCalled)
		world.drawOpponentDice(players[1]->showDice());

	if (currentPlayer != 0 && !isBluffCalled)
		world.drawSandTimer(currentPlayer);
}

bool GameState::update(sf::Time dt)
{
	if (world.getChipPosition().x == world.getNewChipPosition().x && world.getChipPosition().y == world.getNewChipPosition().y)
		play();
	else {
		world.draw();
		player.drawButtons(&world.getRenderTarget());
		world.drawCup();
		world.moveChip(board.getCurrentBid());
		world.drawChip();
	}
	
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

bool GameState::isValidMove()
{
	return true;
}

void GameState::setIsHumanPlayerWon()
{
	std::vector<Dice> allDice;

	for (auto d : players[0]->showDice())
		allDice.push_back(d);

	for (auto d : players[1]->showDice())
		allDice.push_back(d);
		
	int numberOfFaceOnTable = 0;

	for (auto d : allDice)
		if (d.getFace() == board.getCurrentBid().getFace() || d.getFace() == Dice::Face::Star)
			numberOfFaceOnTable++;

	bool isCallingBluffWon = true;
	if (board.getCurrentBid().getNumber() <= numberOfFaceOnTable)
		isCallingBluffWon = false;

	if ((currentPlayer == 0 && isCallingBluffWon) || (currentPlayer != 0 && !isCallingBluffWon))
		player.setStatus(HumanPlayer::Status::Success);
	else
		player.setStatus(HumanPlayer::Status::Failure);
}

void GameState::play()
{
	if (!isBluffCalled) {

		Bid newBid = players[currentPlayer]->makeMove(board.getCurrentBid());

		if (newBid.getNumber() != -1) {
			if (newBid.getNumber() != BLUFF) {

				if (board.isMoveValid(newBid)) {
					board.setCurrentBid(newBid);



					//if (currentPlayer != 2)
					//	(dynamic_cast<AIPlayer3*>(players[2]))->updateInfoForPlayer(newBid);
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
				setIsHumanPlayerWon();
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