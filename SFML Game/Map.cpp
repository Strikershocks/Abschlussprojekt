#include "Map.hpp"


Map::Map(void)
{
	Ground();
}


Map::~Map(void)
{
}


void Map::Ground()
{
	if (!texture.loadFromFile("Resources/Textures/Ground/GrassGround.png", sf::IntRect(0, 0, 476, 107)))
	{
		// handle error
	}
	// Es soll immer wiederholt werden.
	texture.setRepeated(true);

	// Es soll zur not geglättet werden.
	texture.setSmooth(true);

	// setzt dem Sprite die Texture Ground.
	sprite.setTexture(texture);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}