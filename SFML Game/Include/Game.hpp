#pragma once

#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
#include "Spieler.hpp"
#include "Map.hpp"
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

		//Gravitation nach unten.
		void GravityFall();

		// Maussteuerung
		void MausSteuerung(bool isPressed);

		// Aktualisieren Playerposition.
		void initPlayerPosition();

		// Sorgt für die eigentliche vortbewegung
		void update(sf::Time elapsedTime);

		// Render sorgt für das Drawn usw.
		void render();

		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		
		// Nicht veränderbare Spielergeschwindigkeit
		static const float PlayerSpeed, JumpSpeed, Gravity;
		static const sf::Time TimePerFrame;

		//einfügen des XML Handlers.
		XMLHandler XMLDoc;

		// Laden der Welt
		Map World;

		// Laden des Spielers
		Spieler Player;

		sf::RenderWindow Window;
		sf::Font Font;
		sf::Clock frameClock;
		sf::Time frameTime;
		sf::Vector2f movement;

		// x und y von der Größe des Fensters
		int x, y;

		std::size_t StatisticsNumFrames;
		sf::Vector2i localPositionMouse;
		bool IsMovingUp;
		bool IsMovingDown;
		bool IsMovingRight;
		bool IsMovingLeft;
		bool noKeyWasPressed;
		bool StopRechts;
		bool blockJump;
		bool Jump;
		bool StopUnten;
		bool JumpHighest;
		int PlayerX;
		int PlayerY;
};

