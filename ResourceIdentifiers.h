#pragma once

// forward declaration of SFML classes
namespace sf {
	class Texture;
	class Font;
	class Shader;
	class SoundBuffer;
}

enum class EffectID
{
	AlliedGunfire,
	EnemyGunfire,
	Explosion1,
	Explosion2,
	LaunchMissile,
	CollectPickup,
	Button,
}; 

enum class MusicID
{
	MenuTheme,
	MissionTheme,
};

enum class TextureID {
	Table,
	Board,
	Dice1,
	Dice2,
	Dice3,
	Dice4,
	Dice5,
	DiceStar
};

enum class FontID {
	Main,
};

// forward declaration and a few type definition
template <typename Resource, typename Identifier>
class ResourceHolder;

using TextureHolder_t = ResourceHolder<sf::Texture, TextureID>;
using FontHolder_t = ResourceHolder<sf::Font, FontID>;
using SoundBufferHolder_t = ResourceHolder<sf::SoundBuffer, EffectID>;