#include "State.h"
#include "Utility.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class ChooseOpponentsState : public State
{
public:
							ChooseOpponentsState(StateStack& stack, Context context);

	virtual void			draw() override;
	virtual bool			update(sf::Time dt) override;
	virtual bool			handleEvent(const sf::Event& event) override;

	void					updateOpponentsText();

private:
	enum OpponentPlayers {
		AI_1 = 0,
		AI_2 = 1,
		AI_3 = 2,
	};

private:
	sf::Text				chooseOpponentsText;
	sf::Text				instructionText;

	std::vector<sf::Text>	opponents;
	std::size_t				opponentsIndex;

	std::map<int, bool>		opponentsChosen;

	sf::Color				backgroundColour;
};
