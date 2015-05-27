#pragma once
#include "SFML/Graphics.hpp"

// Definierung von der Maximalen Menüpunkte
#define MAX_MENU_ITEMS 5

class Menu : public sf::Drawable
{
public:
	//Standardkonstruktor der die höhe und breite des fensters bekommt.
	Menu(float width, float height);
	~Menu();
	void MoveUp();
	void MoveDown();
	void changePlayer();
	int GetPressedItem();
	std::string getPlayerModel();
	// Auswahl nach Rechts Player Model
	void changePlayerRight();

	// Auswahl nach Links Player Model
	void changePlayerLeft();
	void setPlayerModel(std::string PlayerModel);
	
private:
	int selectedItemIndex;
	std::string PlayerModel;


	// Ausgewählter Spieler Model
	int selectedPlayerModelIndex;
	sf::Font font;
	// Textarray für den Menütext (MAX_MENU_ITEMS ist die Anzahl der Maximalen Auswahlmöglichkeiten 
	// im Menü.
	sf::Text menu[MAX_MENU_ITEMS];
	sf::Sprite Player;
	sf::Texture Texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

