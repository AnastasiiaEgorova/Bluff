#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
	: music()
	, filenames()
	, volume(100.f)
{
	filenames[MusicID::MenuTheme] = "Media/Music/Community_Piano.ogg";
	filenames[MusicID::GameTheme] = "Media/Music/Community_8bit.ogg";
	filenames[MusicID::DiceThrown] = "Media/Music/DiceThrown.ogg";
}

void MusicPlayer::play(MusicID theme)
{
	auto filename = filenames[theme];

	if (!music.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded");

	music.setVolume(volume);
	music.setLoop(true);
	music.play();
}

void MusicPlayer::stop()
{
	music.stop();
}

void MusicPlayer::setPause(bool paused)
{
	if (paused)
		music.pause();
	else
		music.play();
}

void MusicPlayer::setVolume(float v)
{
	volume = v;
}
