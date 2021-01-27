#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <map>
#include <string>
#include <stdexcept>
#include <cassert>

enum class TextureID {
	Board,
	Dice
};

class TextureHolder
{
public:
	void				load(TextureID id, const std::string& filename);
	const sf::Texture&	get(TextureID id) const;

private:
	std::map<TextureID, std::unique_ptr<sf::Texture>> textureMap;
};


