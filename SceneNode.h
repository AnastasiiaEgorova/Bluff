#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <memory>
#include <cassert>
#include <set>

#include "Command.h"
#include "Category.h"
//#include "CommandQueue.h"

class CommandQueue;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	using Ptr = std::unique_ptr<SceneNode>;
	using Pair = std::pair<SceneNode*, SceneNode*>;

public:
	SceneNode(Category::Type c = Category::Type::None);

	void					attachChild(Ptr child);
	Ptr						detachChild(const SceneNode& node);

	virtual sf::FloatRect	getBoundingRect() const;

	void					update(sf::Time dt, CommandQueue& commands);

	sf::Vector2f			getWorldPosition() const;												// to get absolute position
	sf::Transform			getWorldTransform() const;

	void					onCommand(const Command& command, sf::Time dt);
	virtual unsigned int	getCategory() const;

	void					checkSceneCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	void					checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);

	void					removeWrecks();

	virtual bool			isMarkedForRemoval() const;
	virtual bool			isDestroyed() const;

private:
	virtual void			updateCurrent(sf::Time dt, CommandQueue& commands);
	void					updateChildren(sf::Time dt, CommandQueue& commands);

	virtual void			draw(sf::RenderTarget& target, sf::RenderStates states) const;			// doesn't have to be public (see later)
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void					drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

	void					drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr>		children;
	SceneNode*				parent;						// raw ptr for parent because there is ownership
	Category::Type			defaultCategory;
};

float						calculateDistance(const SceneNode& lhs, const SceneNode& rhs);
bool						isColliding(const SceneNode& lhs, const SceneNode& rhs);

