#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

class Game : private sf::NonCopyable
{
	public:
		Game(int x, int y, int Aliasing, std::string PlayerModel);
		void run();
		
	private:
		void processEvents();
		void update(sf::Time elapsedTime);
		void render();

		void updateStatistics(sf::Time elapsedTime);	
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
		
		// Nicht veränderbare Spielergeschwindigkeit
		static const float PlayerSpeed;
		static const sf::Time TimePerFrame;

		// Animation für Links
		Animation walkingAnimationLeft;

		// Animation für Rechts
		Animation walkingAnimationRight;
		Animation* currentAnimation;
		// set up AnimatedSprite
		AnimatedSprite animatedSprite();

		sf::RenderWindow Window;
		sf::Texture Texture;
		sf::Sprite Player;
		sf::Font Font;
		sf::Text StatisticsText;
		sf::Time StatisticsUpdateTime;
		sf::Clock frameClock;
		sf::Time frameTime;

		std::size_t StatisticsNumFrames;
		bool IsMovingUp;
		bool IsMovingDown;
		bool IsMovingRight;
		bool IsMovingLeft;
};

