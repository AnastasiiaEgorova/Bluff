#include "InstructionState.h"

InstructionState::InstructionState(StateStack& stack, Context context)
	: State(stack, context)
{
	sf::Font& font = context.fonts->get(FontID::Main);

	titleSprite.setTexture(context.textures->get(TextureID::Title));
	centerOrigin(titleSprite);
	titleSprite.setPosition(context.window->getView().getCenter().x, titleSprite.getLocalBounds().height / 2.f);

	titleText.setFont(font);
	titleText.setString("Instruction");
	titleText.setFillColor(sf::Color(239, 137, 37));
	titleText.setScale(2.f, 2.f);
	centerOrigin(titleText);
	titleText.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 10.f));

	instructionText.setFont(font);
	std::string instr = "Bluff is a board game where you play against different AIs.\n";
	instr += "Each round you can choose with whom you want to play.\n\n";

	instr += "Each player has 5 dice, each dice has 6 sides: 1 to 5, and a star.\n";
	instr += "Star can play for any number 1 to 5, or play for stars specifically.\n\n";

	instr += "In the beginning of each round all players throw their dice.\n";
	instr += "No player knows opponents' dice. The goal is to make the highest bid that satisfy thrown dice values.\n";
	instr += "First player (you) makes a bet of dice's value and quantity.\n";
	instr += "Next player makes a new bet by increasing the value or quantity OR call bluff.\n";
	instr += "After calling bluff players open their dice and check if the calling bluff player won.\n";
	instructionText.setString(instr);
	instructionText.setScale(0.7f, 0.7f);
	centerOrigin(instructionText);
	instructionText.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 180.f));
}

void InstructionState::draw()
{
	auto& window = *getContext().window;

	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(sf::Color::Black);
	backgroundShape.setSize(window.getView().getSize());
	window.draw(backgroundShape);

	window.draw(titleSprite);
	window.draw(titleText);
	window.draw(instructionText);
}

bool InstructionState::update(sf::Time dt)
{
	return false;
}

bool InstructionState::handleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) { 
		requestStackPop();
	}

	return false;
}