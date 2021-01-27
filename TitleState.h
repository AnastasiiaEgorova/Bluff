#pragma once
#include "State.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class TitleState : public State
{
public:
					TitleState(StateStack& stack, Context context);

	virtual void	draw() override;
	virtual bool	update(sf::Time dt) override;
	virtual bool	handleEvent(const sf::Event& event) override;

private:
	sf::Sprite		backgroundSprite;
	sf::Text		text;

	bool			showText;		// both needed to make the text flashing
	sf::Time		textEffectTime;
};

