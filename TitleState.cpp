#include "TitleState.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Utility.h"
#include "ResourceHolder.h"

TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context)
	, text()
	, showText(true)
	, textEffectTime(sf::Time::Zero)
{
	//backgroundSprite.setTexture(context.textures->get(TextureID::TitleScreen));

	text.setFont(context.fonts->get(FontID::Main));
	text.setString("Press any key to start");

	centerOrigin(text);
	text.setPosition(context.window->getView().getSize() / 2.f);
}

void TitleState::draw()
{
	auto& window = *getContext().window;		// local variable wich is ref to global window
	window.draw(backgroundSprite);	
	
	if (showText)
		window.draw(text);
}

bool TitleState::update(sf::Time dt)
{
	// flashing text effect
	textEffectTime += dt;	
	
	if (textEffectTime >= sf::seconds(0.5f)) {
		showText = !showText;
		textEffectTime = sf::Time::Zero;
	}	
	
	return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(StateID::Menu);
	}
	return true;
}
