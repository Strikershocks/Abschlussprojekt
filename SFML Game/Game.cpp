#include "Game.hpp"

// Spieler Geschwindigkeit + TimePerFrame
const float Game::PlayerSpeed = 200.f;
const float Game::JumpSpeed = 100.0f;
const float Game::Gravity = 50;

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
sf::ContextSettings settings;

// set up AnimatedSprite
Game::Game(int x, int y, int Aliasing, std::string PlayerModel) : Window(sf::VideoMode(x, y), "Side Runner", sf::Style::Close, settings)
{
	settings.antialiasingLevel = Aliasing;
	this->x = x;
	this->y = y;
	//
	viewPlayer.setCenter(Player.getX()/2, Player.getY()/2);
	viewPlayer.setViewport(sf::FloatRect(0, 0, 1.75f, 1.75f));

	World.SetWindowSize(1 ,x, y);
	this->PlayerModel = PlayerModel;

	// Leben an Schwierigkeit anpassen.
	if(XMLDoc.loadSchwierigkeit() == "Mittel")
		this->Player.MinusLeben();
	else if(XMLDoc.loadSchwierigkeit() == "Schwer")
	{
		this->Player.MinusLeben();
		this->Player.MinusLeben();
	}

	// Standard Werte Setzen.
	Font;
	IsMovingUp = false;
	IsMovingDown = false;
	IsMovingRight = false;
	IsMovingLeft = false;
	StopJump = true;
	StartJump = false;
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
	Player.setName(XMLDoc.loadPlayerName());
	Player.setPosition(200,200);
	begin = clock();

	// Solange das Fenster Offen ist.
	while (Window.isOpen())
	{
		sf::Time frameTime = frameClock.restart();
		timeSinceLastUpdate += frameTime;
		initPlayerPosition();

		// Auswertung Kollision.
		if(World.checkKollision())
		{
			Player.MinusLeben();
		}

		// Überprüfung ob man gewonnen hat.
		if(World.checkGoal())
		{
			bool RankingSuccess = false;
			end = clock(); // Zeit messung ende.
			// Zeit in Sekunden ausrechnen.
			elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			// Zum Zeit in Int umwandeln für die Sekunden.
			if(checkRanking((int)elapsed_secs))
			{
				RankingSuccess = true;
			}
			Window.close();
			InfoFenster.Window_Success(RankingSuccess);
		}

		// Game Over wenn 0 Leben.
		if(Player.getLeben() == 0)
		{
			Window.close();
			InfoFenster.Abspann(600, 600);
		}

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
	
		// Gravitation erstellen.
		GravityFall();
		GravityUp();
		
		//Bewegung ausführen
		Player.AnimationTest(movement, frameTime, 0, PlayerModel);

		// View anpassen.
		viewUpdate();

		// Wenn keine Taste gedrückt, Animation stoppen.
		if (noKeyWasPressed)
        {
			Player.AnimationTest(movement, frameTime, 1, PlayerModel);
        }

		noKeyWasPressed = true;

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
			case sf::Event::MouseButtonReleased:
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

	// Wenn Rechts laufen
	if (IsMovingRight && StopRechts != true)
	{
		movement.x += PlayerSpeed;
		//Player.ChangeAnimation(1);
		noKeyWasPressed = false;
	}
}

void Game::render()
{
	Window.clear();	
	Window.setView(viewPlayer);
	Window.draw(World);
	Window.draw(Player);
	Window.display();
}

// Input Handler für die Tastatureingaben.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{	
	if (key == sf::Keyboard::W || key == sf::Keyboard::Up || key == sf::Keyboard::Space)
	{
		if(StopJump == true)
		{
			StartJump = true;
		}
		StopJump = false;
	}
	else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
		IsMovingRight = isPressed;
}

void Game::initPlayerPosition()
{
	sf::Vector2f PlayerCoords;
	PlayerCoords.x = Player.getX();
	PlayerCoords.y = Player.getY();
	World.set_player_pos(PlayerCoords);
}

void Game::MausSteuerung()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ==  true && StopJump == true)
	{
		StartJump = true;
		StopJump = false;
		
		return;
	}

	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) == true)
	{
		IsMovingRight = true;
		return;
	}else
	{
		IsMovingRight = false;
		return;
	}
}
void Game::GravityUp()
{
	// Wenn Sprung Gedrückt, solange nach Oben bis Sprungmax erreicht ist.
	if(StartJump == true)
	{
		if(Player.getY() - 32 > 200 || movement.y < 0)
		{
			movement.y -= JumpSpeed;
		}
		else
		{
			// Position kurz unter Höchsten Jump Punkt setzen.
			Player.setPosition(Player.getX(), 232);
			movement.y = 0;
			JumpHighest = true;
			StartJump = false;
		}
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
			// Postion über dem Boden Setzen.
			Player.setPosition(Player.getX(), 590);
			movement.y = 0;
			JumpHighest = false;
			StopJump = true;
		}
	}
}

void Game::viewUpdate()
{
	viewPlayer.setCenter(Player.getX() + 300, 520);
}

// Ranking prüfen und neues Ranking einstellen.
bool Game::checkRanking(float Zeit)
{
	std::string ZeitasString;
	float RankingZeitOld;
	for(int i = 0; i < 10; i++)
	{
		ZeitasString = XMLDoc.loadRanking(i + 1, 1);
		RankingZeitOld = atof(ZeitasString.c_str());
		// Wenn die Zeit besser ist als das Vorhanden Ranking dann Speichern.
		if(RankingZeitOld > Zeit)
		{
			XMLDoc.saveRanking(Player.getName(), Zeit, i+1);
			return true;
		}
	}
	return false;
}