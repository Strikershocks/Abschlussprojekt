#include "MENU.hpp"


Menu::Menu(float width, float height)
{
	setPlayerModel("GuyBlueSprite.png");
	selectedPlayerModelIndex = 0;
	changePlayer();
	if (!font.loadFromFile("Resources/Sansation.ttf"))
	{
		// handle error
	}
	
	for(int i = 0; i < MAX_MENU_ITEMS; i++)
	
	{
		menu[i].setFont(font);
		menu[i].setColor(sf::Color::White);
		menu[i].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * (i+1)));
	}
	
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Singleplayer");
	
	menu[1].setString("Multiplayer");

	menu[2].setString("Ranking");

	menu[3].setString("Optionen");

	menu[4].setString("Beenden");

	selectedItemIndex = 0;

	PfeilLinks.scale(0.4, 0.4);
	PfeilRechts.scale(0.4, 0.4);
	if(!TexturePL.loadFromFile("Resources/Textures/Pfeil.png", sf::IntRect(-10, 80, 120, 130)))
	{
		// Loading Error 
	}
	PfeilLinks.setTexture(TexturePL);
	PfeilLinks.setPosition(10.f, 225.f);
	if(!TexturePR.loadFromFile("Resources/Textures/Pfeil.png", sf::IntRect(510, 80, 120, 130)))
	{
		// Loading Error 
	}
	PfeilRechts.setTexture(TexturePR);
	PfeilRechts.setPosition(220.f, 225.f);
	
}


Menu::~Menu()
{
}

 void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < MAX_MENU_ITEMS; i++)
	{
		target.draw(menu[i], states);
	}
	target.draw(Player, states);
	target.draw(PfeilLinks, states);
	target.draw(PfeilRechts, states);
 }

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_MENU_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int Menu::GetPressedItem()
{
	 return selectedItemIndex;
}

void Menu::changePlayer()
{
	// Textur wird geladen.
	if(!Texture.loadFromFile("Resources/Textures/" + PlayerModel))
	{
		// Loading Error
	}

	// Setzen der Texture für das Spieler Model.
	Player.setTexture(Texture);

	// Setzen der Position vom Spieler Model.
	Player.setPosition(90.f, 190.f);
}

void Menu::changePlayerRight()
{
	selectedPlayerModelIndex++;
	if(selectedPlayerModelIndex > 8)
	{
		selectedPlayerModelIndex = 0;
	}

	switch(selectedPlayerModelIndex)
	{
	case 0: // Für Player Model 2
		{
			setPlayerModel("GuyBlueSprite.png ");
			break;
		}
	case 1: // Für Player Model 2
		{
			setPlayerModel("HinagikuSprite.png");
			break;
		}
	case 2: // Für Player Model 3
		{
			setPlayerModel("GuySprite.png");
			break;
		}
	case 3: // Für Player Model 4
		{
			setPlayerModel("BlankSprite.png");
			break;
		}
	case 4: // Für Player Model 5
		{
			setPlayerModel("GhostSprite.png");
			break;
		}
	case 5: // Für Player Model 6
		{
			setPlayerModel("HolstaurusSprite.png");
			break;
		}
	case 6: // Für Player Model 7
		{
			setPlayerModel("MonsterGirlSprite.png");
			break;
		}
	case 7: // Für Player Model 8
		{
			setPlayerModel("MummySprite.png");
			break;
		}
	case 8: // Für Player Model 9
		{
			setPlayerModel("SlimeSprite.png");
			break;
		}
	}
	changePlayer();
}

void Menu::changePlayerLeft()
{
	selectedPlayerModelIndex--;
	if(selectedPlayerModelIndex < 0)
	{
		selectedPlayerModelIndex = 8;
	}

	switch(selectedPlayerModelIndex)
	{
	case 0: // Für Player Model 1
		{
			setPlayerModel("GuyBlueSprite.png");
			break;
		}
	case 1: // Für Player Model 2
		{
			setPlayerModel("HinagikuSprite.png");
			break;
		}
	case 2: // Für Player Model 3
		{
			setPlayerModel("GuySprite.png");
			break;
		}
	case 3: // Für Player Model 4
		{
			setPlayerModel("BlankSprite.png");
			break;
		}
	case 4: // Für Player Model 5
		{
			setPlayerModel("GhostSprite.png");
			break;
		}
	case 5: // Für Player Model 6
		{
			setPlayerModel("HolstaurusSprite.png");
			break;
		}
	case 6: // Für Player Model 7
		{
			setPlayerModel("MonsterGirlSprite.png");
			break;
		}
	case 7: // Für Player Model 8
		{
			setPlayerModel("MummySprite.png");
			break;
		}
	case 8: // Für Player Model 9
		{
			setPlayerModel("SlimeSprite.png");
			break;
		}
	}
	changePlayer();
}

void Menu::setPlayerModel(std::string PlayerModel)
{
	this->PlayerModel = PlayerModel;
}

std::string Menu::getPlayerModel()
{
	return PlayerModel;
}
