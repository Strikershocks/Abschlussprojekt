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

	//Settermethode für die Spielerposition
	void set_player_pos(sf::Vector2f CoordinatePlayer);

	//Gettermethoden für die Spielerposition
	int get_player_xpos();
	int get_player_ypos();
	
	// Gibt Kollisionsindex zurück, true für Collision.
	bool checkKollision();

	//Sieg überprüfen.
	bool checkGoal();

	void bodenHindernisse(int lvl);

	//Methode um Levelnummer und Fenstergröße mitzuteilen
	void SetWindowSize(int lv_num, int x, int y);

	//Draw-Methode
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	//Levelnummer
	int lv;

	//Fenstergröße
	int WinX;
	int WinY;

	// Koordinaten Player
	sf::Vector2f CoordinatePlayer;

	//Textur für den Boden
	sf::Texture t_floor;

	//Sprites für den Boden
	std::vector<sf::Sprite> s_floor;

	//Textur für den Hintergrund
	sf::Texture t_bg;

	//Sprites für den Hintergrund
	std::vector<sf::Sprite> s_bg;

	//Methode um ein Levelauszuwählen, das erstellt werden soll
	void create_map(int lv_num);

	// Random zwischen min und max
	int Random(int min, int max);

	//Methoden um unterschiedliche Level zu erstellen
	void create_lv1();
	void create_lv2();

	//Textur für die Wände
	sf::Texture t_wall;

	//Sprites für die Wände
	std::vector <Wall> s_wall;

	// Textur für das Hindernis
	sf::Texture t_obstacle[200];

	// Sprites für das Hindernis.
	std::vector <Obstacle> s_obstacle;

	// Texture für die Ziellinie
	sf::Texture goal;

	// Sprite für die Ziellinie
	sf::Sprite Goal;
};

