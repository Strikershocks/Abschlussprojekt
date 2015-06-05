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

	//Settermethode für die Spielerposition
	void set_player_pos(int player_xpos, int player_ypos);

	//Gettermethoden für die Spielerposition
	int get_player_xpos();
	int get_player_ypos();

	//Methode um Levelnummer und Fenstergröße mitzuteilen
	void SetWindowSize(int lv_num, int x, int y);

	//Draw-Methode
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	//Spielerposition
	int player_xpos;
	int player_ypos;

	//Levelnummer
	int lv;

	//Fenstergröße
	int WinX;
	int WinY;

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

	//Methoden um unterschiedliche Level zu erstellen
	void create_lv1();
	void create_lv2();

	//Textur für die Wände
	sf::Texture t_wall;
	//Sprites für die Wände
	std::vector <Wall> s_wall;
};

