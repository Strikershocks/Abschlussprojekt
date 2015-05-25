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
	Option[0].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 1));

	Option[1].setFont(font);
	Option[1].setColor(sf::Color::White);
	Option[1].setString("Anti-Allaising");
	Option[1].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 2));

	Option[2].setFont(font);
	Option[2].setColor(sf::Color::White);
	Option[2].setString("Bestenliste zurücksetzen!");
	Option[2].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 3));


	Option[3].setFont(font);
	Option[3].setColor(sf::Color::White);
	Option[3].setString("Zurück");
	Option[3].setPosition(sf::Vector2f(width / 2, height / (MAX_MENU_ITEMS + 1) * 4));

	selectedItemIndex = 0;
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