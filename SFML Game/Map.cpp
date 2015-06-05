#include "Map.hpp"


Map::Map()
{
	//create_map(1);
}

Map::Map(int lv_num, int WinX, int WinY)
{
	//Damit die Map weiß, wie groß das Fenster ist
	this->WinX=WinX;
	this->WinY=WinY;

	//Die Map wird erstellt
	create_map(lv_num);
}

void Map::set_player_pos(int player_xpos, int player_ypos)
{
	this->player_xpos=player_xpos;
	this->player_ypos=player_ypos;
}

int Map::get_player_xpos()
{
	return player_xpos;
}

int Map::get_player_ypos()
{
	return player_ypos;
}


Map::~Map(void)
{
}

void Map::create_map(int lv_num)
{
	//Die Map-Auswahl
	switch (lv_num)
	{
	case 1:
		create_lv1();
		break;
	case 2:
		create_lv2();
		break;
	default:
		create_lv1();
		break;
	}
}


void Map::create_lv1()
{

	//Die Textur für den Boden wird geladen
	if (!t_floor.loadFromFile("Resources/Textures/Ground/Grass2.png", sf::IntRect(0, 0, 1024, 64)))
	{
		// handle error
	}

	//Es soll geglättet werden
	t_floor.setSmooth(true);
	
	//Ein neues Sprite für den Boden
	sf::Sprite new_tile;
	
	//Setzt dem Sprite die Textur des Bodens
	new_tile.setTexture(t_floor);

	for(int i=0; i<3; i++)
	{
		//Hier werden mehrere Kopien des neuen Bodenteils an den Boden angefügt
		new_tile.setPosition(i*1024, WinY-64);
		s_floor.push_back(new_tile);
	}

	//Die Textur für den Hintergrund wird geladen
	if (!t_bg.loadFromFile("Resources/Textures/Ground/GrassGround.png", sf::IntRect(0, 45, 476, 45)))
	{
		// handle error
	}

	//Es soll geglättet werden
	t_bg.setSmooth(true);

	//Ein neues Sprite für den hintergrund
	sf::Sprite new_bg;

	//Die Textur für den Background wird gewählt
	new_bg.setTexture(t_bg);

	//Bis der Hintergrund ausgefüllt ist sollen auf der Y Achse ...
	for(int ii=0; ii<WinY; ii=ii+45)
	{
		// ... und auf der X-Achse kopien des Hintergrund-Sprites erstellt werden
		for(int i=0; i<WinX; i=i+476)
		{
			//Die Position des Hintergrundes wird gewählt und dann wird eine Kopie des Spites an
			//den Hintergrund angefügt
			new_bg.setPosition(i,ii);
			s_bg.push_back(new_bg);
		}
	}

	//Eine neue Wand wird erstellt
	Wall new_wall;

	//Die Textur für die Wand wird geladen
	if (!t_wall.loadFromFile("Resources/Textures/Ground/Flappy-Ground.png", sf::IntRect(0, 17, 10, 40)))
	{
		// handle error
	}

	//Die Textur für die Wand wird gesetzt
	new_wall.s_obs.setTexture(t_wall);

	//Der Wand wird mitgeteilt wie groß das Fenster ist
	new_wall.set_windowsize(WinX, WinY);

	//Eine Kopie der Wand wird der Map hinzugefügt
	s_wall.push_back(new_wall);
}

void Map::create_lv2()
{
	//Level 2 Fehlt derzeit noch
}


void Map::SetWindowSize(int lv_num, int x, int y)
{
	//Die Levelnummer wird eingetragen
	lv=lv_num;

	//Die Fenstergröße wird eingetragen
	WinX = x;
	WinY = y;

	//Die Map wird erstellt
	create_map(lv);
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Malen aller Hintergründe
	for(int i=0; i<s_bg.size(); i++)
	{
		target.draw(s_bg[i], states);

	}

	//Auf die Hintergründe wird der Boden draufgemalt
	for(int i=0; i<s_floor.size(); i++)
	{
		target.draw(s_floor[i], states);

	}

	//Andere Objekte, wie Wände, kommen natürlich zum Schluss
	for(int i=0; i<s_wall.size(); i++)
	{
		target.draw(s_wall[i], states);
	}

}