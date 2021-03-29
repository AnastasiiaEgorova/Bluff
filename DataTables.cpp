#include "DataTables.h"

std::map<Actor::Type, AbedData> initializeAbedData()
{
	std::map<Actor::Type, AbedData> data;

	data[Actor::Type::Abed].texture = TextureID::Abed;
	
	JsonFrameParser frames = JsonFrameParser("Media/Textures/Abed.json");

	data[Actor::Type::Abed].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle")); //TODO change for addFrameSet later
	data[Actor::Type::Abed].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Abed].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Abed].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think")); //TODO change for addFrameSet later
	data[Actor::Type::Abed].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::Abed].animations[Actor::State::Think].setRepeating(false);

	return data;
}