#pragma once
#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
#include "XMLHandler.hpp"

// Definierung von der Maximalen Men�punkte
#define MAX_MENU_ITEMS 8

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);

	// Dem Spielernamen ein Char anh�ngen.
	void setPlayerNameChar(char Char);

	// Letzen Char vom Spielernamen l�schen.
	void delPlayerNameChar();
	
	// Auswahl nach Oben.
	void MoveUp();
	
	// Auswahl nach Unten
	void MoveDown();
	
	// Auswahl nach Rechts
	void changeRight();
	
	// Auswahl nach Links
	void changeLeft();

	// Aufl�sung �ndern.
	void changeSizeXY();

	// Getter PressedItem
	int GetPressedItem();

private:
	XMLHandler XMLDoc;
	// Ausgew�hltes Optionsfeld
	int selectedItemIndex;


	// Font f�r den Text
	sf::Font font;

	// Array f�r die Optionen
	sf::Text Option[MAX_MENU_ITEMS];

	// Spielername
	std::string PlayerName;
	
	// Windows Gr��e
	int WinX;
	int WinY;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

