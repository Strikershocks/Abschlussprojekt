#pragma once
/*Spieler.hpp
**createdate: 03.06.2015
**author: Gamstudio�
**last update: 04.06.2015
**description:
**gesammelte Daten des Spielers (Spielfigur, Spielname)*/
#include <iostream>
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.hpp"

class Spieler : public sf::Drawable
{
public:
	//Konstruktor mit Namen und Figur
	Spieler();

	//Spielernamen setzen
	void setName(std::string name);

	//x und y Position setzen
	void setPosition(int x, int y);

	//verliert ein Leben
	void MinusLeben();

	//gewinnt ein Leben
	void PlusLeben();

	//Animation Test
	void AnimationTest(sf::Vector2f movement, sf::Time frameTime, int index, std::string PlayerModel);

	//gibt Spielernamen wieder
	std::string getName();

	//gibt jeweils Positionen x und y wieder
	int getX();
	int getY();

	//gibt Anzahl der Leben zur�ck
	int getLeben();
	
private:
	//Spielername
	sf::Text Name;
	sf::Font font;

	// Texture vom Player
	sf::Texture Texture;
	sf::Texture Herz;
		
	//Positionen x und y
	int x;
	int y;

	//Anzahl der Leben
	std::vector<sf::Sprite> Lebensanzeige;

	// Animation f�r Rechts
	Animation walkingAnimationRight;

	// Zeiger auf Akutelle Animation
	Animation* currentAnimation;

	// set up AnimatedSprite
	AnimatedSprite animatedSprite;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

