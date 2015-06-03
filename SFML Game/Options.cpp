#include "Options.hpp"

Options::Options(float width, float height)
{
	// Standard Werte in die Variablen füllen.
	selectedItemIndex = 0;
	selectedWindowIndex = 0;
	PlayerName = XMLDoc.loadPlayerName();
	changeSizeXY();

	if (!font.loadFromFile("Resources/Sansation.ttf"))
	{
		// handle error
	}

	Option[0].setFont(font);
	Option[0].setColor(sf::Color::Red);
	Option[0].setString("Spielername: " + PlayerName);
	Option[0].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 1));

	Option[1].setFont(font);
	Option[1].setColor(sf::Color::White);
	Option[1].setString("Anti-Aliasing " + toString(XMLDoc.loadAliasing()));
	Option[1].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 2));

	Option[2].setFont(font);
	Option[2].setColor(sf::Color::White);
	Option[2].setString("Fenstergröße " + toString(xWindow) + 'x' + toString(yWindow));
	Option[2].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 3));

	Option[3].setFont(font);
	Option[3].setColor(sf::Color::White);
	Option[3].setString("Bestenliste zurücksetzen!");
	Option[3].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 4));

	Option[4].setFont(font);
	Option[4].setColor(sf::Color::White);
	Option[4].setString("Zurück");
	Option[4].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 5));
}


Options::~Options(void)
{
}

void Options::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		Option[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		Option[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_MENU_ITEMS)
	{
		Option[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		Option[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int Options::GetPressedItem()
{
	 return selectedItemIndex;
}

 void Options::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < MAX_MENU_ITEMS; i++)
	{
		target.draw(Option[i], states);
	}
}

 void Options::changeSizeXY()
 {
	 switch(selectedWindowIndex)
	 {
		case 0:
		{
			XMLDoc.saveWinXY(800, 600);
			break;
		}
		case 1:
		{
			XMLDoc.saveWinXY(1024, 768);
			break;
		}
	 } 
	 Option[2].setString("Fenstergröße " + toString(XMLDoc.loadWinX()) + 'x' + toString(XMLDoc.loadWinY()));
}

void Options::changeRight()
{
	switch(selectedItemIndex)
	{
		case 1:
		{
			if(XMLDoc.loadAliasing() < 16)
			{
				int Aliasing; // Aliasing int erstellen als kurzen zwischenspeicher.

				// Aliasing aktuellen Wert zuweisen und dann plus 1.
				Aliasing = XMLDoc.loadAliasing();
				Aliasing++;

				// Aliasing Stufe speichern.
				XMLDoc.saveAliasing(Aliasing);

				// Aliasing Stufe ausgeben.
				Option[1].setString("Anti-Aliasing " + toString(XMLDoc.loadAliasing()));
				break;
			}
			else
			{
				// Aliasing stufe auf 16 setzen und speichern.
				XMLDoc.saveAliasing(0);

				// Aliasing Stufe ausgeben.
				Option[1].setString("Anti-Aliasing " + toString(XMLDoc.loadAliasing()));
				break;
			}
		}
		case 2:
		{
			if(selectedWindowIndex < 1)
			{
				selectedWindowIndex++;
				changeSizeXY();
				break;
			}
			else
			{
				selectedWindowIndex = 0;
				changeSizeXY();
				break;
			}
		}
	} 
}

void Options::changeLeft()
{
	
	switch(selectedItemIndex)
	{
		case 1:
		{
			if(XMLDoc.loadAliasing() > 0)
			{
				int Aliasing; // Aliasing int erstellen als kurzen zwischenspeicher.

				// Aliasing aktuellen Wert zuweisen und dann minus 1.
				Aliasing = XMLDoc.loadAliasing();
				Aliasing--;

				// Aliasing Stufe speichern.
				XMLDoc.saveAliasing(Aliasing);

				// Aliasing Stufe ausgeben.
				Option[1].setString("Anti-Aliasing " + toString(XMLDoc.loadAliasing()));
				break;
			}
			else
			{
				// Aliasing stufe auf 16 setzen und speichern.
				XMLDoc.saveAliasing(16);

				// Aliasing Stufe ausgeben.
				Option[1].setString("Anti-Aliasing " + toString(XMLDoc.loadAliasing()));
				break;
			}
		}
		case 2:
		{
			if(selectedWindowIndex > 0)
			{
				selectedWindowIndex--;
				changeSizeXY();
				break;
			}
			else
			{
				selectedWindowIndex = 1;
				changeSizeXY();
				break;
			}
		}
	} 
}

void Options::setPlayerNameChar(char Char)
{
	// Fügt einen Char am Ende des Strings hinzu und Aktuallisiert die Anzeige
	PlayerName += Char;
	Option[0].setString("Spielername: " + PlayerName);
	XMLDoc.savePlayerName(PlayerName);
}

void Options::delPlayerNameChar()
{
	// Löscht den letzen Char vom String und Aktuallisiert die Anzeige.
	PlayerName.erase(PlayerName.end() - 1);
	Option[0].setString("Spielername: " + PlayerName);
}
