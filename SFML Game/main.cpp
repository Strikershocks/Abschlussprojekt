#include "Include\Game.hpp"
#include "MENU.hpp"
#include "Options.hpp"

#include <stdexcept>
#include <iostream>

int main()
{
	try
	{
		// Erstellt ein Fenster mit der größe 600x600.
		sf::RenderWindow window(sf::VideoMode(600, 600), "Game Menü");
		// Übergibt an Menue und Optionen die größe des Fensters.
		Menu Menü(window.getSize().x, window.getSize().y);
		Options Optionen(window.getSize().x, window.getSize().y);
		int Auswahl = 0;

		// Solange das Fenster Offen ist.
		while (window.isOpen())
		{
			sf::Event event;

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
						    switch(Menü.GetPressedItem())
							{
								// Einzelspieler Start.
								case 0:
								{
									window.close();
									Game game;
									game.run();
									break;
								}
								// Multiplayer Start.
								case 1:
								{
									break;
								}
								// Optionen eingeben.
								case 2:
								{
									break;
								}
								case 3:
								{
									Auswahl = 2;
									window.draw(Optionen);
									break;
								}
								case 4:
								{
									window.close();
									break;
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
