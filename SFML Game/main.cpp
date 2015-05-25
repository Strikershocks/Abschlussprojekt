#include "Include\Game.hpp"
#include "MENU.hpp"
#include "Options.hpp"

#include <stdexcept>
#include <iostream>

int main()
{
	try
	{
		// Erstellt ein Fenster mit der gr��e 600x600.
		sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");
		// �bergibt an Menue die gr��e des Fensters.
		Menu Men�(window.getSize().x, window.getSize().y);
		// Solange das Fenster Offen ist.
		while (window.isOpen())
		{
			sf::Event event;

			while (window.pollEvent(event))
			{
				// Event Switch in dem Alle wichtigen Events registriert werden.
				switch (event.type)
				{
					// Event wenn eine Taste ger�ckt wurde.
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
						{
							Men�.MoveUp();
							break;
						}
						case sf::Keyboard::Down:
						{
							Men�.MoveDown();
							break;
						}
						// Eventfall f�r Enter dr�cken.
						case sf::Keyboard::Return:
						{
							switch (Men�.GetPressedItem())
							{
								// Einzelspieler Start.
								case 0:
								{
									window.close();
									Game game;
									game.run();
									break;
								}
								case 1:
								{
									std::cout << "Option button has been pressed" << std::endl;
									break;
								}
								case 2:
								{
									Options Optionen(window.getSize().x, window.getSize().y);
									window.draw(Optionen);
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
			window.draw(Men�);
			window.display();
		}
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}
