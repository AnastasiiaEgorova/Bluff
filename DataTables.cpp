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

	//data[Actor::Type::Bender].texture = TextureID::Bender;

	//frames = JsonFrameParser("Media/Textures/Bender.json");

	//data[Actor::Type::Bender].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle"));
	//data[Actor::Type::Bender].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	//data[Actor::Type::Bender].animations[Actor::State::Idle].setRepeating(true);

	//data[Actor::Type::Bender].animations[Actor::State::Think].addFrameSet(frames.getFramesFor("think"));
	//data[Actor::Type::Bender].animations[Actor::State::Think].setDuration(sf::seconds(2.f));
	//data[Actor::Type::Bender].animations[Actor::State::Think].setRepeating(false);

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

	data[Actor::Type::Dice1].texture = TextureID::Dice;

	frames = JsonFrameParser("Media/Textures/dice.json");

	data[Actor::Type::Dice1].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle1"));
	data[Actor::Type::Dice1].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dice1].animations[Actor::State::Idle].setRepeating(true);

  	data[Actor::Type::Dice1].animations[Actor::State::Roll].addFrameSet(frames.getFramesFor("roll_1"));
	data[Actor::Type::Dice1].animations[Actor::State::Roll].setDuration(sf::seconds(1.2f));
	data[Actor::Type::Dice1].animations[Actor::State::Roll].setRepeating(false);

	data[Actor::Type::Dice2].texture = TextureID::Dice;

	//frames = JsonFrameParser("Media/Textures/dice.json");

	data[Actor::Type::Dice2].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle2"));
	data[Actor::Type::Dice2].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dice2].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Dice2].animations[Actor::State::Roll].addFrameSet(frames.getFramesFor("roll_2"));
	data[Actor::Type::Dice2].animations[Actor::State::Roll].setDuration(sf::seconds(1.5f));
	data[Actor::Type::Dice2].animations[Actor::State::Roll].setRepeating(false);


	data[Actor::Type::Dice3].texture = TextureID::Dice;

	data[Actor::Type::Dice3].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle3"));
	data[Actor::Type::Dice3].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dice3].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Dice3].animations[Actor::State::Roll].addFrameSet(frames.getFramesFor("roll_3"));
	data[Actor::Type::Dice3].animations[Actor::State::Roll].setDuration(sf::seconds(1.7f));
	data[Actor::Type::Dice3].animations[Actor::State::Roll].setRepeating(false);

	data[Actor::Type::Dice4].texture = TextureID::Dice;

	data[Actor::Type::Dice4].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle4"));
	data[Actor::Type::Dice4].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dice4].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Dice4].animations[Actor::State::Roll].addFrameSet(frames.getFramesFor("roll_4"));
	data[Actor::Type::Dice4].animations[Actor::State::Roll].setDuration(sf::seconds(1.f));
	data[Actor::Type::Dice4].animations[Actor::State::Roll].setRepeating(false);

	data[Actor::Type::Dice5].texture = TextureID::Dice;

	data[Actor::Type::Dice5].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idle5"));
	data[Actor::Type::Dice5].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::Dice5].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::Dice5].animations[Actor::State::Roll].addFrameSet(frames.getFramesFor("roll_5"));
	data[Actor::Type::Dice5].animations[Actor::State::Roll].setDuration(sf::seconds(1.4f));
	data[Actor::Type::Dice5].animations[Actor::State::Roll].setRepeating(false);

	data[Actor::Type::DiceStar].texture = TextureID::Dice;

	data[Actor::Type::DiceStar].animations[Actor::State::Idle].addFrameSet(frames.getFramesFor("idlestar"));
	data[Actor::Type::DiceStar].animations[Actor::State::Idle].setDuration(sf::seconds(2.f));
	data[Actor::Type::DiceStar].animations[Actor::State::Idle].setRepeating(true);

	data[Actor::Type::DiceStar].animations[Actor::State::Roll].addFrameSet(frames.getFramesFor("roll_star"));
	data[Actor::Type::DiceStar].animations[Actor::State::Roll].setDuration(sf::seconds(1.2f));
	data[Actor::Type::DiceStar].animations[Actor::State::Roll].setRepeating(false);

	return data;
}