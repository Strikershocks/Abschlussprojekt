#pragma once
#include <SFML/Graphics.hpp>
class Map  : public sf::Drawable
{
public:
	Map(void);
	~Map(void);
	void SetPlayerPositon(int x, int y);
	void initMap();

private:
	int PlayerX;
	int PlayerY;
	sf::Texture texture;
	sf::Sprite sprite;

	void Hindernisse();
	void PowerUps();
	void Background();
	void Goal();
	void Ground();
	void View();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

