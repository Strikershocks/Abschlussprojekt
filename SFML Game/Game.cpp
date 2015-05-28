#include "Include\Game.hpp"
#include "Include\StringHelpers.hpp"
#include <iostream>
// Spieler Geschwindigkeit + TimePerFrame
const float Game::PlayerSpeed = 200.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

sf::ContextSettings settings;
// set up AnimatedSprite
 AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);

Game::Game(int x, int y, int Aliasing, std::string PlayerModel) : Window(sf::VideoMode(x, y), "Test Game", sf::Style::Close, settings)
{
	settings.antialiasingLevel = Aliasing;

	// Standard Werte Setzen.
	Texture;
	Font;
	StatisticsUpdateTime;
	StatisticsNumFrames = 0;
	IsMovingUp = false;
	IsMovingDown = false;
	IsMovingRight = false;
	IsMovingLeft = false;
	noKeyWasPressed = true;

	// Setzen eines Frame Limits
	 Window.setFramerateLimit(60);

	// Textur wird geladen.
	if(!Texture.loadFromFile("Resources/Textures/" + PlayerModel )) 
	{
		// Loading Error der PNG
	}

	// Ausführung der Animations auswahl
	AnimationSelect(PlayerModel);

	// Setzen der Anfangsanimation
	currentAnimation = &walkingAnimationRight;

	// setzen der Fenster Dimision für die Animation.
	 sf::Vector2i screenDimensions(x, y);

	 // Setzen der Postion vom AnimationSprite
	 animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

	// Schrift Art laden
	if(!Font.loadFromFile("Resources/Sansation.ttf"))
	{
		// Error Handling
	}
}

// Game Start Methode.
void Game::run()
{
	// Initalisierung einer Uhr
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// Solange das Fenster Offen ist.
	while (Window.isOpen())
	{
		sf::Time frameTime = frameClock.restart();
		timeSinceLastUpdate += frameTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		// Starten der gewünschten Animation
		animatedSprite.play(*currentAnimation);
		// Bewegen der Spielfigur / Sprite
		animatedSprite.move(movement * frameTime.asSeconds());

		// Wenn keine Taste gedrückt, Animation stoppen.
		if (noKeyWasPressed)
        {
			animatedSprite.stop();
        }

		noKeyWasPressed = true;

		// Animation Updaten.
		animatedSprite.update(frameTime);
		render();
	}
}

// Event handler der die ganzen Events verwaltet.
void Game::processEvents()
{
	sf::Event event;
	while (Window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				Window.close();
				break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	movement.x = 0.f;
	movement.y = 0.f;

	// Wenn nach Oben laufen
	if (IsMovingUp)
		movement.y -= PlayerSpeed;

	// Wenn nach Unten laufen
	if (IsMovingDown)
		movement.y += PlayerSpeed;
		
	// Wenn Links laufen
	if (IsMovingLeft)
	{
		movement.x -= PlayerSpeed;
		currentAnimation = &walkingAnimationLeft;	
		noKeyWasPressed = false;
	}

	// Wenn Rechts laufen
	if (IsMovingRight)
	{
		movement.x += PlayerSpeed;
		currentAnimation = &walkingAnimationRight;
		noKeyWasPressed = false;
	}
}

void Game::render()
{
	Window.clear();	
	Window.draw(animatedSprite);
	//Window.draw(Background);
	Window.display();
}

// Input Handler für die Tastatureingaben.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		IsMovingUp = isPressed;
	else if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
		IsMovingDown = isPressed;
	else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
		IsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		IsMovingRight = isPressed;
}

// Animations auswahl nach Player auswahl.
void Game::AnimationSelect(std::string PlayerModel)
{
	if(PlayerModel != "HinagikuSprite.png")
	{
		// Animation setzen für Rechts Bewegen.
		walkingAnimationLeft.setSpriteSheet(Texture);
		walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
		walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

		// Animation setzen für Links Bewegen.
		walkingAnimationRight.setSpriteSheet(Texture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

	}
	else if(PlayerModel == "HinagikuSprite.png")
	{
		// Animation setzen für Rechts Bewegen.
		walkingAnimationLeft.setSpriteSheet(Texture);
		walkingAnimationLeft.addFrame(sf::IntRect(32, 48, 32, 48));
		walkingAnimationLeft.addFrame(sf::IntRect(64, 48, 32, 48));
		walkingAnimationLeft.addFrame(sf::IntRect(32, 48, 32, 48));
		walkingAnimationLeft.addFrame(sf::IntRect( 0, 48, 32, 48));

		// Animation setzen für Links Bewegen.
		walkingAnimationRight.setSpriteSheet(Texture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect(64, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect( 0, 96, 32, 48));
	}
}