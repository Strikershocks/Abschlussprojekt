#include "Include\Game.hpp"

// Spieler Geschwindigkeit + TimePerFrame
const float Game::PlayerSpeed = 200.f;
const float Game::JumpSpeed = 100.0f;
const float Game::Gravity = 50;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

sf::ContextSettings settings;
// set up AnimatedSprite
AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);

Game::Game(int x, int y, int Aliasing, std::string PlayerModel) : Window(sf::VideoMode(x, y), "Test Game", sf::Style::Close, settings)
{
	settings.antialiasingLevel = Aliasing;
	this->x = x;
	this->y = y;
	World.SetWindowSize(1 ,x, y);
	Spieler Player;

	Player.setModel(PlayerModel);
	Player.setName(XMLDoc.loadPlayerName());
	Player.initSpieler();

	// Standard Werte Setzen.
	Font;
	IsMovingUp = false;
	IsMovingDown = false;
	IsMovingRight = false;
	IsMovingLeft = false;
	Jump = false;
	blockJump = false;
	JumpHighest = false;
	StopRechts = false;
	noKeyWasPressed = true;

	// Setzen eines Frame Limits
	 Window.setFramerateLimit(60);

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
		initPlayerPosition();


		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		// Starten der gew�nschten Animation
		Player.StartAnimation();
	
		GravityFall();

		// Bewegen der Spielfigur / Sprite
		Player.BewegenSpieler(movement, frameTime);

		// Wenn keine Taste gedr�ckt, Animation stoppen.
		if (noKeyWasPressed)
        {
			Player.StopAnimation();
        }

		noKeyWasPressed = true;

		// Animation Updaten.
		Player.UpdateAnimation(frameTime);

		// Drawn des Games
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
				{
					if(XMLDoc.loadSteuerung() == "Tastatur")
					{
						handlePlayerInput(event.key.code, true);
						break;
					}
					break;
				}
			case sf::Event::KeyReleased:
				{
					if(XMLDoc.loadSteuerung() == "Tastatur")
					{
						handlePlayerInput(event.key.code, false);
						break;
					}
					break;
				}
			case sf::Event::MouseButtonPressed:
				{
					if(XMLDoc.loadSteuerung() == "Maus")
					{
						MausSteuerung(true);
						break;
					}
					break;
				}
			case sf::Event::MouseButtonReleased:
				{
					if(XMLDoc.loadSteuerung() == "Maus")
					{
						MausSteuerung(false);
						break;
					}
					break;
				}
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

	// Wenn Rechts laufen
	if (IsMovingRight && StopRechts != true)
	{
		movement.x += PlayerSpeed;
		Player.ChangeAnimation(1);
		noKeyWasPressed = false;
	}
}

void Game::render()
{
	Window.clear();	
	Window.draw(World);
	Window.draw(Player);
	Window.display();
}

// Input Handler f�r die Tastatureingaben.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
	{
		if(Jump == false)
		{
			Jump = true;
		}
	}
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		IsMovingRight = isPressed;
}

void Game::initPlayerPosition()
{
	// Der Welt wird die Spielerposition �bergeben.
	std::cout << Player.getX() << Player.getY() << std::endl;
	World.set_player_pos(Player.getX(), Player.getY());
}

void Game::MausSteuerung(bool isPressed)
{
	// Speichern der Mausposition X,Y im Fenster.
	localPositionMouse = sf::Mouse::getPosition(Window); 

	if(localPositionMouse.x > PlayerX && isPressed == true)
	{
		IsMovingRight = true;
		return;
	}
	else
	{
		IsMovingRight = false;
	}

	// Ansonsten Pr�fen ob die Maus weiter rechts als der Player ist.
	if(localPositionMouse.y < PlayerY + 10 && isPressed == true)
	{
		// Fehler liegt im Jump.
		if(blockJump == false)
		{
			Jump = true;
		}
		return;
	}
}

void Game::GravityFall()
{
	if(JumpHighest == true)
	{
		// 535 GroundY Position
		if(Player.getY() + 32 < 535 || movement.y < 0)
		{
			movement.y += Gravity;
		}
		else
		{
			// Postion �ber dem Boden Setzen.
			Player.SetAnimationPosition(Player.getX(),503);
			movement.y = 0;
			JumpHighest = false;
			Jump = false;
			blockJump = false;
		}
	}
	else if(Jump == true)
	{
		if(Player.getY() - 32 > 200 || movement.y < 0)
		{
			movement.y += JumpSpeed;
		}
		else
		{
			// Position kurz unter H�chsten Jump Punkt setzen.
			Player.SetAnimationPosition(Player.getX(), 232);
			movement.y = 0;
			JumpHighest = true;
		}
	}
}