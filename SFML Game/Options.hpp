#pragma once
#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
// Definierung von der Maximalen Menüpunkte
#define MAX_MENU_ITEMS 5

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);
	std::string setPlayerName();
	void setPlayerName(std::string);
	// Auswahl nach Oben.
	void MoveUp();
	// Auswahl nach Unten
	void MoveDown();
	// Auswahl nach Rechts
	void changeRight();
	// Auswahl nach Links
	void changeLeft();
	int GetPressedItem();
	// Getter von xWindow
	int getWindowX();
	// Getter von yWindow
	int getWindowY();
	// Auflösung Ändern.
	void changeWindow();

private:
	int selectedItemIndex;
	int selectedWindowIndex;
	int xWindow;
	int yWindow;
	sf::Font font;
	sf::Text Option[MAX_MENU_ITEMS];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

