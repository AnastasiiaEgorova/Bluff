#pragma once
#include <SFML/System/NonCopyable.hpp>

namespace sf {
	class RenderTarget;
	class RenderTexture;
	class Shader;
}

class PostEffect : sf::NonCopyable
{
public:
	virtual					~PostEffect();
	virtual void			apply(const sf::RenderTexture& input, sf::RenderTarget& output) = 0;	

	// static because depends on Graphic Card of machine
	static bool				isSupported(); 

protected:
	static void				applyShader(const sf::Shader& shader, sf::RenderTarget& output);
};

