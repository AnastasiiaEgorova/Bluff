#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include <map>
#include <vector>
#include <functional>

#include "ResourceIdentifiers.h"
#include "JsonFrameParser.h"
#include "Actor.h"

struct ActorData {
	TextureID							texture;
	std::map<Actor::State, Animation>	animations;
};

std::map<Actor::Type, ActorData> initializeActorData();



