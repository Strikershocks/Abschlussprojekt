#pragma once
#include "SFML/Graphics.hpp"

// Definierung von der Maximalen Men�punkte
#define MAX_MENU_ITEMS 4

class Menu : public sf::Drawable
{
public:
	//Standardkonstruktor der die h�he und breite des fensters bekommt.
	Menu(float width, float height);
	~Menu();
	void MoveUp();
	void MoveDown();
	int GetPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	// Textarray f�r den Men�text (MAX_MENU_ITEMS ist die Anzahl der Maximalen Auswahlm�glichkeiten 
	// im Men�.
	sf::Text menu[MAX_MENU_ITEMS];

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

