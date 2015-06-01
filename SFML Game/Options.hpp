#pragma once
#include <SFML/Graphics.hpp>
#include "Include\StringHelpers.hpp"
#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"
#include <stdio.h>

using namespace rapidxml;

// Definierung von der Maximalen Men�punkte
#define MAX_MENU_ITEMS 5

class Options : public sf::Drawable
{
public:
	Options(float width, float height);
	~Options(void);

	// Getter vom Spielernamen.
	std::string getPlayerName();

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
	
	// Getter von xWindow
	int getWindowX();
	
	// Getter von yWindow
	int getWindowY();
	
	// Getter f�r Aliasing
	int getAliasing();

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

	void XMLSave();

	void XMLRead();
};

