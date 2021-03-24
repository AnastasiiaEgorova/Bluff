#pragma once

#include "StateIdentifiers.h"
#include "ResourceIdentifiers.h"
#include "HumanPlayer.h"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

// forward declaration
namespace sf {
	class RenderWindow;
}

class HumanPlayer;
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
			HumanPlayer& player,
			MusicPlayer& music,
			SoundPlayer& sounds,
			std::vector<int>& opponentPlayers);

		sf::RenderWindow*		window;
		TextureHolder_t*		textures;
		FontHolder_t*			fonts;
		HumanPlayer*			player;
		MusicPlayer*			music;
		SoundPlayer*			sounds;
		std::vector<int>*		opponentPlayers;
	};

					State(StateStack& stack, Context context);
	virtual         ~State() {}

	virtual void	draw() = 0;
	virtual bool	update(sf::Time dt) = 0;
	virtual bool	handleEvent(const sf::Event& event) = 0;

	void			setOpponents(std::vector<int> o);
	 
protected:
	void			requestStackPush(StateID stateID);
	void			requestStackPop();
	void			requestStackClear();

	Context			getContext();

private:
	StateStack*		stack;
	Context			context;
};

