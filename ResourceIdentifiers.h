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
	Eagle,
	Raptor,
	Avenger,
	Desert,
	Bullet,
	Missile,
	HealthRefill,
	MissileRefill,
	FireSpread,
	FireRate,
	TitleScreen,

	Entities,
	Jungle,
	Buttons,
	Explosion,
	Particle,
	FinishLine,
};

enum class FontID {
	Main,
};

enum class ShaderID {
	BrightnessPass,
	DownSamplePass,
	GaussianBlurPass,
	AddPass,
};

// forward declaration and a few type definition
template <typename Resource, typename Identifier>
class ResourceHolder;

using TextureHolder_t = ResourceHolder<sf::Texture, TextureID>;
using FontHolder_t = ResourceHolder<sf::Font, FontID>;
using ShaderHolder_t = ResourceHolder<sf::Shader, ShaderID>;
using SoundBufferHolder_t = ResourceHolder<sf::SoundBuffer, EffectID>;