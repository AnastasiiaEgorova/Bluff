#include "ChooseOpponentsState.h"

ChooseOpponentsState::ChooseOpponentsState(StateStack& stack, Context context)
	: State(stack, context)
	, chooseOpponentsText()
	, instructionText()
	, opponents()
	, opponentsIndex(0)
{
	sf::Font& font = context.fonts->get(FontID::Main);
	//sf::Vector2f windowSize(context.window->getSize());

	sf::Text opponentAI1;
	opponentAI1.setFont(font);
	opponentAI1.setString("AI 1");
	centerOrigin(opponentAI1);
	opponentAI1.setPosition(context.window->getView().getSize() / 2.f);
	opponents.push_back(opponentAI1);

	sf::Text opponentAI2;
	opponentAI2.setFont(font);
	opponentAI2.setString("AI 2");
	centerOrigin(opponentAI2);
	opponentAI2.setPosition(opponentAI1.getPosition() + sf::Vector2f(0.f, 30.f));
	opponents.push_back(opponentAI2);

	sf::Text opponentAI3;
	opponentAI3.setFont(font);
	opponentAI3.setString("AI 3");
	centerOrigin(opponentAI3);
	opponentAI3.setPosition(opponentAI2.getPosition() + sf::Vector2f(0.f, 30.f));
	opponents.push_back(opponentAI3);

	chooseOpponentsText.setFont(font);
	chooseOpponentsText.setString("Choose opponents to play with");
	centerOrigin(chooseOpponentsText);
	chooseOpponentsText.setPosition(opponentAI1.getPosition() - sf::Vector2f(0.f, 120.f));

	instructionText.setFont(font);
	instructionText.setCharacterSize(20);
	instructionText.setString("Press Space to choose opponent. Press Enter to continue.");
	centerOrigin(instructionText);
	instructionText.setPosition(opponentAI3.getPosition() + sf::Vector2f(0.f, 160.f));

	backgroundColour = sf::Color(0, 255, 0, 100);
}

void ChooseOpponentsState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(backgroundColour);
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);

	window.draw(chooseOpponentsText);
	for (const auto& text : opponents) {
		window.draw(text);
	}
	window.draw(instructionText);
}

bool ChooseOpponentsState::update(sf::Time dt)
{
	return false;
}

bool ChooseOpponentsState::handleEvent(const sf::Event& event)
{
	return false;
}

void ChooseOpponentsState::updateOpponentsText()
{
}
