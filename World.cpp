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

	clock = setSpriteNode(TextureID::Clock, sf::Vector2f(150, 140), 0.3);
	cup = setSpriteNode(TextureID::Cup, sf::Vector2f(50, 30), 0.9);

	clock2 = setSpriteNode(TextureID::Clock, sf::Vector2f(1000, 140), 0.3);
	cup2 = setSpriteNode(TextureID::Cup, sf::Vector2f(850, 20), 0.9);

	chip = new SpriteNode(textures.get(TextureID::Chip1));
	setChipPosition(1);
	setChipRotation(1);

	newChipPosition = sf::Vector2f(358.f, 185.f);
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

	//float currentPosX = world.getChipPosition().x;
	//float currentPosY = world.getChipPosition().y;
	//while (currentPosX != world.getNewChipPosition().x && currentPosY != world.getNewChipPosition().y) {
	//	world.moveChip(board.getCurrentBid());
	//	world.drawChip();
	//}

	//target.draw(*clock2);
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

void World::drawOpponentDice(std::vector<Dice> playersDice)
{
	// dice1
	sf::Texture& dice1Texture = textures.get(loadDice(playersDice.at(0).getFace()));
	dice1Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice1(new SpriteNode(dice1Texture));
	dice1->setPosition(60, 180);
	sceneLayers[BoardLayer]->attachChild(std::move(dice1));

	// dice2
	sf::Texture& dice2Texture = textures.get(loadDice(playersDice.at(1).getFace()));
	dice2Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice2(new SpriteNode(dice2Texture));
	dice2->setPosition(30, 240);
	sceneLayers[BoardLayer]->attachChild(std::move(dice2));

	// dice3
	sf::Texture& dice3Texture = textures.get(loadDice(playersDice.at(2).getFace()));
	dice3Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice3(new SpriteNode(dice3Texture));
	dice3->setPosition(120, 220);
	sceneLayers[BoardLayer]->attachChild(std::move(dice3));

	// dice4
	sf::Texture& dice4Texture = textures.get(loadDice(playersDice.at(3).getFace()));
	dice4Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice4(new SpriteNode(dice4Texture));
	dice4->setPosition(30, 300);
	sceneLayers[BoardLayer]->attachChild(std::move(dice4));

	// dice5
	sf::Texture& dice5Texture = textures.get(loadDice(playersDice.at(4).getFace()));
	dice5Texture.setRepeated(false);

	std::unique_ptr<SpriteNode> dice5(new SpriteNode(dice5Texture));
	dice5->setPosition(120, 290);
	sceneLayers[BoardLayer]->attachChild(std::move(dice5));
}

