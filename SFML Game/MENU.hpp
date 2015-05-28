#pragma once
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.hpp"

// Definierung von der Maximalen Menüpunkte
#define MAX_MENU_ITEMS 5

class Menu : public sf::Drawable
{
public:
	//Standardkonstruktor der die höhe und breite des fensters bekommt.
	Menu(float width, float height);
	~Menu();

	// Menü nach oben.
	void MoveUp();

	// Menü nach unten.
	void MoveDown();

	// Ändert den Angezeigten Spieler
	void changePlayer();
	
	// Getter selectedItemIndex
	int GetPressedItem();

	// Getter PlayerModel
	std::string getPlayerModel();
	// Auswahl nach Rechts Player Model
	void changePlayerRight();

	// Auswahl nach Links Player Model
	void changePlayerLeft();

	// Setter PlayerModel
	void setPlayerModel(std::string PlayerModel);
	
private:
	int selectedItemIndex;

	// Player Model
	std::string PlayerModel;

	// Spieler steht Still.
	Animation standAnimation;

	// Ausgewählter Spieler Model
	int selectedPlayerModelIndex;

	// Font für die Schrift Art
	sf::Font font;

	// Textarray fürden Menütext (MAX_MENU_ITEMS ist die Anzahl der Maximalen Auswahlmöglichkeiten 
	// im Menü.
	sf::Text menu[MAX_MENU_ITEMS];
	sf::Sprite Player;
	sf::Texture Texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

