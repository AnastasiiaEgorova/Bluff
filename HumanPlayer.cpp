#include "HumanPlayer.h"

HumanPlayer::HumanPlayer() : Player()
{
	initializeKeyBindings();
	//initializeActions();
}

void HumanPlayer::initializeKeyBindings()
{   // map from key to action
	keyBindings[sf::Keyboard::M] = Action::MakeMove;
	keyBindings[sf::Keyboard::B] = Action::CallBluff;
}

Bid HumanPlayer::makeMove()
{
	// will do makeBid OR callBluff
	return Bid(2, Dice::Face::Star);
}

Bid HumanPlayer::makeBid()
{
	return Bid(2, Dice::Face::Star);
}

Bid HumanPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}

void HumanPlayer::initializeButtons(const FontHolder_t& fonts)
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

void HumanPlayer::updateMousePositionsForButtons(sf::Vector2i mousePos)
{
	btnCallBluff->update(mousePos);
	btnMakeMove->update(mousePos);

	for (auto& b : numberButtons)
		b->update(mousePos);

	for (auto& b : faceButtons)
		b->update(mousePos);
}

void HumanPlayer::drawButtons(sf::RenderTarget* target)
{
	btnCallBluff->render(target);
	btnMakeMove->render(target);

	for (auto& b : numberButtons)
		b->render(target);

	for (auto& b : faceButtons)
		b->render(target);
}


bool HumanPlayer::areButtonsPressedToMakeMove()
{
	bool numberChosen = false;
	bool faceChosen = false;

	for (auto& b : numberButtons)
		if (b->isPressed())
			numberChosen = true;

	for (auto& b : faceButtons)
		if (b->isPressed())
			faceChosen = true;

	return (numberChosen && faceChosen);
}
