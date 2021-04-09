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
        Abed, 
        Drake, 
        Bender, 
        Dean, 
        TroyAndAbed,
        Brittasaurus,

        Dice1,
        Dice2,
        Dice3,
        Dice4,
        Dice5,
        DiceStar,

        Count
    };

    enum class State {
        Idle, Think, Count
    };

public:
    Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts);
    ~Actor() = default;

    void                            setState(State state);
    Actor::State                    getState() const;

private:
    void                            updateStates();
    void                            updateCurrent(sf::Time dt, CommandQueue& commands);
    void                            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Type                            type_;
    State                           state_;
    mutable sf::Sprite              sprite_;
    std::map<State, Animation>      animations_;
    //TextNode* healthDisplay_;
};


