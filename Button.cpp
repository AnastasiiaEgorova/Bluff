#include "Button.h"

Button::Button(float x, float y, float width, float height, const FontHolder_t& fonts, std::string text)
{
	this->buttonState = BtnIdle;

	isChosen = false;

	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));

	this->text.setFont(fonts.get(FontID::Main));
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f - this->text.getGlobalBounds().height / 2.f - 5.f);

	this->idleColour = sf::Color(20, 20, 20, 200);
	this->hoverColour = sf::Color::Yellow;
	this->pressedColour = sf::Color::Green;
	this->isChosenColour = sf::Color::Magenta;

	this->shape.setFillColor(sf::Color(100, 100, 100, 200));
}

void Button::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
	target->draw(this->text);
}

void Button::update(const sf::Vector2i mousePosition)
{
	// Idle
	this->buttonState = BtnIdle;

	// Hover
	if (this->shape.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))) {
		this->buttonState = BtnHover;

		// Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			isChosen = !isChosen;
			this->buttonState = BtnPressed;
		}
	}

	if (!isChosen) {
		switch (this->buttonState)
		{
		case BtnIdle:
			this->shape.setFillColor(this->idleColour);
			break;

		case BtnHover:
			this->shape.setFillColor(this->hoverColour);
			break;

		case BtnPressed:
			this->shape.setFillColor(this->pressedColour);
			break;

		default:
			this->shape.setFillColor(sf::Color::Red);
			break;
		}
	}
	else
	{
		shape.setFillColor(isChosenColour);
	}
}

bool Button::isPressed() const
{
	return this->buttonState == BtnPressed;
}


bool Button::getIsChosen() const
{
	return isChosen;
}

void Button::setIsChosen(bool value)
{
	isChosen = value;
}

std::string Button::getName() const
{
	return text.getString().toAnsiString();
}
