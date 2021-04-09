#include "Player.h"
#include "Commandqueue.h"
#include <algorithm>

Player::Player()
{
	for (int i = 0; i < 5; ++i) {
		playersDice.push_back(Dice());
	}
}

std::vector<Dice> Player::showDice() 
{
	return playersDice;
}

//void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
//{
//	if (event.type == sf::Event::KeyPressed) {
//		// Check if pressed key appears in key binding, trigger command if so
//		auto found = keyBindings.find(event.key.code);
//
//		if (found != keyBindings.end() && !isRealTimeAction(found->second))
//			commands.push(actionBindings[found->second]);
//	}
//}

