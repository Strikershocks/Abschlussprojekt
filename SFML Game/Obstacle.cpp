#include "Obstacle.hpp"


Obstacle::Obstacle(void)
{
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


void Obstacle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(s_obs, states);
}
