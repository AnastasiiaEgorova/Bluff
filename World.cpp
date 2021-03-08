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

void World::updateCurrentBidText(Bid b)
{
	std::stringstream stream;
	stream << b;
	currentBid->setString("Current Bid: " + stream.str());
}

void World::draw()
{
	target.setView(worldView);
	target.draw(sceneGraph);
}

void World::updateErrorMessage(std::string message)
{
	errorMessage->setString(message);
}

void World::drawDice(std::vector<Dice> playersDice)
{
	// dice1
	sf::Texture& dice1Texture = textures.get(loadDice(playersDice.at(0).getFace()));
	dice1Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice1(new SpriteNode(dice1Texture));
	dice1->setPosition(worldBounds.width - 280, worldBounds.height - 90);
	sceneLayers[BoardLayer]->attachChild(std::move(dice1));

	// dice2
	sf::Texture& dice2Texture = textures.get(loadDice(playersDice.at(1).getFace()));
	dice2Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice2(new SpriteNode(dice2Texture));
	dice2->setPosition(worldBounds.width - 320, worldBounds.height - 150);
	sceneLayers[BoardLayer]->attachChild(std::move(dice2));

	// dice3
	sf::Texture& dice3Texture = textures.get(loadDice(playersDice.at(2).getFace()));
	dice3Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice3(new SpriteNode(dice3Texture));
	dice3->setPosition(worldBounds.width - 380, worldBounds.height - 120);
	sceneLayers[BoardLayer]->attachChild(std::move(dice3));

	// dice4
	sf::Texture& dice4Texture = textures.get(loadDice(playersDice.at(3).getFace()));
	dice4Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice4(new SpriteNode(dice4Texture));
	dice4->setPosition(worldBounds.width - 440, worldBounds.height - 130);
	sceneLayers[BoardLayer]->attachChild(std::move(dice4));

	// dice5
	sf::Texture& dice5Texture = textures.get(loadDice(playersDice.at(4).getFace()));
	dice5Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice5(new SpriteNode(dice5Texture));
	dice5->setPosition(worldBounds.width - 500, worldBounds.height - 100);
	sceneLayers[BoardLayer]->attachChild(std::move(dice5));
}

void World::loadTextures()
{
	textures.load(TextureID::Table, "Media/Textures/Table.jpg");
	textures.load(TextureID::Board, "Media/Textures/Board.jpg");
	textures.load(TextureID::Dice1, "Media/Textures/Dice1.jpg");
	textures.load(TextureID::Dice2, "Media/Textures/Dice2.jpg");
	textures.load(TextureID::Dice3, "Media/Textures/Dice3.jpg");
	textures.load(TextureID::Dice4, "Media/Textures/Dice4.jpg");
	textures.load(TextureID::Dice5, "Media/Textures/Dice5.jpg");
	textures.load(TextureID::DiceStar, "Media/Textures/DiceStar.jpg");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; ++i) {

		Category::Type category = (i == TableLayer) ? Category::Type::Table : Category::Type::Dice;

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

	//Current Bid (for now)
	std::unique_ptr<TextNode> currentBidField(new TextNode(fonts, "Current Bid: "));
	currentBidField->setPosition(worldView.getCenter().x - 30,
								30);
	currentBid = currentBidField.get();
	sceneLayers[TableLayer]->attachChild(std::move(currentBidField));

	//Error Message for user
	std::unique_ptr<TextNode> errorMessageField(new TextNode(fonts, ""));
	errorMessageField->setPosition(worldView.getCenter().x - 30, 60);

	errorMessage = errorMessageField.get();
	sceneLayers[TableLayer]->attachChild(std::move(errorMessageField));
}


void World::updateSounds()
{
	//sounds.setListenerPosition(playerAircraft->getWorldPosition());
	//sounds.removeStoppedSounds();
}

TextureID World::loadDice(Dice::Face face)
{
	switch (face) {

	case Dice::Face::One:
		return TextureID::Dice1;

	case Dice::Face::Two:
		return TextureID::Dice2;

	case Dice::Face::Three:
		return TextureID::Dice3;

	case Dice::Face::Four:
		return TextureID::Dice4;

	case Dice::Face::Five:
		return TextureID::Dice5;

	default:
		return TextureID::DiceStar;
	}
}

sf::RenderTarget& World::getRenderTarget()
{
	return target;
}