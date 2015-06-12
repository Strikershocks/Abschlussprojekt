#pragma once
#include <sfml/Graphics.hpp>

class Obstacle: public sf::Drawable
{
public:
	//ctor und dtor
	Obstacle(void);
	~Obstacle(void);

	//Methode um die Fenstergr��e mitzuteilen
	void set_windowsize(int WinX, int WinY);

	
	//Sprite f�r das Hindernis
	sf::Sprite s_obs;

	// Setzen der Position.
	void setPosition(int PosX, int PosY);

	// Getter f�r getBoundingBox (Kollisionsabfrage)
	sf::FloatRect getBoundingBox();

	//Draw-Methode
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	//Fenstergr��e
	int WinX;
	int WinY;
	sf::FloatRect boundingBox;
};

