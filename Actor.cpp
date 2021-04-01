#include "Actor.h"
#include "DataTables.h"

namespace
{
	const std::map<Actor::Type, ActorData> TABLE = initializeAbedData();
}

Actor::Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts)
	: type_(type)
	, state_(State::Idle)
	, sprite_(textures.get(TABLE.at(type).texture))
{
	for (auto a : TABLE.at(type).animations)
	{
		animations_[a.first] = a.second;
	}

	sprite_.setTextureRect(sf::IntRect());
	centerOrigin(sprite_);

}

void Actor::setState(Actor::State state)
{
	state_ = state;
	animations_[state_].restart();
}

Actor::State Actor::getState() const
{
	return state_;
}

void Actor::updateStates()
{
	if (state_ == State::Think && animations_[state_].isFinished())
		state_ = State::Idle;
}

void Actor::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	updateStates();

	auto rec = animations_.at(state_).update(dt);

	sprite_.setTextureRect(rec);
	centerOrigin(sprite_);
}

void Actor::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_, states);
}

