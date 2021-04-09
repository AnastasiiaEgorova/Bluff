#pragma once
#include "State.h"
#include "Utility.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

class InstructionState : public State
{
public:
							InstructionState(StateStack& stack, Context context);

	virtual void			draw() override;
	virtual bool			update(sf::Time dt) override;
	virtual bool			handleEvent(const sf::Event& event) override;

private:
	sf::Sprite				titleSprite;

	sf::Text				titleText;
	sf::Text				instructionText;
};

