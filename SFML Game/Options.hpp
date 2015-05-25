#pragma once
#include <SFML/Graphics.hpp>
// Definierung von der Maximalen Menüpunkte
#define MAX_MENU_ITEMS 4

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);
	std::string getPlayerName();
	void setPlayerName();
	void MoveUp();
	void MoveDown();
	int GetPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_MENU_ITEMS];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

