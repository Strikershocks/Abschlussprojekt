#pragma once
/*Spieler.hpp
**createdate: 03.06.2015
**author: Gamstudio™
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

	//Modelnamen setzen
	void setModel(std::string model);

	// Start der Animation
	void StartAnimation();

	// Initialisierung Spieler
	void initSpieler();

	// Animationsauswahl
	void AnimationSelect(std::string PlayerModel);

	// Setzen der Animationspostion
	void SetAnimationPosition(float x, float y);

	// Stop der Animation.
	void StopAnimation();

	// Ändern der Animation
	void ChangeAnimation(int index);

	// Aktuallisiert Animation
	void UpdateAnimation(sf::Time frameTime);

	void BewegenSpieler(sf::Vector2f movement, sf::Time frameTime);

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

	// Texture vom Player
	sf::Texture Texture;
		
	//Positionen x und y
	int x;
	int y;

	//Anzahl der Leben
	int Leben;

	// Animation für Links
	Animation walkingAnimationLeft;

	// Animation für Rechts
	Animation walkingAnimationRight;

	// Zeiger auf Akutelle Animation
	Animation* currentAnimation;

	// set up AnimatedSprite
	AnimatedSprite animatedSprite;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