SpriteNode* World::setSpriteNode(TextureID text, sf::Vector2f pos, float scale)
{
	sf::Texture& texture = textures.get(text);
	texture.setRepeated(false);
	SpriteNode* node = (new SpriteNode(texture));
	node->setPosition(pos);
	node->setScale(scale, scale);

	return node;
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
	textures.load(TextureID::Clock, "Media/Textures/SandClock.png");
	textures.load(TextureID::Cup, "Media/Textures/Cup.jpg");
	textures.load(TextureID::Chip1, "Media/Textures/Chip1.png");
	textures.load(TextureID::Chip2, "Media/Textures/Chip2.png");
	textures.load(TextureID::Chip3, "Media/Textures/Chip3.png");
	textures.load(TextureID::Chip4, "Media/Textures/Chip4.png");
	textures.load(TextureID::Chip5, "Media/Textures/Chip5.png");
	textures.load(TextureID::ChipStar, "Media/Textures/ChipStar.png");
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
	currentBidField->setPosition(worldView.getCenter().x - 30, 90);

	currentBid = currentBidField.get();
	sceneLayers[TableLayer]->attachChild(std::move(currentBidField));

	//Error Message for user
	std::unique_ptr<TextNode> errorMessageField(new TextNode(fonts, ""));
	errorMessageField->setPosition(worldView.getCenter().x - 30, 30);

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

void World::drawSandTimer(int player)
{
	if (player == 1)
		target.draw(*clock);
	else if (player == 2)
		target.draw(*clock2);
}

void World::drawCup()
{
	target.draw(*cup);
	target.draw(*cup2);
}

void World::drawChip()
{
	chip->setScale(0.4, 0.4);
	target.draw(*chip);
}

void World::moveChip(Bid bid)
{
	float currentPosX = chip->getPosition().x;
	float currentPosY = chip->getPosition().y;
	float currentAngle = chip->getRotation();

	if (currentPosX != newChipPosition.x)										// move x position
		chip->setPosition(currentPosX += dx / 40.f, currentPosY);
	if (currentPosY != newChipPosition.y)										// move y position
		chip->setPosition(currentPosX, currentPosY += dy / 40.f);
	if (chip->getRotation() != newChipAngle)									// move rotation
		chip->setRotation(currentAngle += dAngle);

	if (abs(currentPosX - newChipPosition.x) < 10.f && abs(currentPosY - newChipPosition.y) < 10.f) {
		chip->setPosition(newChipPosition);
		setChipRotation(bid.getNumber());
		setChipTexture(bid.getFace());
	}

	//if (bid.getFace() != Dice::Face::Star) {
	//	setChipPosition(bid.getNumber());
	//	setChipRotation(bid.getNumber());
	//	setChipTexture(bid.getFace());
	//}
	//else
	//	setStarChip(bid.getNumber());
}

void World::setChipPosition(int number)
{
	sf::Vector2f pos = Board::BidPositions.find(number)->second;
	chip->setPosition(pos);
}

void World::setChipRotation(int number)
{
	float rot = Board::BidRotations.find(number)->second;
	chip->setRotation(rot);
}

void World::setChipTexture(Dice::Face face)
{
	switch (face) {
		case Dice::Face::One:
			chip->setTexture(textures.get(TextureID::Chip1));
			break;
		case Dice::Face::Two:
			chip->setTexture(textures.get(TextureID::Chip2));
			break;
		case Dice::Face::Three:
			chip->setTexture(textures.get(TextureID::Chip3));
			break;
		case Dice::Face::Four:
			chip->setTexture(textures.get(TextureID::Chip4));
			break;
		case Dice::Face::Five:
			chip->setTexture(textures.get(TextureID::Chip5));
			break;
		default:
			chip->setTexture(textures.get(TextureID::ChipStar));
	}
}

void World::setStarChip(int number)
{
	sf::Vector2f pos = Board::BidStarsPositions.find(number)->second;
	chip->setPosition(pos);

	float rot = Board::BidStarsRotations.find(number)->second;
	chip->setRotation(rot);

	chip->setTexture(textures.get(TextureID::ChipStar));
}

void World::setChipNewPosition(Bid bid)
{
	if (bid.getFace() != Dice::Face::Star)
		newChipPosition = sf::Vector2f(Board::BidPositions.find(bid.getNumber())->second);
	else 
		newChipPosition = sf::Vector2f(Board::BidStarsPositions.find(bid.getNumber())->second);

	dx = newChipPosition.x - chip->getPosition().x;
	dy = newChipPosition.y - chip->getPosition().y;
}

sf::Vector2f World::getChipPosition()
{
	return chip->getPosition();
}

sf::Vector2f World::getNewChipPosition()
{
	return newChipPosition;
}

void World::setNewChipAngle(Bid bid)
{
	if (bid.getFace() != Dice::Face::Star)
		newChipAngle = Board::BidRotations.find(bid.getNumber())->second;
	else
		newChipAngle = Board::BidStarsRotations.find(bid.getNumber())->second;

	dAngle = newChipAngle - chip->getRotation();
}

float World::getNewChipAngle()
{
	return newChipAngle;
}