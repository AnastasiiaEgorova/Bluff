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
	titleText.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 30.f));

	instructionText.setFont(font);
	instructionText.setString("Play");
	centerOrigin(instructionText);
	instructionText.setPosition(titleText.getPosition() + sf::Vector2f(0.f, 80.f));
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

	if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {  // Enter is pressed
		requestStackPop();
		//requestStackPush(StateID::Menu);
	}

	return false;
}