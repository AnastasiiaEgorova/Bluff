#pragma once
#include <SFML/Window/Event.hpp>
#include "Command.h"
#include <map>

// forward declaration
class CommandQueue;

class Player
{
public:
	enum class Action {
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		Fire,
		LaunchMissile,
		ActionCount
	};

	enum class MissionStatus {
		Running,
		Success,
		Failure,
	};

public:
											Player();
	void									handleEvent(const sf::Event& event, CommandQueue& commands);

	void									setMissionStatus(MissionStatus status);
	MissionStatus							getMissionStatus() const;

private:
	void									initializeKeyBindings();
	void									initializeActions();

private:
	std::map<sf::Keyboard::Key, Action>		keyBindings;
	std::map<Action, Command>				actionBindings;
	MissionStatus							currentMissionStatus;
};

