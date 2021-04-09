#pragma once
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "CommandQueue.h"
#include "Command.h"
#include "SoundPlayer.h"
#include "TextNode.h"
#include "Bid.h"
#include "Button.h"
#include "Board.h"
#include "Actor.h"
#include <sstream>
#include <string>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include <array>
#include "Dice.h"

namespace sf {
	class RenderTarget;
}

class World : public sf::NonCopyable
{
public:
	explicit							World(sf::RenderTarget& window, FontHolder_t& fonts, SoundPlayer& sounds, std::vector<int>& opponents);
	void								update(sf::Time dt);
	void								draw();
	void								updateErrorMessage(std::string message);
	void								drawDice(std::vector<Dice> playersDice);
	void								drawOpponentDice(std::vector<Dice> playersDice, int opponent);
	CommandQueue&						getCommands();

	sf::RenderTarget&					getRenderTarget();

	void								updateSounds();
	void								updateCurrentBidText(Bid b);

	void								drawChip();

	void								moveChip(Bid bid);
	void								setChipNewPosition(Bid bid);
	void								setNewChipAngle(Bid bid);

	sf::Vector2f						getChipPosition();
	sf::Vector2f						getNewChipPosition();
	float								getNewChipAngle();
	void								setChipTexture(Dice::Face face);

	void								updatePlayerAnimationState(int currentPlayer);

	Actor*								getOpponent(int number);

private:
	void								loadTextures();
	void								buildScene();
	Actor::Type							loadDice(Dice::Face face);

	SpriteNode*							setSpriteNode(TextureID text, sf::Vector2f pos, float scale);

	void								setChipInitialPosition(int number);
	void								setChipRotation(int number);

	void								setOpponentsDicePositions(std::vector<int>& opponents);

	void								setOpponents(std::vector<int>& opponents);

private:

	enum Layer {
		TableLayer,
		BoardLayer,
		ChipLayer,
		LayerCount
	};

	sf::RenderTarget&					target;
	sf::RenderTexture					sceneTexture;
	sf::View							worldView;
	TextureHolder_t						textures;
	const FontHolder_t&					fonts;
	SoundPlayer&						sounds;

	SceneNode							sceneGraph;
	std::array<SceneNode*, LayerCount>	sceneLayers;	
	CommandQueue						commandQueue;

	sf::FloatRect						worldBounds;		// to determine the temporary window size

	TextNode*							currentBid;
	TextNode*							errorMessage;

	std::vector<Actor*>					actors;

	std::vector<std::vector<sf::Vector2f>>			opponetsDicePositions;

	SpriteNode*							chip;

	sf::Vector2f						newChipPosition;
	float								dx;
	float								dy;

	float								newChipAngle;
	float								dAngle;
};

