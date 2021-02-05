#include "World.h"

World::World(sf::RenderTarget& outputTarget, FontHolder_t& fonts, SoundPlayer& sounds)
	: target(outputTarget)
	, sceneTexture()
	, worldView(target.getDefaultView())
	, textures()
	, fonts(fonts)
	, sounds(sounds)
	, sceneGraph()
	, sceneLayers()
	, worldBounds(0.f, 0.f, worldView.getSize().x, worldView.getSize().y)
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
	textures.load(TextureID::Table, "Media/Textures/Table.jpg");
	textures.load(TextureID::Board, "Media/Textures/Board.jpg");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; ++i) {

		Category::Type category = (i == TableLayer) ? Category::Type::Table : Category::Type::EverythingElse;

		SceneNode::Ptr layer(new SceneNode(category));
		sceneLayers[i] = layer.get();

		sceneGraph.attachChild(std::move(layer));
	}

	float viewHeight = worldView.getSize().y;
	sf::IntRect textureRect(worldBounds);

	// table
	sf::Texture& texture = textures.get(TextureID::Table);
	texture.setRepeated(false);

	std::unique_ptr<SpriteNode> table(new SpriteNode(texture));
	table->setPosition(worldBounds.left, worldBounds.top);
	table->setScale(1.5, 1.5);
	sceneLayers[TableLayer]->attachChild(std::move(table));

	//board
	sf::Texture& textureBoard = textures.get(TextureID::Board);
	textureBoard.setRepeated(false);

	std::unique_ptr<SpriteNode> board(new SpriteNode(textureBoard));
	board->setPosition(worldView.getCenter().x - textureBoard.getSize().x / 1.5, 
						worldView.getCenter().y - textureBoard.getSize().y / 1.5);
	board->setScale(1.25, 1.25);
	sceneLayers[BoardLayer]->attachChild(std::move(board));
}


void World::updateSounds()
{
	//sounds.setListenerPosition(playerAircraft->getWorldPosition());
	//sounds.removeStoppedSounds();
}
