#include "Include\Game.hpp"

// Spieler Geschwindigkeit + TimePerFrame
const float Game::PlayerSpeed = 200.f;
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
	//Player(PlayerModel, XMLDoc.loadPlayerName());

	// Standard Werte Setzen.
	Texture;
	Font;
	IsMovingUp = false;
	IsMovingDown = false;
	IsMovingRight = false;
	IsMovingLeft = false;
	StopLinks = false;
	StopOben = false;
	StopRechts = false;
	StopLinks = false;
	noKeyWasPressed = true;

	// Setzen eines Frame Limits
	 Window.setFramerateLimit(60);

	// Textur wird geladen.
	if(!Texture.loadFromFile("Resources/Textures/" + PlayerModel )) 
	{
		// Loading Error der PNG
	}
	Texture.setSmooth(true);

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
		initPlayerPosition();

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
						MausSteuerung();
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

	// Wenn nach Oben Springen
	if (IsMovingUp && StopOben != true)
	{
		movement.y -= PlayerSpeed;
	}

	// Wenn Rechts laufen
	if (IsMovingRight && StopRechts != true)
	{
		movement.x += PlayerSpeed;
		currentAnimation = &walkingAnimationRight;
		noKeyWasPressed = false;
	}
}

void Game::render()
{
	Window.clear();	
	Window.draw(World);
	Window.draw(animatedSprite);
	Window.display();
}

// Input Handler für die Tastatureingaben.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
		IsMovingUp = isPressed;
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		IsMovingRight = isPressed;
}

// Animations auswahl nach Player auswahl.
void Game::AnimationSelect(std::string PlayerModel)
{
	if(PlayerModel != "HinagikuSprite.png")
	{
		// Animation setzen für Rechts Bewegen.
		walkingAnimationRight.setSpriteSheet(Texture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));
	}
	else if(PlayerModel == "HinagikuSprite.png")
	{
		// Animation setzen für Rechts Bewegen.
		walkingAnimationRight.setSpriteSheet(Texture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect(64, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect( 0, 96, 32, 48));
	}
}

void Game::initPlayerPosition()
{
	// Damit bekommt man beide Postionen.
	PlayerX = animatedSprite.getPosition().x;
	PlayerY = animatedSprite.getPosition().y;
	World.set_player_pos(PlayerX, PlayerY);
}

void Game::MausSteuerung()
{
}