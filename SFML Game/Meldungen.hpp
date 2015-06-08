#pragma once
/*Meldungen.hpp
**createdate: 04.06.2015
**author: Gamestudio™
**last update: 04.06.2015
**description:
**gesammelte Meldungen*/

#include <iostream>
#include "SFML/Graphics.hpp"


class Meldungen
{
public:
	Meldungen(void);

	void Window_Success();

	void Player_Died();

	void Window_failNetwork();

	void Window_failMusic();

	void Abspann(float, float);

private:
	void CreateMeldung(std::string Titel, std::string MeldungText);

};

