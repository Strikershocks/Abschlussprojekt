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
	
	// Getter PressedItem
	int GetPressedItem();
	
	// Getter von xWindow
	int getWindowX();
	
	// Getter von yWindow
	int getWindowY();
	
	// Auflösung Ändern.
	void changeSizeXY();

	// Ändern von Aliasing level.
	void changeAliasing(int i);

private:
	int selectedItemIndex;
	int selectedWindowIndex;
	int selectedAliasingIndex;
	int xWindow;
	int yWindow;
	int Aliasing; 
	bool back;
	sf::Font font;
	sf::Text Option[MAX_MENU_ITEMS];
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

