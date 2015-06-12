#pragma once
#include <sfml/Graphics.hpp>

class Obstacle: public sf::Drawable
{
public:
	//ctor und dtor
	Obstacle(void);
	~Obstacle(void);

	//Methode um die Fenstergröße mitzuteilen
	void set_windowsize(int WinX, int WinY);

	
	//Sprite für das Hindernis
	sf::Sprite s_obs;

	// Setzen der Position.
	void setPosition(int PosX, int PosY);

	// Getter für getBoundingBox (Kollisionsabfrage)
	sf::FloatRect getBoundingBox();

	//Draw-Methode
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	//Fenstergröße
	int WinX;
	int WinY;
	sf::FloatRect boundingBox;
};

