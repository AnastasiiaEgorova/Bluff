#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

enum ButtonStates {
	BtnIdle = 0,
	BtnHover,
	BtnPressed,
};

class Button
{
public:
							Button(float x, float y, float width, float height, const FontHolder_t& fonts, std::string text);

	void					render(sf::RenderTarget* target);
	void					update(const sf::Vector2i mousePosition);

	bool					isPressed() const;

	bool					getIsChosen() const;
	void					setIsChosen(bool value);

	std::string				getName() const;
			

private:

	size_t					buttonState;

	bool					isChosen;

	sf::RectangleShape		shape;
	sf::Text				text;

	sf::Color				idleColour;
	sf::Color				hoverColour;
	sf::Color				pressedColour;
	sf::Color				isChosenColour;
};

