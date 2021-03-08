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

Bid HumanPlayer::makeMove(Bid currentBid)
{
	if (btnCallBluff->isPressed()) {
		resetButtons();
		return callBluff();
	}
	else {
		return makeBid(currentBid);
	}
}

Bid HumanPlayer::makeBid(Bid currentBid)
{
	if (!areButtonsPressedToMakeMove())
		return Bid(-1, Dice::Face::One);
	else
	{
		std::string num;
		getValueFormButton(num, numberButtons);

		std::string face;
		getValueFormButton(face, faceButtons);

		int number = Bid::numberNames.find(num)->second;
		Dice::Face faceFace = Bid::faceNames.find(face)->second;

		resetButtons();
		return Bid(number, faceFace);
	}
}

Bid HumanPlayer::callBluff()
{
	return Bid(0, Dice::Face::One);
}

void HumanPlayer::initializeButtons(const FontHolder_t& fonts)
{
	//btnMakeMove = std::unique_ptr<Button>(new Button(1100.f, 450.f, 100.f, 25.f, fonts, "Make Move"));

	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 30.f, 45.f, 25.f, fonts, "1")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 60.f, 45.f, 25.f, fonts, "2")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 90.f, 45.f, 25.f, fonts, "3")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 120.f, 45.f, 25.f, fonts, "4")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 150.f, 45.f, 25.f, fonts, "5")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 180.f, 45.f, 25.f, fonts, "6")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 210.f, 45.f, 25.f, fonts, "7")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 240.f, 45.f, 25.f, fonts, "8")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 270.f, 45.f, 25.f, fonts, "9")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 300.f, 45.f, 25.f, fonts, "10")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 330.f, 45.f, 25.f, fonts, "11")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 360.f, 45.f, 25.f, fonts, "12")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 390.f, 45.f, 25.f, fonts, "13")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 420.f, 45.f, 25.f, fonts, "14")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 450.f, 45.f, 25.f, fonts, "15")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 480.f, 45.f, 25.f, fonts, "16")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 510.f, 45.f, 25.f, fonts, "17")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 540.f, 45.f, 25.f, fonts, "18")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 570.f, 45.f, 25.f, fonts, "19")));
	numberButtons.push_back(std::unique_ptr<Button>(new Button(1150.f, 600.f, 45.f, 25.f, fonts, "20")));

	faceButtons.push_back(std::unique_ptr<Button>(new Button(1200.f, 30.f, 45.f, 25.f, fonts, "Ones")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1200.f, 60.f, 45.f, 25.f, fonts, "Twos")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1200.f, 90.f, 45.f, 25.f, fonts, "Threes")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1200.f, 120.f, 45.f, 25.f, fonts, "Fours")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1200.f, 150.f, 45.f, 25.f, fonts, "Fives")));
	faceButtons.push_back(std::unique_ptr<Button>(new Button(1200.f, 180.f, 45.f, 25.f, fonts, "Stars")));

	btnCallBluff = std::unique_ptr<Button>(new Button(1150.f, 650.f, 100.f, 25.f, fonts, "Call Bluff"));
}

void HumanPlayer::updateMousePositionsForButtons(sf::Vector2i mousePos)
{
	btnCallBluff->update(mousePos);
	//btnMakeMove->update(mousePos);

	for (auto& b : numberButtons)
		b->update(mousePos);

	for (auto& b : faceButtons)
		b->update(mousePos);
}

void HumanPlayer::drawButtons(sf::RenderTarget* target)
{
	btnCallBluff->render(target);
	//btnMakeMove->render(target);

	for (auto& b : numberButtons)
		b->render(target);

	for (auto& b : faceButtons)
		b->render(target);
}

void HumanPlayer::resetButtons()
{
	for (auto& b : numberButtons)
		b->setIsChosen(false);

	for (auto& b : faceButtons)
		b->setIsChosen(false);
}


bool HumanPlayer::areButtonsPressedToMakeMove()
{
	bool numberChosen = false;
	bool faceChosen = false;

	for (auto& b : numberButtons) 
		if (b->getIsChosen()) {
			numberChosen = true;
			break;
		}

	for (auto& b : faceButtons)
		if (b->getIsChosen()) {
			faceChosen = true;
			break;
		}

	return (numberChosen && faceChosen);
}

void HumanPlayer::getValueFormButton(std::string& str, std::vector<std::unique_ptr<Button>>& buttons)
{
	for (auto& b : buttons) {
		if (b->getIsChosen())
			str = b->getName();
	}
}
