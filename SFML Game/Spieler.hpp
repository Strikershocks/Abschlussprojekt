#pragma once
/*Spieler.hpp
**createdate: 03.06.2015
**author: Gamstudio™
**last update: 04.06.2015
**description:
**gesammelte Daten des Spielers (Spielfigur, Spielname)*/
#include <iostream>
#include "SFML/Graphics.hpp"

class Spieler : public sf::Drawable
{
public:
	//Konstruktor mit Namen und Figur
	Spieler(std::string model,std::string name);

	//Modelnamen setzen
	void setModel(std::string model);

	//Spielernamen setzen
	void setName(std::string name);

	//x und y Position setzen
	void setposition(int x, int y);

	//verliert ein Leben
	void MinusLeben(void);

	//gewinnt ein Leben
	void PlusLeben(void);

	//gibt Modelnamen wieder
	std::string getModel(void);

	//gibt Spielernamen wieder
	std::string getName(void);

	//gibt jeweils Positionen x und y wieder
	int getX(void);
	int getY(void);

	//gibt Anzahl der Leben zurück
	int getLeben(void);
	
private:
	//Modelname
	std::string PlayerModel;
	
	//Spielername
	std::string PlayerName;
		
	//Positionen x und y
	int x;
	int y;

	//Anzahl der Leben
	int Leben;

	//setzt die Spielfigur anhand des Modelnamen
	void setTextureModel(std::string name);

	//Spielfigur
	sf::Sprite Model;
	sf::Texture texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

