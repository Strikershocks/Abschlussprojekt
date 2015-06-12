#include "Obstacle.hpp"


Obstacle::Obstacle(void)
{
	// Setzen der BoundingBox für die Kollisionsabfrage.
	boundingBox = s_obs.getGlobalBounds();
}


Obstacle::~Obstacle(void)
{
}

void Obstacle::set_windowsize(int WinX, int WinY) //Muss noch überarbeitet werden
{
	//Setzen der Fenstergröße
	this->WinX=WinX;
	this->WinY=WinY;

	//Setzen der Position (Muss noch optimiert werden)
	s_obs.setPosition(this->WinX-40, this->WinY-104);
}

sf::FloatRect Obstacle::getBoundingBox()
{
	boundingBox = s_obs.getGlobalBounds();
	return boundingBox;
}

void Obstacle::setPosition(int PosX, int PosY)
{
	s_obs.setPosition(PosX, PosY);
}

void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(s_obs, states);
}
