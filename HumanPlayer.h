#pragma once
#include "Player.h"
#include "Button.h"

class HumanPlayer : public Player
{
public:
	enum class Action {
		MakeMove,
		CallBluff,
		ActionCount
	};

public:
											HumanPlayer();
	//void									handleEvent(const sf::Event& event, CommandQueue& commands);

	void									initializeKeyBindings();
	//void									initializeActions();

	Bid										makeMove(Bid currentBid) override;

	void									initializeButtons(const FontHolder_t& fonts);
	void									updateMousePositionsForButtons(sf::Vector2i mousePos);
	void									drawButtons(sf::RenderTarget* target);
	void									resetButtons();

	bool									areButtonsPressedToMakeMove();

	void									getValueFormButton(std::string& str, std::vector<std::unique_ptr<Button>>& buttons);

private:
	Bid										makeBid(Bid currentBid) override;
	Bid										callBluff() override;

private:
	std::map<sf::Keyboard::Key, Action>		keyBindings;
	std::map<Action, Command>				actionBindings;

	std::unique_ptr<Button>					btnCallBluff;
	//std::unique_ptr<Button>					btnMakeMove;

	std::vector<std::unique_ptr<Button>>	numberButtons;
	std::vector<std::unique_ptr<Button>>	faceButtons;
};

