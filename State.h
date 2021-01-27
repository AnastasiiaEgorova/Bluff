#pragma once

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

// forward declaration
namespace sf {
	class RenderWindow;
}

class Player;
class StateStack;
class MusicPlayer;
class SoundPlayer;

// the whole point of State is to be inherited by other classes
class State
{
public:
	using Ptr = std::unique_ptr<State>;

	struct Context {

		Context(sf::RenderWindow& window,
			TextureHolder_t& textures,
			FontHolder_t& fonts,
			Player& player,
			MusicPlayer& music,
			SoundPlayer& sounds);

		sf::RenderWindow*	window;
		TextureHolder_t*	textures;
		FontHolder_t*		fonts;
		Player*				player;
		MusicPlayer*		music;
		SoundPlayer*		sounds;
	};

					State(StateStack& stack, Context context);
	virtual         ~State() {}

	virtual void	draw() = 0;
	virtual bool	update(sf::Time dt) = 0;
	virtual bool	handleEvent(const sf::Event& event) = 0;
	 
protected:
	void			requestStackPush(StateID stateID);
	void			requestStackPop();
	void			requestStackClear();

	Context			getContext();

private:
	StateStack*		stack;
	Context			context;
};

