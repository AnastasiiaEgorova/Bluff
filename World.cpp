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

	//loadTextures();
	//buildScene();

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
	textures.load(TextureID::Desert, "Media/Textures/Desert.png");

	textures.load(TextureID::Jungle, "Media/Textures/Jungle.png");
	textures.load(TextureID::Explosion, "Media/Textures/Explosion.png");
	textures.load(TextureID::Particle, "Media/Textures/Particle.png");
	textures.load(TextureID::FinishLine, "Media/Textures/FinishLine.png");

	textures.load(TextureID::Entities, "Media/Textures/Entities.png");
}

void World::buildScene()
{

	// prepare background texture
	sf::Texture& texture = textures.get(TextureID::Jungle);
	texture.setRepeated(true);

}


void World::updateSounds()
{
	//sounds.setListenerPosition(playerAircraft->getWorldPosition());
	//sounds.removeStoppedSounds();
}
