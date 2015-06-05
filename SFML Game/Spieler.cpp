/*Spieler.cpp
**createdate: 03.06.2015
**author: Stefanie Dautz
**last update: 04.06.2015
**description:
**gesammelte Daten des Spielers (Spielfigur, Spielname)*/
#include "Spieler.hpp"

Spieler::Spieler(std::string model, std::string name)
{
	setModel(model);
	setName(name);
	this->Leben = 3;
}

void Spieler::setModel(std::string model)
{
	this->PlayerModel = model;
	setTextureModel(model);
}

void Spieler::setName(std::string name)
{this->PlayerName = name;}

void Spieler::setposition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Spieler::MinusLeben(void)
{this->Leben--;}

void Spieler::PlusLeben(void)
{this->Leben++;}


std::string Spieler::getModel(void)
{return this->PlayerModel;}

std::string Spieler::getName(void)
{return this->PlayerName;}

int Spieler::getX()
{return this->x;}

int Spieler::getY()
{return this->y;}

int Spieler::getLeben()
{return this->Leben;}

void Spieler::setTextureModel(std::string name)
{
	// Textur wird geladen.
	if(!texture.loadFromFile("Resources/Textures/" + name))
	{
		// Loading Error
	}

	// Setzen der Texture für das Spieler Model.
	Model.setTexture(texture);
}

void Spieler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Model, states);
}