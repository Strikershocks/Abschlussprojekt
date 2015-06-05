#pragma once
#include <SFML/Graphics.hpp>
#include "Wall.hpp"
class Map  : public sf::Drawable
{
public:
	//Konstruktoren und Destruktor
	Map();
	Map(int lv_num, int WinX, int WinY);
	~Map(void);

	//Settermethode f�r die Spielerposition
	void set_player_pos(int player_xpos, int player_ypos);

	//Gettermethoden f�r die Spielerposition
	int get_player_xpos();
	int get_player_ypos();

	//Methode um Levelnummer und Fenstergr��e mitzuteilen
	void SetWindowSize(int lv_num, int x, int y);

	//Draw-Methode
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	//Spielerposition
	int player_xpos;
	int player_ypos;

	//Levelnummer
	int lv;

	//Fenstergr��e
	int WinX;
	int WinY;

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

	//Methoden um unterschiedliche Level zu erstellen
	void create_lv1();
	void create_lv2();

	//Textur f�r die W�nde
	sf::Texture t_wall;
	//Sprites f�r die W�nde
	std::vector <Wall> s_wall;
};

