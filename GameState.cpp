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
	players.push_back(new AIPlayer());

	player.initializeButtons(*context.fonts);	

	world.drawDice(players.front()->showDice());
}

void GameState::draw()
{
	world.draw();
	player.drawButtons(&world.getRenderTarget());

	world.drawCup();

	if (isBluffCalled)
		world.drawOpponentDice(players[1]->showDice());

	if (currentPlayer != 0 && !isBluffCalled)
		world.drawSandTimer();
}

bool GameState::update(sf::Time dt)
{
	play();
	
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
					//if ()
					errorMessage = "";
					nextPlayer();
					//TO DO change later
					std::this_thread::sleep_for(std::chrono::seconds(1));
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
	else
		requestStackPush(StateID::GameOver);
}