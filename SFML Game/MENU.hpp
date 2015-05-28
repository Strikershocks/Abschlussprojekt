#pragma once
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.hpp"

// Definierung von der Maximalen Men�punkte
#define MAX_MENU_ITEMS 5

class Menu : public sf::Drawable
{
public:
	//Standardkonstruktor der die h�he und breite des fensters bekommt.
	Menu(float width, float height);
	~Menu();

	// Men� nach oben.
	void MoveUp();

	// Men� nach unten.
	void MoveDown();

	// �ndert den Angezeigten Spieler
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

	// Ausgew�hlter Spieler Model
	int selectedPlayerModelIndex;

	// Font f�r die Schrift Art
	sf::Font font;

	// Textarray f�rden Men�text (MAX_MENU_ITEMS ist die Anzahl der Maximalen Auswahlm�glichkeiten 
	// im Men�.
	sf::Text menu[MAX_MENU_ITEMS];
	sf::Sprite Player;
	sf::Texture Texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

