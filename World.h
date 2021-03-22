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
	explicit							World(sf::RenderTarget& window, FontHolder_t& fonts, SoundPlayer& sounds);
	void								update(sf::Time dt);
	void								draw();
	void								updateErrorMessage(std::string message);
	void								drawDice(std::vector<Dice> playersDice);
	void								drawOpponentDice(std::vector<Dice> playersDice);
	CommandQueue&						getCommands();

	sf::RenderTarget&					getRenderTarget();

	void								updateSounds();
	void								updateCurrentBidText(Bid b);

	void								drawSandTimer(int player);
	void								drawCup();
	void								drawChip();

	void								moveChip(Bid bid);
	void								setChipNewPosition(Bid bid);

	sf::Vector2f						getChipPosition();
	sf::Vector2f						getNewChipPosition();

private:
	void								loadTextures();
	void								buildScene();
	TextureID							loadDice(Dice::Face face);

	SpriteNode*							setSpriteNode(TextureID text, sf::Vector2f pos, float scale);

	void								setChipPosition(int number);
	void								setChipRotation(int number);
	void								setChipTexture(Dice::Face face);

	void								setStarChip(int number);

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

	SpriteNode*						    clock;
	SpriteNode*							cup;

	SpriteNode*							clock2;
	SpriteNode*							cup2;

	SpriteNode*							chip;

	sf::Vector2f						newChipPosition;
	float								dx;
	float								dy;
};

