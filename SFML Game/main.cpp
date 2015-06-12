#include "Game.hpp"
#include "MENU.hpp"
#include "Options.hpp"
#include "XMLHandler.hpp"
#include "Ranking.hpp"
#include <stdexcept>
#include <iostream>

sf::Event event;

int main()
{
	try
	{
		// Übergibt an Menue und Optionen die größe des Fensters.
		int Auswahl = 0;
		bool Eingabe = false;

		// Background erstellen.
		sf::Texture Background;
		sf::Sprite BackgroundSprite;
		
		if (!Background.loadFromFile("Resources/Background/Aura.jpg"))
		{
			// error...
		}
		BackgroundSprite.setTexture(Background);

		// Erstellt ein Fenster mit der größe 600x600.
		sf::RenderWindow window(sf::VideoMode(600, 600), "Game Menü");
		Options Optionen(window.getSize().x, window.getSize().y);
		Menu Menü(window.getSize().x, window.getSize().y);
		XMLHandler XMLDoc;
		Ranking Rank;

		// Setzen eines Framelimits
		window.setFramerateLimit(60);
		// Solange das Fenster Offen ist.
		while (window.isOpen())
		{
			// Event Handler (Abfragen)
			while (window.pollEvent(event))
			{
				// Event Switch in dem Alle wichtigen Events registriert werden.
				switch (event.type)
				{
				case sf::Event::TextEntered:
				{
					if(Eingabe == true)
					{
						//Alle Tasten außer "Backspace" (ASCII-Wert 8) und Enter (ASCII-Wert 13) erlauben
						if (event.text.unicode < 8 || (event.text.unicode > 8 && event.text.unicode < 128 && event.text.unicode != 13))
						{
							//Maximal 16 Zeichen bei Namenseingabe!
							if (static_cast<int>(XMLDoc.loadPlayerName().length()) < 13)
							{
								Optionen.setPlayerNameChar(static_cast<char>(event.text.unicode));
							}
							
						}
						// falls "Backspace" gedrückt...
						if (event.text.unicode == 8)
						{
							//...prüfe erstmal, ob Name nicht schon leer ist!
							if (!static_cast<int>(XMLDoc.loadPlayerName().length()) == 0)
							{
								//wenn nicht, dann lösche das letzte Zeichen des Strings "str"
								Optionen.delPlayerNameChar();
							}
						}
					}
					break;
				}
				// Event wenn eine Taste gerückt wurde.
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						{
							if(Eingabe == false)
							{
								if(Auswahl == 0)
									Menü.MoveUp();
								else
									Optionen.MoveUp();
							}
							break;
						}
					case sf::Keyboard::Down:
						{
							if(Eingabe == false)
							{
								if(Auswahl == 0)
									Menü.MoveDown();
								else
									Optionen.MoveDown();
							}
							break;
						}
					case sf::Keyboard::Right:
						{
							if(Auswahl != 0)
							{
								Optionen.changeRight();
							}
							else
							{
								Menü.changePlayerRight();
							}
							break;
						}
					case sf::Keyboard::Left:
						{
							if(Auswahl != 0)
							{
								Optionen.changeLeft();
							}
							else
							{
								Menü.changePlayerLeft();
							}
							break;
						}
					// Eventfall für Enter drücken.
					case sf::Keyboard::Return:
						{
							// Wenn das Menü Offen ist.
							if(Auswahl == 0)
							{
								switch(Menü.GetPressedItem())
								{
									// Einzelspieler Start.
									case 0:
									{
										window.close();
										Game game(XMLDoc.loadWinX(), XMLDoc.loadWinY(), XMLDoc.loadAliasing(), Menü.getPlayerModel());
										game.run();
										break;
									}
									// Multiplayer Start.
									case 1:
									{
										break;
									}
									case 2:
									{	
										Auswahl = 2;
										window.draw(Rank);
										break;
									}
									// Optionen eingeben.
									case 3:
									{
										Auswahl = 3;
										window.draw(Optionen);
										break;
									}
									case 4:
									{
										window.close();
										break;
									}
								}
							}
							// Optionen sind geöffnet.
							else
							{
								switch(Optionen.GetPressedItem())
								{
									// Enter auf Spielername
									case 0:
									{
										if(Eingabe == true)
											Eingabe = false;
										else
											Eingabe = true;
										break;
									}
									case 7:
									{
										Auswahl = 0;
										break;
									}
								}
							}
							break;
						}
					}
					break;
				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			window.clear(sf::Color::Black);
			window.draw(BackgroundSprite);
			// Drawn von Optionen oder Menü bild.
			if(Auswahl == 0)
				window.draw(Menü);
			else if(Auswahl == 2)
				window.draw(Rank);
			else
				window.draw(Optionen);
			window.display();
		}
	}
	// Fehler werden abgefangen und in der Console angezeigt.
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}