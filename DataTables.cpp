#include "DataTables.h"

std::map<Actor::Type, ActorData> initializeActorData()
{
	std::map<Actor::Type, ActorData> data;

	data[Actor::Type::Abed].texture = TextureID::Abed;
	
	JsonFrameParser frames = JsonFrameParser("Media/Textures/Abed.json");

	data[Actor::Type::Abed].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle")); 
	data[Actor::Type::Abed].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Abed].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Abed].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think")); 
	data[Actor::Type::Abed].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::Abed].animations[Actor::State::Think].setRepeating(false);

	data[Actor::Type::Drake].texture = TextureID::Drake;

	frames = JsonFrameParser("Media/Textures/Drake.json");

	data[Actor::Type::Drake].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle"));
	data[Actor::Type::Drake].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Drake].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Drake].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think"));
	data[Actor::Type::Drake].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::Drake].animations[Actor::State::Think].setRepeating(false);

	data[Actor::Type::Bender].texture = TextureID::Bender;

	frames = JsonFrameParser("Media/Textures/Bender.json");

	data[Actor::Type::Bender].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle"));
	data[Actor::Type::Bender].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Bender].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Bender].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think"));
	data[Actor::Type::Bender].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::Bender].animations[Actor::State::Think].setRepeating(false);

	data[Actor::Type::Dean].texture = TextureID::Dean;

	frames = JsonFrameParser("Media/Textures/Dean.json");

	data[Actor::Type::Dean].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle"));
	data[Actor::Type::Dean].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dean].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Dean].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think"));
	data[Actor::Type::Dean].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dean].animations[Actor::State::Think].setRepeating(false);

	data[Actor::Type::TroyAndAbed].texture = TextureID::TroyAndAbed;

	frames = JsonFrameParser("Media/Textures/TroyAbed.json");

	data[Actor::Type::TroyAndAbed].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle"));
	data[Actor::Type::TroyAndAbed].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::TroyAndAbed].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::TroyAndAbed].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think"));
	data[Actor::Type::TroyAndAbed].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::TroyAndAbed].animations[Actor::State::Think].setRepeating(false);

	data[Actor::Type::Brittasaurus].texture = TextureID::Brittasaurus;

	frames = JsonFrameParser("Media/Textures/Brittasaurus.json");

	data[Actor::Type::Brittasaurus].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle"));
	data[Actor::Type::Brittasaurus].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Brittasaurus].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Brittasaurus].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think"));
	data[Actor::Type::Brittasaurus].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	data[Actor::Type::Brittasaurus].animations[Actor::State::Think].setRepeating(false);

	return data;
}