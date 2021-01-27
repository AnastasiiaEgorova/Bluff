#include "Player.h"
#include "Commandqueue.h"
#include <algorithm>

Player::Player()
	: currentMissionStatus(MissionStatus::Running)
{
	// bindings
	initializeKeyBindings();
	initializeActions();
}

void Player::initializeKeyBindings()
{   // map from key to action
	keyBindings[sf::Keyboard::Left] = Action::MoveLeft;
	keyBindings[sf::Keyboard::Right] = Action::MoveRight;
	keyBindings[sf::Keyboard::Up] = Action::MoveUp;
	keyBindings[sf::Keyboard::Down] = Action::MoveDown;
	keyBindings[sf::Keyboard::Space] = Action::Fire;
	keyBindings[sf::Keyboard::M] = Action::LaunchMissile;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
}


void Player::setMissionStatus(MissionStatus status)
{
	currentMissionStatus = status;
}

Player::MissionStatus Player::getMissionStatus() const
{
	return currentMissionStatus;
}

void Player::initializeActions()
{

}

