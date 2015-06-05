#include "Options.hpp"

Options::Options(float width, float height)
{
	// Standard Werte in die Variablen f�llen.
	selectedItemIndex = 0;
	PlayerName = XMLDoc.loadPlayerName();
	changeSizeXY();
	int i = 7;

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
	Option[2].setString("Fenstergr��e " + toString(XMLDoc.loadWinX()) + 'x' + toString(XMLDoc.loadWinY()));
	Option[2].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 3));

	Option[3].setFont(font);
	Option[3].setColor(sf::Color::White);
	Option[3].setString("Steuerung " + toString(XMLDoc.loadSteuerung()));
	Option[3].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 4));

	Option[4].setFont(font);
	Option[4].setColor(sf::Color::White);
	Option[4].setString("Musik " + toString(XMLDoc.loadMusic()));
	Option[4].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 5));

	Option[5].setFont(font);
	Option[5].setColor(sf::Color::White);
	Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));
	Option[5].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 6));

	if(PlayerName == "Gott")
	{
		Option[6].setFont(font);
		Option[6].setColor(sf::Color::White);
		Option[6].setString("Bestenliste zur�cksetzen!");
		Option[6].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 7));
		i++;
	}

	Option[7].setFont(font);
	Option[7].setColor(sf::Color::White);
	Option[7].setString("Zur�ck");
	Option[7].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * i));
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
	 switch(XMLDoc.loadWindowIndex())
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
	 Option[2].setString("Fenstergr��e " + toString(XMLDoc.loadWinX()) + 'x' + toString(XMLDoc.loadWinY()));
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
			if(XMLDoc.loadWindowIndex() < 1)
			{
				XMLDoc.saveWindowIndex(1);
				changeSizeXY();
				break;
			}
			else
			{
				XMLDoc.saveWindowIndex(0);
				changeSizeXY();
				break;
			}
		}
		case 3:
		{
			if(XMLDoc.loadSteuerung() == "Maus")
			{
				XMLDoc.saveSteuerung("Tastatur");
				Option[3].setString("Steuerung " + toString(XMLDoc.loadSteuerung()));
				break;
			}
			else
			{
				XMLDoc.saveSteuerung("Maus");
				Option[3].setString("Steuerung " + toString(XMLDoc.loadSteuerung()));
				break;
			}
		}
		case 4:
		{
			if(XMLDoc.loadMusic() == "An")
			{
				XMLDoc.saveMusic("Aus");
				Option[4].setString("Musik " + toString(XMLDoc.loadMusic()));
				break;
			}
			else
			{
				XMLDoc.saveMusic("An");
				Option[4].setString("Musik " + toString(XMLDoc.loadMusic()));
				break;
			}
		}
		case 5:
		{
			if(XMLDoc.loadSchwierigkeitIndex() < 2)
			{
				if(XMLDoc.loadSchwierigkeitIndex() == 0)
				{
					XMLDoc.saveSchwierigkeitIndex(1);
					XMLDoc.saveSchwierigkeit("Mittel");
					Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));
					break;
				}
				else
				{
					XMLDoc.saveSchwierigkeitIndex(2);
					XMLDoc.saveSchwierigkeit("Schwer");
					Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));			
					break;
				}
			}
			else
			{
				XMLDoc.saveSchwierigkeitIndex(0);
				XMLDoc.saveSchwierigkeit("Leicht");
				Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));
				break;
			}
		}
		case 6:
		{
			if(XMLDoc.loadPlayerName() == "Gott")
			{
				// Bestenliste zur�cksetzen.
				break;
			}
			break;
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
			if(XMLDoc.loadWindowIndex() > 0)
			{
				XMLDoc.saveWindowIndex(0);
				changeSizeXY();
				break;
			}
			else
			{
				XMLDoc.saveWindowIndex(1);
				changeSizeXY();
				break;
			}
		}
		case 3:
		{
			if(XMLDoc.loadSteuerung() == "Tastatur")
			{
				XMLDoc.saveSteuerung("Maus");
				Option[3].setString("Steuerung " + toString(XMLDoc.loadSteuerung()));
				break;
			}
			else
			{
				XMLDoc.saveSteuerung("Tastatur");
				Option[3].setString("Steuerung " + toString(XMLDoc.loadSteuerung()));
				break;
			}
		}
		case 4:
		{
			if(XMLDoc.loadMusic() == "Aus")
			{
				XMLDoc.saveMusic("An");
				Option[4].setString("Musik " + toString(XMLDoc.loadMusic()));
				break;
			}
			else
			{
				XMLDoc.saveMusic("Aus");
				Option[4].setString("Musik " + toString(XMLDoc.loadMusic()));
				break;
			}
		}
		case 5:
		{
			if(XMLDoc.loadSchwierigkeitIndex() > 0)
			{
				if(XMLDoc.loadSchwierigkeitIndex() == 2)
				{
					XMLDoc.saveSchwierigkeitIndex(1);
					XMLDoc.saveSchwierigkeit("Mittel");
					Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));
					break;
				}
				else
				{
					XMLDoc.saveSchwierigkeitIndex(0);
					XMLDoc.saveSchwierigkeit("Leicht");
					Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));			
					break;
				}
			}
			else
			{
				XMLDoc.saveSchwierigkeitIndex(2);
				XMLDoc.saveSchwierigkeit("Schwer");
				Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));
				break;
			}
		}
		case 6:
		{
			if(XMLDoc.loadPlayerName() == "Gott")
			{
				// Bestenliste zur�cksetzen.
				break;
			}
			break;
		}
	} 
}

void Options::setPlayerNameChar(char Char)
{
	// F�gt einen Char am Ende des Strings hinzu und Aktuallisiert die Anzeige
	PlayerName += Char;
	Option[0].setString("Spielername: " + PlayerName);
	XMLDoc.savePlayerName(PlayerName);
}

void Options::delPlayerNameChar()
{
	// L�scht den letzen Char vom String und Aktuallisiert die Anzeige.
	PlayerName.erase(PlayerName.end() - 1);
	Option[0].setString("Spielername: " + PlayerName);
}
