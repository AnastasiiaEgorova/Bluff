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
	backgroundColour = sf::Color(255, 0, 0, 100);
	
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(sf::Color::White);
	centerOrigin(gameOverText);
	gameOverText.setPosition(0.5f * windowSize.x, 0.5f * windowSize.y);


	bender.setTexture(context.textures->get(TextureID::Bender));
	bender.setScale(0.4, 0.4);
	bender.setPosition(0.65f * windowSize.x, 0.1f * windowSize.y);

	backgroundShape.setFillColor(backgroundColour);
	backgroundShape.setSize(context.window->getView().getSize());
}

void GameOverState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	//sf::RectangleShape backgroundShape;
	//backgroundShape.setFillColor(backgroundColour);
	//backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);
	window.draw(gameOverText);

	window.draw(bender);
}

bool GameOverState::update(sf::Time dt)
{
	const int COUNTDOWN_TIME = 3;

	elapsedTime += dt;
	//if (elapsedTime > sf::seconds(COUNTDOWN_TIME)) {
	//	requestStackClear();
	//	requestStackPush(StateID::Menu);
	//}

    return false;
}

bool GameOverState::handleEvent(const sf::Event& event)
{
    return false;
}
