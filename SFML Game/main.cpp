#include "Include\Game.hpp"
#include "MENU.hpp"
#include "Options.hpp"

#include <stdexcept>
#include <iostream>

sf::Event event;
std::string str;
void PlayerEingabeThread();


int main()
{
	try
	{
		// Übergibt an Menue und Optionen die größe des Fensters.
		int Auswahl = 0;
		// Erstellt ein Fenster mit der größe 600x600.
		sf::RenderWindow window(sf::VideoMode(600, 600), "Game Menü");
		Menu Menü(window.getSize().x, window.getSize().y);
		Options Optionen(window.getSize().x, window.getSize().y);

		// Solange das Fenster Offen ist.
		while (window.isOpen())
		{

			while (window.pollEvent(event))
			{
				// Event Switch in dem Alle wichtigen Events registriert werden.
				switch (event.type)
				{
				// Event wenn eine Taste gerückt wurde.
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						{
							if(Auswahl == 0)
								Menü.MoveUp();
							else
								Optionen.MoveUp();
							break;
						}
					case sf::Keyboard::Down:
						{
							if(Auswahl == 0)
								Menü.MoveDown();
							else
								Optionen.MoveDown();
							break;
						}
					case sf::Keyboard::Right:
						{
							if(Auswahl != 0)
							{
								Optionen.changeRight();
							}
							break;
						}
					case sf::Keyboard::Left:
						{
							if(Auswahl != 0)
							{
								// ChangeLEft
							}
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
										Game game(Optionen.getWindowX(), Optionen.getWindowY(), Optionen.getAliasing());
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
							// Optionen sind geöffnet.
							else
							{
								switch(Optionen.GetPressedItem())
								{
									// Enter auf Spielername
									case 0:
									{
										sf::Thread thread(&PlayerEingabeThread);
										thread.launch();
										Optionen.setPlayerName(str);
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
			if(Auswahl == 0)
				window.draw(Menü);
			else
				window.draw(Optionen);
			window.display();
		}
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}

void PlayerEingabeThread()
{
	if (event.type == sf::Event::TextEntered)
	{
        //Alle Tasten außer "Backspace" (ASCII-Wert 8) erlauben
        if (event.text.unicode < 8 || (event.text.unicode > 8 && event.text.unicode < 128))
		{
			//Maximal 16 Zeichen bei Namenseingabe!
			if (static_cast<int>(str.length()) < 16)
			{
				str += static_cast<char>(event.text.unicode);
			}
			//falls "Backspace" gedrückt...
			else if (event.text.unicode == 8)
			{
				//...prüfe erstmal, ob Name nicht schon leer ist!
				if (!static_cast<int>(str.length()) == 0)
				{
					//wenn nicht, dann lösche das letzte Zeichen des Strings "str"
					str.erase(str.end() - 1);
				}
			}
		}
	}
	if(event.type == sf::Keyboard::Return)
	{
		return;
	}
}