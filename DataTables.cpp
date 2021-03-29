#include "DataTables.h"

std::map<Actor::Type, AbedData> initializeAbedData()
{
	std::map<Actor::Type, AbedData> data;

	data[Actor::Type::Abed].texture = TextureID::Abed;
	
	JsonFrameParser frames = JsonFrameParser("Media/Textures/hero2.json");

	data[Actor::Type::Abed].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle")); //TODO change for addFrameSet later
	data[Actor::Type::Abed].animations[Actor::State::Idle].setDuration(sf::seconds(1.f));
	data[Actor::Type::Abed].animations[Actor::State::Idle].setRepeating(true);

	return data;
}