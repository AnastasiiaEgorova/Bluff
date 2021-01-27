#include "World.h"

World::World(sf::RenderTarget& outputTarget, FontHolder_t& fonts, SoundPlayer& sounds)
	: target(outputTarget)
	//, sceneTexture()
	, worldView(target.getDefaultView())
	, textures()
	, fonts(fonts)
	, sounds(sounds)
	, sceneGraph()
	//, playerAircraft(nullptr)     // will populate later
{
	//sceneTexture.create(target.getSize().x, target.getSize().y);

	loadTextures();
	buildScene();

}

CommandQueue& World::getCommands() {
	return commandQueue;
}


void World::update(sf::Time dt)
{



	while (!commandQueue.isEmpty()) {
		sceneGraph.onCommand(commandQueue.pop(), dt);
	}


	sceneGraph.update(dt, getCommands());
	updateSounds();
}

void World::draw()
{
	target.setView(worldView);
	target.draw(sceneGraph);
}

void World::loadTextures()
{
	textures.load(TextureID::Board, "Media/Textures/TitleScreen.png");
}

void World::buildScene()
{

	// prepare background texture
	sf::Texture& texture = textures.get(TextureID::Board);
	texture.setRepeated(false);

}


void World::updateSounds()
{
	//sounds.setListenerPosition(playerAircraft->getWorldPosition());
	//sounds.removeStoppedSounds();
}
