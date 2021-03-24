#include "State.h"
#include "StateStack.h"

State::State(StateStack& stack, Context context)
	: stack(&stack)
	, context(context)
{
}

void State::requestStackPush(StateID stateID)
{
	stack->pushState(stateID);
}

void State::requestStackPop()
{
	stack->popState();
}

void State::requestStackClear()
{
	stack->clearStates();
}

State::Context State::getContext()
{
	return context;
}

State::Context::Context(sf::RenderWindow& window, 
	TextureHolder_t& textures, 
	FontHolder_t& fonts, 
	HumanPlayer& player,
	MusicPlayer& music,
	SoundPlayer& sounds,
	std::vector<int>& opponentPlayers)
	// in context all fields are pointers => taking addresses of objects
	: window(&window)
	, textures(&textures)
	, fonts(&fonts)
	, player(&player)
	, music(&music)
	, sounds(&sounds)
	, opponentPlayers(&opponentPlayers)
{
}

void State::setOpponents(std::vector<int> o)
{
	context.opponentPlayers = &o;
}
