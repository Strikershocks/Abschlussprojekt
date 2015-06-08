#include "HintergrundSounds.hpp"
/*HintergrundSounds.cpp
**createdate: 03.06.2015
**author: Gamstudio™
**last update: 04.06.2015
**description:
**gesammelte Music und Sound-Aufrufe*/

HintergrundSounds::HintergrundSounds(void)
{this->GM = true;}

void HintergrundSounds::MenuMusic()
{
	std::string buffer;
	buffer = "Resources/sounds/CFC_0006.wav";	
	playMusic(buffer);	
}

void HintergrundSounds::GameMusic()
{
	std::string buffer;
	buffer = "Resources/sounds/CFC_0005.wav";	
	playMusic(buffer);
}

void HintergrundSounds::PlayerFall()
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Resources/sounds/CFC_0002.wav");	
	playEffects(&buffer);
}

void HintergrundSounds::PlayerDied()
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Resources/sounds/CFC_0936.wav");	
	//playEffects(&buffer);
	effects.setBuffer(buffer);
	effects.play();
	

}

void HintergrundSounds::PlayerJump()
{
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Resources/sounds/CFC_0004.wav");	
	playEffects(&buffer);
}

void HintergrundSounds::GameMusicOnOff()
{
	if(isGameMusic())
		GM = false;
	else
		GM = true;
}

bool HintergrundSounds::isGameMusic()
{return GM;}

void HintergrundSounds::stopMusic()
{
	music.stop();
}

void HintergrundSounds::playMusic(std::string pfad)
{	
	// Open it from an audio file
	if (!music.openFromFile(pfad))
	{
	// error...
	}
	
	music.setPosition(0, 1, 10); // change its 3D position
	music.setPitch(2); // increase the pitch
	music.setVolume(50);
	music.setLoop(true);
	music.play();	
}

void HintergrundSounds::playEffects(sf::SoundBuffer *buffer)
{	
	effects.setBuffer(*buffer);
	effects.play();
}