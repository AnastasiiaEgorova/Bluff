#include "EmitterNode.h"

#include "ParticleNode.h"
#include "Command.h"
#include "CommandQueue.h"

EmitterNode::EmitterNode(Particle::Type type)
	: SceneNode()
	, accumulatedTime(sf::Time::Zero)
	, type(type)
	, particleSystem(nullptr)
{
}

void EmitterNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	if (particleSystem)				//if particle system has alredy been initialized
	{
		emitParticles(dt);
	}
	else                           //send command to find particle system in the graph
	{
		// Find particle node with the same type as emitter node
		auto finder = [this](ParticleNode& container, sf::Time)
		{
			if (container.getParticleType() == type)
				particleSystem = &container;
		};		
		
		Command command;
		command.category = Category::ParticleSystem;
		command.action = derivedAction<ParticleNode>(finder);		
		
		commands.push(command);
	}
}

void EmitterNode::emitParticles(sf::Time dt)
{
	const float EMISSION_RATE = 30.f;
	const sf::Time INTERVAL = sf::seconds(1.f) / EMISSION_RATE;

	accumulatedTime += dt;

	while (accumulatedTime > INTERVAL) {
		accumulatedTime -= INTERVAL;
		particleSystem->addParticle(getWorldPosition());
	}
}
