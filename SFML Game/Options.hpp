#pragma once
#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
// Definierung von der Maximalen Men�punkte
#define MAX_MENU_ITEMS 5

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);
	std::string getPlayerName();
	void setPlayerNameChar(char Char);
	void delPlayerNameChar();
	
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
	
	// Getter f�r Aliasing
	int getAliasing();

	// Aufl�sung �ndern.
	void changeSizeXY();

private:
	// Ausgew�hltes Optionsfeld
	int selectedItemIndex;

	// Ausgew�hlte Aufl�sung
	int selectedWindowIndex;

	// x Wert
	int xWindow;

	// y Wert
	int yWindow;

	// Ausgew�hltes Anti-Aliasing Level max 16
	int Aliasing; 

	// Font f�r den Text
	sf::Font font;

	// Array f�r die Optionen
	sf::Text Option[MAX_MENU_ITEMS];

	// Spielername
	std::string PlayerName;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

