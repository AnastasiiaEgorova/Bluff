#include "World.h"
//#include "SpriteNode.h"

World::World(sf::RenderTarget& outputTarget, FontHolder_t& fonts, SoundPlayer& sounds)
	: target(outputTarget)
	, sceneTexture()
	, worldView(target.getDefaultView())
	, textures()
	, fonts(fonts)
	, sounds(sounds)
	, sceneGraph()
	, sceneLayers()
	, worldBounds(0.f, 0.f, worldView.getSize().x, 6000.f)
	//, playerAircraft(nullptr)     // will populate later
{
	sceneTexture.create(target.getSize().x, target.getSize().y);

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
	textures.load(TextureID::Board, "Media/Textures/Board.jpg");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; ++i) {

		Category::Type category = (i == BoardLayer) ? Category::Type::Board : Category::Type::EverythingElse;

		SceneNode::Ptr layer(new SceneNode(category));
		sceneLayers[i] = layer.get();

		sceneGraph.attachChild(std::move(layer));
	}

	// prepare background texture
	sf::Texture& texture = textures.get(TextureID::Board);
	texture.setRepeated(false);

	float viewHeight = worldView.getSize().y;
	sf::IntRect textureRect(worldBounds);
	textureRect.height += static_cast<int>(viewHeight);

	std::unique_ptr<SpriteNode> board(new SpriteNode(texture, textureRect));
	board->setPosition(0.f, -76.f);
	sceneLayers[BoardLayer]->attachChild(std::move(board));
}


void World::updateSounds()
{
	//sounds.setListenerPosition(playerAircraft->getWorldPosition());
	//sounds.removeStoppedSounds();
}
