#include "ChooseOpponentsState.h"

ChooseOpponentsState::ChooseOpponentsState(StateStack& stack, Context context)
	: State(stack, context)
	, chooseOpponentsText()
	, instructionText()
	, opponents()
	, opponentsIndex(0)
{
	sf::Font& font = context.fonts->get(FontID::Main);
	//sf::Vector2f windowSize(context.window->getSize());

	sf::Text opponentAI1;
	opponentAI1.setFont(font);
	opponentAI1.setString("AI 1");
	centerOrigin(opponentAI1);
	opponentAI1.setPosition(context.window->getView().getSize() / 2.f);
	opponents.push_back(opponentAI1);
	opponentsChosen[0] = false;

	sf::Text opponentAI2;
	opponentAI2.setFont(font);
	opponentAI2.setString("AI 2");
	centerOrigin(opponentAI2);
	opponentAI2.setPosition(opponentAI1.getPosition() + sf::Vector2f(0.f, 30.f));
	opponents.push_back(opponentAI2);
	opponentsChosen[1] = false;

	sf::Text opponentAI3;
	opponentAI3.setFont(font);
	opponentAI3.setString("AI 3");
	centerOrigin(opponentAI3);
	opponentAI3.setPosition(opponentAI2.getPosition() + sf::Vector2f(0.f, 30.f));
	opponents.push_back(opponentAI3);
	opponentsChosen[2] = false;

	chooseOpponentsText.setFont(font);
	chooseOpponentsText.setString("Choose opponents to play with");
	centerOrigin(chooseOpponentsText);
	chooseOpponentsText.setPosition(opponentAI1.getPosition() - sf::Vector2f(0.f, 120.f));

	instructionText.setFont(font);
	instructionText.setCharacterSize(20);
	instructionText.setString("Press Space to choose/unchoose opponent. Press Enter to continue.");
	centerOrigin(instructionText);
	instructionText.setPosition(opponentAI3.getPosition() + sf::Vector2f(0.f, 160.f));

	backgroundColour = sf::Color(0, 255, 0, 100);

	updateOpponentsText();
}

void ChooseOpponentsState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	sf::RectangleShape backgroundShape;
	backgroundShape.setFillColor(backgroundColour);
	backgroundShape.setSize(window.getView().getSize());

	window.draw(backgroundShape);

	window.draw(chooseOpponentsText);
	for (const auto& text : opponents) {
		window.draw(text);
	}
	window.draw(instructionText);
}

bool ChooseOpponentsState::update(sf::Time dt)
{
	return false;
}

bool ChooseOpponentsState::handleEvent(const sf::Event& event)
{
	if (event.type != sf::Event::KeyPressed)
		return false;

	if (event.key.code == sf::Keyboard::Space) {  // If an opponent is chosen

		opponentsChosen[opponentsIndex] = !opponentsChosen[opponentsIndex];
		updateOpponentsText();
	}
	else if (event.key.code == sf::Keyboard::Up) {
		if (opponentsIndex > 0)
			opponentsIndex--;
		else
			opponentsIndex = opponents.size() - 1;

		updateOpponentsText();
	}
	else if (event.key.code == sf::Keyboard::Down) {
		if (opponentsIndex < opponents.size() - 1)
			opponentsIndex++;
		else
			opponentsIndex = 0;

		updateOpponentsText();
	}

	else if (event.key.code == sf::Keyboard::Return) {
		std::vector<int> op;
		for (auto& o : opponentsChosen) {
			if (o.second)
				//context.opponentPlayers->push_back(o.first);
				op.push_back(o.first);
		}
		setOpponents(op);

		requestStackPop();
		requestStackPush(StateID::Game);
	}

	return false;   // if there are more states in stack => return false
}

void ChooseOpponentsState::updateOpponentsText()
{
	if (opponents.empty())
		return;

	for (auto& text : opponents) {
		text.setFillColor(sf::Color::White);
	}

	opponents[opponentsIndex].setFillColor(sf::Color::Red);

	for (int i = 0; i < opponents.size(); ++i)
		if (opponentsChosen[i])
			opponents[i].setFillColor(sf::Color::Blue);
}
