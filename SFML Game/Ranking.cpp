#include "Ranking.hpp"


Ranking::Ranking(void)
{
	if (!font.loadFromFile("Resources/Sansation.ttf"))
	{
		// handle error
	}
	
	// Erstellen der 10 Ranking Texte
	for(int i = 0; i < 10; i++)
	{
		menu[i].setFont(font);
		menu[i].setColor(sf::Color::White);
		menu[i].setPosition(sf::Vector2f(20 , 600 / (10 + 1) * (i+1)));
		menu[i].setString(XML.loadRanking(i + 1, 0));
	}
}


Ranking::~Ranking(void)
{
}

void Ranking::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 9; i++)
	{
		target.draw(menu[i], states);
	}
 }