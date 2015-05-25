#pragma once
#include <SFML/Graphics.hpp>
// Definierung von der Maximalen Menüpunkte
#define MAX_MENU_ITEMS 5

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);
	std::string getPlayerName();
	void setPlayerName(std::string);
	void MoveUp();
	void MoveDown();
	void changeRight();
	void changeLeft();
	int GetPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text Option[MAX_MENU_ITEMS];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

