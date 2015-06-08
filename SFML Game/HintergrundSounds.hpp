#pragma once
/*HintergrundSounds.hpp
**createdate: 03.06.2015
**author: Gamstudio™
**last update: 04.06.2015
**description:
**gesammelte Music und Sound-Aufrufe*/
#include "SFML/Audio.hpp"

class HintergrundSounds
{
public:
	//setzt Game Hintergrundmusik auf true
	HintergrundSounds(void);
	
	//Hintergrundmusik im Hauptmenü
	void MenuMusic(void);
	
	//HintergrundMusik im Spiel
	void GameMusic(void);


	//SoundEffekt, wenn Spieler fällt
	void PlayerFall(void);

	//Soundeffekt, wenn Spieler stirbt
	void PlayerDied(void);

	//Soundeffekt, wenn Spieler springt
	void PlayerJump(void);

	//wechselt den Zustand der Game Hintergrundmusik (an/aus)
	void GameMusicOnOff(void);

	//gibt den Zustand der Game Hintergrundmusik zurück
	bool isGameMusic(void);
	
	//Stoppt die Hintergrundmusik
	void stopMusic(void);
private:
	//Spielt die Hintergrundmusik ab
	void playMusic(std::string pfad);

	//Spielt die Soundeffekte ab
	void playEffects(sf::SoundBuffer *buffer);

	//Hintergrundmusik
	sf::Music music;

	//Soundeffekte
	sf::Sound effects;

	//Zustand der Game Hintergrundmusik
	bool GM;
};

