#pragma once
#include "SFML/Graphics.hpp"
#include"XMLHandler.hpp"

class Ranking : public sf::Drawable
{
public:
	Ranking(void);
	~Ranking(void);

private:
	// Font für die Schrift Art
	sf::Font font;
	// 10 Ranking Punkte
	sf::Text menu[10];

	XMLHandler XML;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

