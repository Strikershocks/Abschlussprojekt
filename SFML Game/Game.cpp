#include "Include\Game.hpp"
#include "Include\StringHelpers.hpp"

// Spieler Geschwindigkeit + TimePerFrame
const float Game::PlayerSpeed = 800.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game(): Window(sf::VideoMode(640, 480), "Test Game", sf::Style::Close)
{
	// Standard Werte Setzen.
	Texture;
	Player;
	Font;
	StatisticsText;
	StatisticsUpdateTime;
	StatisticsNumFrames = 0;
	IsMovingUp = false;
	IsMovingDown = false;
	IsMovingRight = false;
	IsMovingLeft = false;

	// Textur wird geladen.
	if (!Texture.loadFromFile("Resources/Textures/playerball.png"))
	{
		// Loading Error der PNG
	}

	// Setzen der Texture für den Spieler
	Player.setTexture(Texture);
	// Setzen der Position für den Spielen.
	Player.setPosition(100.f, 100.f);
	// Schrift Art laden und Eigenschaften Setzen.
	Font.loadFromFile("Resources/Sansation.ttf");
	StatisticsText.setFont(Font);
	StatisticsText.setPosition(5.f, 5.f);
	StatisticsText.setCharacterSize(10);
}

// Game Start Methode.
void Game::run()
{
	sf::Clock clock; // Initalisierung einer Uhr
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (Window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

// Eventhandler der die Ganzen Events verwaltet.
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

//
void Game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (IsMovingUp)
		movement.y -= PlayerSpeed;
	if (IsMovingDown)
		movement.y += PlayerSpeed;
	if (IsMovingLeft)
		movement.x -= PlayerSpeed;
	if (IsMovingRight)
		movement.x += PlayerSpeed;
		
	Player.move(movement * elapsedTime.asSeconds());
}

void Game::render()
{
	Window.clear();	
	Window.draw(Player);
	//Window.draw(mBackground);
	Window.draw(StatisticsText);
	Window.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	StatisticsUpdateTime += elapsedTime;
	StatisticsNumFrames += 1;

	if (StatisticsUpdateTime >= sf::seconds(1.0f))
	{
		StatisticsText.setString(
			"Frames / Second = " + toString(StatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(StatisticsUpdateTime.asMicroseconds() / StatisticsNumFrames) + "us");
							 
		StatisticsUpdateTime -= sf::seconds(1.0f);
		StatisticsNumFrames = 0;
	}
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
