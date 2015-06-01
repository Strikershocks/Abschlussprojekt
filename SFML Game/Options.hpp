#pragma once
#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"
#include <stdio.h>

using namespace rapidxml;

// Definierung von der Maximalen Menüpunkte
#define MAX_MENU_ITEMS 5

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);

	// Getter vom Spielernamen.
	std::string getPlayerName();

	// Dem Spielernamen ein Char anhängen.
	void setPlayerNameChar(char Char);

	// Letzen Char vom Spielernamen löschen.
	void delPlayerNameChar();
	
	// Auswahl nach Oben.
	void MoveUp();
	
	// Auswahl nach Unten
	void MoveDown();
	
	// Auswahl nach Rechts
	void changeRight();
	
	// Auswahl nach Links
	void changeLeft();

	// Auflösung Ändern.
	void changeSizeXY();

	// Getter PressedItem
	int GetPressedItem();
	
	// Getter von xWindow
	int getWindowX();
	
	// Getter von yWindow
	int getWindowY();
	
	// Getter für Aliasing
	int getAliasing();

private:
	// Ausgewähltes Optionsfeld
	int selectedItemIndex;

	// Ausgewählte Auflösung
	int selectedWindowIndex;

	// x Wert
	int xWindow;

	// y Wert
	int yWindow;

	// Ausgewähltes Anti-Aliasing Level max 16
	int Aliasing; 

	// Font für den Text
	sf::Font font;

	// Array für die Optionen
	sf::Text Option[MAX_MENU_ITEMS];

	// Spielername
	std::string PlayerName;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void XMLSave();

	void XMLRead();
};

