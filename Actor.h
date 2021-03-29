#pragma once

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Animation.h"
#include "TextNode.h"
#include "JsonFrameParser.h"
#include "Utility.h"
#include "SceneNode.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class Actor : public SceneNode
{
public:
    enum class Type {
        Abed, Count
    };

    enum class State {
        Idle, Think, Count
    };

public:
    Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts);
    ~Actor() = default;

    //unsigned int                    getCategory() const;
    //sf::FloatRect                   getBoundingRect() const;
    //float                           getMaxSpeed() const;

    //bool                            isMarkedForRemoval() const;

    //void                            attack();
    void                            setState(State state);
    Actor::State                    getState() const;
    //int                             attackPoints() const;

private:
    void                            updateStates();
    //void                            updateForceField(sf::Time dt);
    void                            updateCurrent(sf::Time dt, CommandQueue& commands);
    void                            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    //void                            updateMovementPattern(sf::Time dt);
    //void                            updateTexts();

    //void             updateMovementPattern(sf::Time dt);

private:
    Type                            type_;
    State                           state_;
    mutable sf::Sprite              sprite_;
    std::map<State, Animation>      animations_;
    //TextNode* healthDisplay_;

    //float                           travelDistance_;
    //std::size_t                     directionIndex_;
    //bool                            attack_;
    //sf::Time                        forceFieldTimer_;
    //bool                            forceField_;
};


