#pragma once
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"
#include "CommandQueue.h"
#include "Command.h"
#include "SoundPlayer.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <array>

namespace sf {
	class RenderTarget;
}

class World : public sf::NonCopyable
{
public:
	explicit							World(sf::RenderTarget& window, FontHolder_t& fonts, SoundPlayer& sounds);
	void								update(sf::Time dt);
	void								draw();
	CommandQueue&						getCommands();

	//bool								hasAlivePlayer() const;
	//void								adaptPlayerPosition();

	void								updateSounds();

private:
	void								loadTextures();
	void								buildScene();



private:
	sf::RenderTarget&					target;
	//sf::RenderTexture					sceneTexture;
	sf::View							worldView;
	TextureHolder_t						textures;
	const FontHolder_t&					fonts;
	SoundPlayer&						sounds;

	SceneNode							sceneGraph;
	CommandQueue						commandQueue;

	//Player*							player;

};

