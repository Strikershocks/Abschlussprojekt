#include "Options.hpp"

Options::Options(float width, float height)
{
	// Standard Werte in die Variablen füllen.
	selectedItemIndex = 0;
	WinX = width;
	WinY = height;
	PlayerName = XMLDoc.loadPlayerName();
	changeSizeXY();
	int i = 7;

	if (!font.loadFromFile("Resources/Sansation.ttf"))
	{
		// handle error
	}

	for(int j = 0; j < MAX_MENU_ITEMS; j++)
	{
		Option[j].setFont(font);
		Option[j].setColor(sf::Color::White);
		Option[j].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * (j+1)));
	}


	Option[0].setColor(sf::Color::Red);
	Option[0].setString("Spielername: " + PlayerName);

	Option[1].setString("Anti-Aliasing " + toString(XMLDoc.loadAliasing()));

	Option[2].setString("Fenstergröße " + toString(XMLDoc.loadWinX()) + 'x' + toString(XMLDoc.loadWinY()));

	Option[3].setString("Steuerung " + toString(XMLDoc.loadSteuerung()));
	
	Option[4].setString("Musik " + toString(XMLDoc.loadMusic()));

	Option[5].setString("Schwierigkeit " + toString(XMLDoc.loadSchwierigkeit()));

	if(PlayerName == "Gott")
	{
		Option[6].setFont(font);
		Option[6].setColor(sf::Color::White);
		Option[6].setString("Bestenliste zurücksetzen!");
		Option[6].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 7));
		i++;
	}

	Option[7].setString("Zurück");
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
		// Überspringen des Versteckten Menüpunktes
		if(PlayerName != "Gott")
		{
			if(selectedItemIndex == 6)
				selectedItemIndex--;
		}
		Option[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_MENU_ITEMS)
	{
		Option[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		// Überspringen des Versteckten Menüpunktes
		if(PlayerName != "Gott")
		{
			if(selectedItemIndex == 6)
				selectedItemIndex++;
		}
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
				// Bestenliste zurücksetzen.
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
				// Bestenliste zurücksetzen.
				break;
			}
			break;
		}
	} 
}

void Options::setPlayerNameChar(char Char)
{
	// Fügt einen Char am Ende des Strings hinzu und Aktuallisiert die Anzeige
	PlayerName += Char;
	Option[0].setString("Spielername: " + PlayerName);
	XMLDoc.savePlayerName(PlayerName);
	if(PlayerName == "Gott")
	{
		Option[6].setFont(font);
		Option[6].setColor(sf::Color::White);
		Option[6].setString("Bestenliste zurücksetzen!");
		Option[6].setPosition(sf::Vector2f(WinX / 4, WinY / (MAX_MENU_ITEMS + 1) * 7));
		Option[7].setPosition(sf::Vector2f(WinX / 4, WinY / (MAX_MENU_ITEMS + 1) * 8));
	}
	else
	{
		Option[6].setColor(sf::Color::Transparent);
		Option[7].setPosition(sf::Vector2f(WinX / 4, WinY / (MAX_MENU_ITEMS + 1) * 7));
	}
}

void Options::delPlayerNameChar()
{
	// Löscht den letzen Char vom String und Aktuallisiert die Anzeige.
	if(PlayerName.size() != 0)
	{
		PlayerName.erase(PlayerName.end() - 1);
	}
	Option[0].setString("Spielername: " + PlayerName);
	if(PlayerName == "Gott")
	{
		Option[6].setFont(font);
		Option[6].setColor(sf::Color::White);
		Option[6].setString("Bestenliste zurücksetzen!");
		Option[6].setPosition(sf::Vector2f(WinX / 4, WinY / (MAX_MENU_ITEMS + 1) * 7));
		Option[7].setPosition(sf::Vector2f(WinX / 4, WinY / (MAX_MENU_ITEMS + 1) * 8));
	}
	else
	{
		Option[6].setColor(sf::Color::Transparent);
		Option[7].setPosition(sf::Vector2f(WinX / 4, WinY / (MAX_MENU_ITEMS + 1) * 7));
	}
}
