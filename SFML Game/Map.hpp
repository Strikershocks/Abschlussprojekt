#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wall.hpp"
class Map  : public sf::Drawable
{
public:
	//Konstruktoren und Destruktor
	Map();
	Map(int lv_num, int WinX, int WinY, sf::Vector2f CoordinatePlayer);
	~Map(void);

	//Settermethode f�r die Spielerposition
	void set_player_pos(sf::Vector2f CoordinatePlayer);

	//Gettermethoden f�r die Spielerposition
	int get_player_xpos();
	int get_player_ypos();
	
	// Gibt Kollisionsindex zur�ck, true f�r Collision.
	bool checkKollision();

	//Sieg �berpr�fen.
	bool checkGoal();

	void bodenHindernisse(int lvl);

	//Methode um Levelnummer und Fenstergr��e mitzuteilen
	void SetWindowSize(int lv_num, int x, int y);

	//Draw-Methode
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	//Levelnummer
	int lv;

	//Fenstergr��e
	int WinX;
	int WinY;

	// Koordinaten Player
	sf::Vector2f CoordinatePlayer;

	//Textur f�r den Boden
	sf::Texture t_floor;

	//Sprites f�r den Boden
	std::vector<sf::Sprite> s_floor;

	//Textur f�r den Hintergrund
	sf::Texture t_bg;

	//Sprites f�r den Hintergrund
	std::vector<sf::Sprite> s_bg;

	//Methode um ein Levelauszuw�hlen, das erstellt werden soll
	void create_map(int lv_num);

	// Random zwischen min und max
	int Random(int min, int max);

	//Methoden um unterschiedliche Level zu erstellen
	void create_lv1();
	void create_lv2();

	//Textur f�r die W�nde
	sf::Texture t_wall;

	//Sprites f�r die W�nde
	std::vector <Wall> s_wall;

	// Textur f�r das Hindernis
	sf::Texture t_obstacle[200];

	// Sprites f�r das Hindernis.
	std::vector <Obstacle> s_obstacle;

	// Texture f�r die Ziellinie
	sf::Texture goal;

	// Sprite f�r die Ziellinie
	sf::Sprite Goal;
};

