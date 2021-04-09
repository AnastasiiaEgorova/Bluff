#include "MenuState.h"
#include "Utility.h"
#include "ResourceHolder.h"
#include "MusicPlayer.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, options()
	, optionIndex(0)
{
	sf::Font& font = context.fonts->get(FontID::Main);

	titleSprite.setTexture(context.textures->get(TextureID::Title));
	centerOrigin(titleSprite);
	titleSprite.setPosition(context.window->getView().getCenter().x, titleSprite.getLocalBounds().height / 2.f);

	titleText.setFont(font);
	titleText.setString("Bluff");
	titleText.setFillColor(sf::Color(239, 137, 37));
	titleText.setScale(2.f, 2.f);
	centerOrigin(titleText);
	titleText.setPosition(context.window->getView().getSize() / 2.f + sf::Vector2f(0.f, 30.f));

	sf::Text playOption;
	playOption.setFont(font);
	playOption.setString("Play");
	centerOrigin(playOption);
	playOption.setPosition(titleText.getPosition() + sf::Vector2f(0.f, 80.f));
	options.push_back(playOption);

	sf::Text instructionOption;
	instructionOption.setFont(font);
	instructionOption.setString("Instructions");
	centerOrigin(instructionOption);
	instructionOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 30.f));
	options.push_back(instructionOption);

	sf::Text exitOption;
	exitOption.setFont(font);
	exitOption.setString("Exit");
	centerOrigin(exitOption);
	exitOption.setPosition(instructionOption.getPosition() + sf::Vector2f(0.f, 30.f));
	options.push_back(exitOption);

	updateOptionText();

	//context.music->play(MusicID::MenuTheme);
}

void MenuState::draw()
{
	auto& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(titleSprite);
	window.draw(titleText);

	for (const auto& text : options) {
		window.draw(text);
	}
}

bool MenuState::update(sf::Time dt)
{
	return false;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Return) {  // Enter is pressed
		if (optionIndex == Play) {
			requestStackPop();
			requestStackPush(StateID::Opponents);
		}
		else if (optionIndex == Instruction) {
			//requestStackPop();
			requestStackPush(StateID::Instruction);
		}
		else if (optionIndex == Exit) {
			requestStackPop();
		}
	}
	else if (event.key.code == sf::Keyboard::Up) {
		if (optionIndex > 0) 
			optionIndex--;
		else
			optionIndex = options.size() - 1;

		updateOptionText();
	}
	else if (event.key.code == sf::Keyboard::Down) {
		if (optionIndex < options.size() - 1)
			optionIndex++;
		else
			optionIndex = 0;

		updateOptionText();
	}
	
	return false;   // if there are more states in stack => return false
}

void MenuState::updateOptionText()
{
	if (options.empty())
		return;

	for (auto& text : options) {
		text.setFillColor(sf::Color::White);
	}

	options[optionIndex].setFillColor(sf::Color::Red);
}
