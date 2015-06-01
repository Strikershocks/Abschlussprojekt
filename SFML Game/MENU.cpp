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

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Singleplayer");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Multiplayer");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Ranking");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Optionen");
	menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 4));


	menu[4].setFont(font);
	menu[4].setColor(sf::Color::White);
	menu[4].setString("Beenden");
	menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 5));

	selectedItemIndex = 0;


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

	// Setzen der Texture f�r das Spieler Model.
	Player.setTexture(Texture);

	// Setzen der Position vom Spieler Model.
	Player.setPosition(30.f, 200.f);
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
	case 0: // F�r Player Model 2
		{
			setPlayerModel("GuyBlueSprite.png ");
			break;
		}
	case 1: // F�r Player Model 2
		{
			setPlayerModel("HinagikuSprite.png");
			break;
		}
	case 2: // F�r Player Model 3
		{
			setPlayerModel("GuySprite.png");
			break;
		}
	case 3: // F�r Player Model 4
		{
			setPlayerModel("BlankSprite.png");
			break;
		}
	case 4: // F�r Player Model 5
		{
			setPlayerModel("GhostSprite.png");
			break;
		}
	case 5: // F�r Player Model 6
		{
			setPlayerModel("HolstaurusSprite.png");
			break;
		}
	case 6: // F�r Player Model 7
		{
			setPlayerModel("MonsterGirlSprite.png");
			break;
		}
	case 7: // F�r Player Model 8
		{
			setPlayerModel("MummySprite.png");
			break;
		}
	case 8: // F�r Player Model 9
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
	case 0: // F�r Player Model 1
		{
			setPlayerModel("GuyBlueSprite.png");
			break;
		}
	case 1: // F�r Player Model 2
		{
			setPlayerModel("HinagikuSprite.png");
			break;
		}
	case 2: // F�r Player Model 3
		{
			setPlayerModel("GuySprite.png");
			break;
		}
	case 3: // F�r Player Model 4
		{
			setPlayerModel("BlankSprite.png");
			break;
		}
	case 4: // F�r Player Model 5
		{
			setPlayerModel("GhostSprite.png");
			break;
		}
	case 5: // F�r Player Model 6
		{
			setPlayerModel("HolstaurusSprite.png");
			break;
		}
	case 6: // F�r Player Model 7
		{
			setPlayerModel("MonsterGirlSprite.png");
			break;
		}
	case 7: // F�r Player Model 8
		{
			setPlayerModel("MummySprite.png");
			break;
		}
	case 8: // F�r Player Model 9
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