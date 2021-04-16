#include "GameOverState.h"
#include "Utility.h"
#include "Player.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

GameOverState::GameOverState(StateStack& stack, Context context)
	: State(stack, context)
    , gameOverText()
    , elapsedTime(sf::Time::Zero)
{
	sf::Font& font = context.fonts->get(FontID::Main);
	sf::Vector2f windowSize(context.window->getSize());	
	
	gameOverText.setFont(font);
	gameOverText.setString(context.winner->getString());
	backgroundColour = sf::Color(165, 203, 206, 150);
	
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(sf::Color(80, 61, 44));
	gameOverText.setOutlineThickness(1);
	centerOrigin(gameOverText);
	gameOverText.setPosition(0.5f * windowSize.x, 0.5f * windowSize.y);


	bender.setTexture(context.textures->get(TextureID::Bender));
	bender.setScale(0.28, 0.28);
	bender.setPosition(0.2f * windowSize.x, 0.05f * windowSize.y);

	ostrich.setTexture(context.textures->get(TextureID::Ostrich));
	ostrich.setScale(0.6, 0.6);
	ostrich.setPosition(0.2f * windowSize.x, 0.7f * windowSize.y);

	backgroundShape.setFillColor(backgroundColour);
	backgroundShape.setSize(context.window->getView().getSize());
}

void GameOverState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(backgroundShape);
	window.draw(gameOverText);

	window.draw(bender);
	window.draw(ostrich);
}

bool GameOverState::update(sf::Time dt)
{
	const int COUNTDOWN_TIME = 3;

	elapsedTime += dt;

    return false;
}

bool GameOverState::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();  // for GameOver State
		requestStackPop();	// for Game State
		requestStackPush(StateID::Menu);
	}

    return true;
}
