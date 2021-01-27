#include "SceneNode.h"
#include "Category.h"
#include "Utility.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

SceneNode::SceneNode(Category::Type category)
    : children()
    , parent(nullptr)
    , defaultCategory(category)
{
}

void SceneNode::attachChild(Ptr child)
{
    child->parent = this;
    children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(children.begin(), children.end(),
        [&node](Ptr& p) {return p.get() == &node; });

    assert(found != children.end());

    Ptr result = std::move(*found);
    result->parent = nullptr;
    children.erase(found);

    return result;
}

sf::FloatRect SceneNode::getBoundingRect() const
{
    return sf::FloatRect();
}

void SceneNode::update(sf::Time dt, CommandQueue& commands)
{
    updateCurrent(dt, commands);
    updateChildren(dt, commands);
}

sf::Vector2f SceneNode::getWorldPosition() const
{
    return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
    // represents identity transform which doesn't effect the object
    sf::Transform tx = sf::Transform::Identity;

    // multiplies all objects from root to current node
    for (const SceneNode* node = this; node != nullptr; node = node->parent) {
        tx = node->getTransform() * tx;
    }

    return tx;
}

void SceneNode::onCommand(const Command& command, sf::Time dt)
{
    if (command.category & getCategory()) {
        command.action(*this, dt);
    }

    for (Ptr& c : children) {
        c->onCommand(command, dt);
    }
}

unsigned int SceneNode::getCategory() const
{
    return defaultCategory;
}

// invokes checkNodeCollision recursively for all children of node
void SceneNode::checkSceneCollision(SceneNode& node, std::set<Pair>& collisionPairs)
{
    checkNodeCollision(node, collisionPairs);

    for (Ptr& child : node.children)
        checkSceneCollision(*child, collisionPairs);
}

// evaluates a collision between *this(node) and all its children
void SceneNode::checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs)
{
    if (this != &node && isColliding(*this, node) && !isDestroyed() && !node.isDestroyed())
        collisionPairs.insert(std::minmax(this, &node));

    for (Ptr& child : children)
        child->checkNodeCollision(node, collisionPairs);
}

void SceneNode::removeWrecks()
{
    // remove all children with request so
    auto wreckfieldBegin = std::remove_if(children.begin(), children.end(), std::mem_fn(&SceneNode::isMarkedForRemoval));
    children.erase(wreckfieldBegin, children.end());

    // Call function recursively for all remaining children
    std::for_each(children.begin(), children.end(), std::mem_fn(&SceneNode::removeWrecks));
}

bool SceneNode::isMarkedForRemoval() const
{
    return isDestroyed();
}

bool SceneNode::isDestroyed() const
{
    return false;
}

void SceneNode::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    // default do nothing
    // to be overridden by derived classes that want update
}

void SceneNode::updateChildren(sf::Time dt, CommandQueue& commands)
{
    for (auto& child : children) {
        child->update(dt, commands);
    }
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // states has an attribute transform of type sf::Transform. It holds the information where to render the parent scene node
    states.transform *= getTransform();

    // draw current node and it's children
    drawCurrent(target, states);
    drawChildren(target, states);

    // draw bounding rectangle
    //drawBoundingRect(target, states);
}

void SceneNode::drawBoundingRect(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::FloatRect rect = getBoundingRect();

    sf::RectangleShape shape;
    shape.setPosition(sf::Vector2f(rect.left, rect.top));
    shape.setSize(sf::Vector2f(rect.width, rect.height));
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Green);
    shape.setOutlineThickness(1.f);

    target.draw(shape);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    // do nothing by default
    // to be overridden where needed
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& child : children) {
        child->draw(target, states);
    }
}

float calculateDistance(const SceneNode& lhs, const SceneNode& rhs)
{
    return length(lhs.getWorldPosition() - rhs.getWorldPosition());
}

bool isColliding(const SceneNode& lhs, const SceneNode& rhs)
{
    return lhs.getBoundingRect().intersects(rhs.getBoundingRect());
}
