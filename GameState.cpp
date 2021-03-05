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
{
	//TO DO
	//context.music->play(MusicID::MissionTheme);

	players.push_back(&player);
	players.push_back(new AIPlayer());

	initializeButtons(*context.fonts);	

	world.drawDice(players.front()->showDice());
}

void GameState::draw()
{
	world.draw();
	drawButtons();
}

bool GameState::update(sf::Time dt)
{
	world.update(dt);
	world.updateCurrentBidText(board.getCurrentBid());

	updateMousePosition();

	updateMousePositionsForButtons();

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

void GameState::updateMousePosition()
{
	this->mousePosition = sf::Mouse::getPosition(this->window);
}

void GameState::initializeButtons(const FontHolder_t& fonts)
{
	btnCallBluff = std::unique_ptr<Button>(new Button(1100.f, 100.f, 100.f, 25.f, fonts, "Call Bluff"));
	btnMakeMove = std::unique_ptr<Button>(new Button(1100.f, 450.f, 100.f, 25.f, fonts, "Make Move"));

	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 130.f, 40.f, 25.f, fonts, "1")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 160.f, 40.f, 25.f, fonts, "2")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 190.f, 40.f, 25.f, fonts, "3")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 220.f, 40.f, 25.f, fonts, "4")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 250.f, 40.f, 25.f, fonts, "5")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 280.f, 40.f, 25.f, fonts, "6")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 310.f, 40.f, 25.f, fonts, "7")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 340.f, 40.f, 25.f, fonts, "8")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 370.f, 40.f, 25.f, fonts, "9")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1100.f, 400.f, 40.f, 25.f, fonts, "10")));

	faceButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 130.f, 40.f, 25.f, fonts, "Ones")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 160.f, 40.f, 25.f, fonts, "Twos")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 190.f, 40.f, 25.f, fonts, "Threes")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 220.f, 40.f, 25.f, fonts, "Fours")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 250.f, 40.f, 25.f, fonts, "Fives")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 280.f, 40.f, 25.f, fonts, "Stars")));
}

void GameState::updateMousePositionsForButtons()
{
	btnCallBluff->update(mousePosition);
	btnMakeMove->update(mousePosition);

	for (auto& b : numberButtons)
		b->update(mousePosition);

	for (auto& b : faceButtons)
		b->update(mousePosition);
}

void GameState::drawButtons()
{
	btnCallBluff->render(&world.getRenderTarget());
	btnMakeMove->render(&world.getRenderTarget());

	for (auto& b : numberButtons)
		b->render(&world.getRenderTarget());

	for (auto& b : faceButtons)
		b->render(&world.getRenderTarget());
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

		Bid newBid;

		if (currentPlayer == 0)
			if (btnCallBluff->isPressed())
				isBluffCalled = true;

		else 
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
	else
		requestStackPush(StateID::GameOver);
}