#include "Options.hpp"


Options::Options(float width, float height)
{
	// Standard Werte in die Variablen f�llen.
	selectedItemIndex = 0;
	selectedWindowIndex = 0;
	Aliasing = 0;
	PlayerName = " ";
	changeSizeXY();
	XMLSave();

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
	Option[1].setString("Anti-Aliasing " + toString(Aliasing));
	Option[1].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 2));

	Option[2].setFont(font);
	Option[2].setColor(sf::Color::White);
	Option[2].setString("Fenstergr��e " + toString(xWindow) + 'x' + toString(yWindow));
	Option[2].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 3));

	Option[3].setFont(font);
	Option[3].setColor(sf::Color::White);
	Option[3].setString("Bestenliste zur�cksetzen!");
	Option[3].setPosition(sf::Vector2f(width / 4, height / (MAX_MENU_ITEMS + 1) * 4));

	Option[4].setFont(font);
	Option[4].setColor(sf::Color::White);
	Option[4].setString("Zur�ck");
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
			xWindow = 800;
			yWindow = 480;
			break;
		}
		case 1:
		{
			xWindow = 1024;
			yWindow = 768;
			break;
		}
		case 2:
		{
			xWindow = 1280;
			yWindow = 720;
			break;
		}
		case 3:
		{
			xWindow = 1280;
			yWindow = 1024;
			break;
		}
		case 4:
		{
			xWindow = 1600;
			yWindow = 900;
			break;
		}
	 } 
	 Option[2].setString("Fenstergr��e " + toString(xWindow) + 'x' + toString(yWindow));
}

void Options::changeRight()
{
	switch(selectedItemIndex)
	{
		case 1:
		{
			if(Aliasing < 16)
			{
				Aliasing++;
				Option[1].setString("Anti-Aliasing " + toString(Aliasing));
				break;
			}
			else
			{
				Aliasing = 0;
				Option[1].setString("Anti-Aliasing " + toString(Aliasing));
				break;
			}
		}
		case 2:
		{
			if(selectedWindowIndex < 4)
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
			if(Aliasing > 0)
			{
				Aliasing--;
				Option[1].setString("Anti-Aliasing " + toString(Aliasing));
				break;
			}
			else
			{
				Aliasing = 16;
				Option[1].setString("Anti-Aliasing " + toString(Aliasing));
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
				selectedWindowIndex = 4;
				changeSizeXY();
				break;
			}
		}
	} 
}

int Options::getWindowX()
{
	return xWindow;
}

int Options::getWindowY()
{
	return yWindow;
}


int Options::getAliasing()
{
	return Aliasing;
}

void Options::setPlayerNameChar(char Char)
{
	// F�gt einen Char am Ende des Strings hinzu und Aktuallisiert die Anzeige
	PlayerName += Char;
	Option[0].setString("Spielername: " + PlayerName);
}

std::string Options::getPlayerName()
{
	return PlayerName;
}

void Options::delPlayerNameChar()
{
	// L�scht den letzen Char vom String und Aktuallisiert die Anzeige.
	PlayerName.erase(PlayerName.end() - 1);
	Option[0].setString("Spielername: " + PlayerName);
}

void Options::XMLSave()
{
/*

 Test -------------------------------------------------------------------------------> */
// Laden eines XML-Files
xml_document<> doc;
// Name des Files
std::ifstream file("settings.xml");
std::stringstream buffer;
buffer << file.rdbuf();
file.close();
std::string content(buffer.str());
doc.parse<0>(&content[0]);

// Haupt Node ausw�hlen (Hier w�re das Ergebniss <Optionen>
xml_node<> *pRoot = doc.first_node();

// Auswahl des Child Nodes mit dem Namen Playername
xml_node<> *pNode = pRoot->first_node("Playername");

// Das Attribut was in Klammern steht auslesen, aus dem Node den wir in pNode gespeichert haben.
xml_attribute<> *pAttr = pNode->first_attribute("attribute");
std::string strValue = pAttr->value();
// Site: https://semidtor.wordpress.com/2013/03/29/rapidxml-mini-tutorial/

}

void Options::XMLRead()
{
	/*xml_document<> doc;
	for (xml_attribute<> *attr = node->first_attribute(); attr; attr = attr->next_attribute())
	{
		cout << "Node foobar has attribute " << attr->name() << " ";
		cout << "with value " << attr->value() << "\n";
	}*/
}