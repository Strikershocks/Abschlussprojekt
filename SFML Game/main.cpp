#include "Include\Game.hpp"
#include "MENU.hpp"
#include "Options.hpp"
#include "XMLHandler.hpp"

#include <stdexcept>
#include <iostream>

sf::Event event;

int main()
{
	try
	{
		// �bergibt an Menue und Optionen die gr��e des Fensters.
		int Auswahl = 0;
		bool Eingabe = false;
		// Erstellt ein Fenster mit der gr��e 600x600.
		sf::RenderWindow window(sf::VideoMode(600, 600), "Game Men�");
		Options Optionen(window.getSize().x, window.getSize().y);
		Menu Men�(window.getSize().x, window.getSize().y);
		XMLHandler XMLDoc;

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
						//Alle Tasten au�er "Backspace" (ASCII-Wert 8) und Enter (ASCII-Wert 13) erlauben
						if (event.text.unicode < 8 || (event.text.unicode > 8 && event.text.unicode < 128 && event.text.unicode != 13))
						{
							//Maximal 16 Zeichen bei Namenseingabe!
							if (static_cast<int>(XMLDoc.loadPlayerName().length()) < 16)
							{
								Optionen.setPlayerNameChar(static_cast<char>(event.text.unicode));
							}
							
						}
						// falls "Backspace" gedr�ckt...
						if (event.text.unicode == 8)
						{
							//...pr�fe erstmal, ob Name nicht schon leer ist!
							if (!static_cast<int>(XMLDoc.loadPlayerName().length()) == 0)
							{
								//wenn nicht, dann l�sche das letzte Zeichen des Strings "str"
								Optionen.delPlayerNameChar();
							}
						}
					}
					break;
				}
				// Event wenn eine Taste ger�ckt wurde.
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						{
							if(Eingabe == false)
							{
								if(Auswahl == 0)
									Men�.MoveUp();
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
									Men�.MoveDown();
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
								Men�.changePlayerRight();
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
								Men�.changePlayerLeft();
							}
							break;
						}
					// Eventfall f�r Enter dr�cken.
					case sf::Keyboard::Return:
						{
							// Wenn das Men� Offen ist.
							if(Auswahl == 0)
							{
								switch(Men�.GetPressedItem())
								{
									// Einzelspieler Start.
									case 0:
									{
										window.close();
										Game game(XMLDoc.loadWinX(), XMLDoc.loadWinY(), XMLDoc.loadAliasing(), Men�.getPlayerModel());
										game.run();
										break;
									}
									// Multiplayer Start.
									case 1:
									{
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
							// Optionen sind ge�ffnet.
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
									case 4:
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
			// Drawn von Optionen oder Men� bild.
			if(Auswahl == 0)
				window.draw(Men�);
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