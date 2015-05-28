#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"

class Game : private sf::NonCopyable
{
	public:
		Game(int x, int y, int Aliasing, std::string PlayerModel);
		void run();
		
	private:
		// Event handler
		void processEvents();

		// Animations auswahl nach Player auswahl.
		void AnimationSelect(std::string PlayerModel);

		// Sorgt für die eigentliche vortbewegung
		void update(sf::Time elapsedTime);

		// Render sorgt für das Drawn usw.
		void render();

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
		AnimatedSprite animatedSprite;

		sf::RenderWindow Window;
		sf::Texture Texture;
		sf::Sprite Player;
		sf::Font Font;
		sf::Time StatisticsUpdateTime;
		sf::Clock frameClock;
		sf::Time frameTime;
		sf::Vector2f movement;

		std::size_t StatisticsNumFrames;
		bool IsMovingUp;
		bool IsMovingDown;
		bool IsMovingRight;
		bool IsMovingLeft;
		bool noKeyWasPressed;
};

