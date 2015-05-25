#include "Options.hpp"


Options::Options(float width, float height)
{
		if (!font.loadFromFile("Resources/Sansation.ttf"))
	{
		// handle error
	}

	Option[0].setFont(font);
	Option[0].setColor(sf::Color::Red);
	Option[0].setString("Spielername");
	Option[0].setPosition(sf::Vector2f(width / 3, height / (MAX_MENU_ITEMS + 1) * 1));

	Option[1].setFont(font);
	Option[1].setColor(sf::Color::White);
	Option[1].setString("Anti-Allaising");
	Option[1].setPosition(sf::Vector2f(width / 3, height / (MAX_MENU_ITEMS + 1) * 2));

	Option[2].setFont(font);
	Option[2].setColor(sf::Color::White);
	Option[2].setString("Fenstergröße");
	Option[2].setPosition(sf::Vector2f(width / 3, height / (MAX_MENU_ITEMS + 1) * 3));

	Option[3].setFont(font);
	Option[3].setColor(sf::Color::White);
	Option[3].setString("Bestenliste zurücksetzen!");
	Option[3].setPosition(sf::Vector2f(width / 3, height / (MAX_MENU_ITEMS + 1) * 4));

	Option[4].setFont(font);
	Option[4].setColor(sf::Color::White);
	Option[4].setString("Zurück");
	Option[4].setPosition(sf::Vector2f(width / 3, height / (MAX_MENU_ITEMS + 1) * 4));

	selectedItemIndex = 0;
	selectedWindowIndex = 0;
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

 void Options::changeWindow()
 {
	 switch(selectedWindowIndex)
	 {
		case 0:
		{
			xWindow = 800;
			yWindow = 480;
		}
		case 1:
		{
			xWindow = 1024;
			yWindow = 768;
		}
		case 2:
		{
			xWindow = 1280;
			yWindow = 720;
		}
		case 3:
		{
			xWindow = 1280;
			yWindow = 1024;
		}
		case 4:
		{
			xWindow = 1600;
			yWindow = 900;
		}
	 } 
}

void Options::changeRight()
{
	switch(selectedItemIndex)
	{
		case 0:
		{
			xWindow = 800;
			yWindow = 480;
		}
		case 1:
		{
			xWindow = 1024;
			yWindow = 768;
		}
		case 2:
		{
			if(selectedWindowIndex < 5)
			{
				selectedWindowIndex++;
				changeWindow();
			}
			else
			{
				selectedWindowIndex = 0;
				changeWindow();
			}
		}
		case 3:
		{
			xWindow = 1280;
			yWindow = 1024;
		}
		case 4:
		{
			xWindow = 1600;
			yWindow = 900;
		}
	} 
}
