/******************************************************************************
    Name: Siderunner Game C++ Projekt
    Autor: Stefanie Dautz, Niklas Kra�mann, Lukas Riebesel, Kai Blume
	Projektbetreuer: Herr Hunstock
    Datum: 30.06.2015
    Version: 1.5

    Beschreibung:
	Es handelt sich um ein Siderunner Jump and Run Game das
	mit C++ und der Grafikbibliothek SFML erstellt wird.
	Das Projekt dient als Werbema�name f�r die Schule.
	Es entsteht w�rend der Projektphase 2015 mit der Klasse B2IA13.

	Besonderheiten:
	- Ein paar Eastereggs f�r den Spieler

	Referenzen:
	- 
******************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
#include "Spieler.hpp"
#include "Map.hpp"
#include "Meldungen.hpp"
#include "XMLHandler.hpp"
#include <iostream>

class Game : private sf::NonCopyable
{
	public:
		Game(int x, int y, int Aliasing, std::string PlayerModel);
		void run();
		
	private:
		// Event handler
		void processEvents();

		//Gravitation nach Unten
		void GravityFall();

		// Gravitation nach Oben
		void GravityUp();

		// Update vom View
		void viewUpdate();

		// Maussteuerung
		void MausSteuerung(bool isPressed);

		// Aktualisieren Playerposition.
		void initPlayerPosition();

		// Sorgt f�r die eigentliche vortbewegung
		void update(sf::Time elapsedTime);

		// Render sorgt f�r das Drawn usw.
		void render();

		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		
		// Nicht ver�nderbare Spielergeschwindigkeit
		static const float PlayerSpeed, JumpSpeed, Gravity;
		static const sf::Time TimePerFrame;

		//einf�gen des XML Handlers.
		XMLHandler XMLDoc;

		// Laden der Welt
		Map World;

		// Laden der Meldungen
		Meldungen InfoFenster;

		// String f�r das SpielerModel
		std::string PlayerModel;

		// Laden des Spielers
		Spieler Player;

		sf::RenderWindow Window;
		sf::Font Font;
		sf::Clock frameClock;
		sf::Time frameTime;
		sf::Vector2f movement;

		// x und y von der Gr��e des Fensters
		int x, y;

		std::size_t StatisticsNumFrames;
		sf::View viewPlayer;
		sf::Vector2i localPositionMouse;
		bool IsMovingUp;
		bool IsMovingDown;
		bool IsMovingRight;
		bool IsMovingLeft;
		bool noKeyWasPressed;
		bool StopRechts;
		bool StopJump;
		bool StartJump;
		bool JumpHighest;
		bool StopUnten;
};

