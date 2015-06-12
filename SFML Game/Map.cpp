#include "Map.hpp"


Map::Map()
{
	//create_map(1);
	goal.loadFromFile("Resources/Textures/Goal/Goal1.png");

	Goal.setTexture(goal);
	Goal.setPosition(6500.f, 355.f);
}

Map::Map(int lv_num, int WinX, int WinY, sf::Vector2f CoordinatePlayer)
{
	//Damit die Map wei�, wie gro� das Fenster ist
	this->WinX = WinX;
	this->WinY = WinY;
	this->CoordinatePlayer = CoordinatePlayer;
	//Die Map wird erstellt, mit dem Lvl das �bergeben wurde.
	create_map(lv_num);
}

void Map::set_player_pos(sf::Vector2f CoordinatePlayer)
{
	this->CoordinatePlayer = CoordinatePlayer;
}

int Map::get_player_xpos()
{
	return CoordinatePlayer.x;
}

int Map::get_player_ypos()
{
	return CoordinatePlayer.y;
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
		bodenHindernisse(lv_num);
		break;
	case 2:
		create_lv2();
		bodenHindernisse(lv_num);
		break;
	default:
		create_lv1();
		bodenHindernisse(1);
		break;
	}
}


void Map::create_lv1()
{
	if( WinX == 1024)
	{
		//Die Textur f�r den Boden wird geladen
		if (!t_floor.loadFromFile("Resources/Textures/Ground/Grass2.png"))
		{
			// handle error
		}	
			
		//Es soll gegl�ttet werden
		t_floor.setSmooth(true);
	
		//Ein neues Sprite f�r den Boden
		sf::Sprite new_tile;
	
		//Setzt dem Sprite die Textur des Bodens
		new_tile.setTexture(t_floor);

		for(int i=0; i<9; i++)
		{
			//Hier werden mehrere Kopien des neuen Bodenteils an den Boden angef�gt
			new_tile.setPosition(i*WinX, WinY-236);
			s_floor.push_back(new_tile);
		}

	}
	else
	{
		//Die Textur f�r den Boden wird geladen
		if (!t_floor.loadFromFile("Resources/Textures/Ground/Grass2.png", sf::IntRect(0, 0, 800, 64)))
		{// handle error
		}
		//Es soll gegl�ttet werden
		t_floor.setSmooth(true);
		
		//Ein neues Sprite f�r den Boden
		sf::Sprite new_tile;
	
		//Setzt dem Sprite die Textur des Bodens
		new_tile.setTexture(t_floor);

		for(int i=0; i<9; i++)
		{
			//Hier werden mehrere Kopien des neuen Bodenteils an den Boden angef�gt
			new_tile.setPosition(i*WinX, WinY-64);
			s_floor.push_back(new_tile);
		}
	}

	if(WinX == 800)
	{
		//Die Textur f�r den Hintergrund wird geladen
		if (!t_bg.loadFromFile("Resources/Background/himmel600.png"))
		{
			// handle error
		}

	}
	else
	{
		//Die Textur f�r den Hintergrund wird geladen
		if (!t_bg.loadFromFile("Resources/Background/himmel.png"))
		{
			// handle error
		}
	}
	//Es soll gegl�ttet werden
	t_bg.setSmooth(true);
	
	//Ein neues Sprite f�r den hintergrund
	sf::Sprite new_bg;
	//Die Textur f�r den Background wird gew�hlt
	new_bg.setTexture(t_bg);

	// ... und auf der X-Achse kopien des Hintergrund-Sprites erstellt werden
	for(int i=0; i<9000; i=i+4049)
	{
		//Die Position des Hintergrundes wird gew�hlt und dann wird eine Kopie des Spites an
		//den Hintergrund angef�gt
		new_bg.setPosition(i,0);
		s_bg.push_back(new_bg);
	}

	//Die Textur f�r das Ziel
	/*std::string selectedGoal = "Goal1.png";
	switch(Random(0, 1))
	{
	case 0:
		{
			selectedGoal = "Goal1.png";
			break;
		}
	case 1:
		{
			selectedGoal = "Goal2.png";
			break;
		}
	default:
		{
			selectedGoal = "Goal1.png";
			break;
		}
	}
	if (!t_bg.loadFromFile("Resources/Textures/Goal/" + selectedGoal))
	{
		// handle error
	}
	Goal.setTexture(goal);
	Goal.setPosition(6500, 535);*/
}


void Map::bodenHindernisse(int lvl)
{
	Obstacle groundObstacle;
	std::string NameTexture;
	// Anzahl Hindernisse
	int iBHindernisse = 0;
	int xPos = 0;

	// Zuf�llige Hinderniss anzahl je nach lvl.
	if(lvl == 1)
	{
		iBHindernisse = Random(10, 100);
	}
	else
	{
		iBHindernisse = Random(30, 200);
	}

	// Solange keine x Elemente erstellt wurden.
	for(int i = 0; i < iBHindernisse; i++)
	{
		int a = Random(0, 3);
		switch(a)
		{
		case 0: 
			{
				NameTexture = "catMonster.png";
				break;
			}
		case 1:
			{
				NameTexture = "catSand.png";
				break;
			}
		case 2:
			{
				NameTexture = "lasertrap1.png";
				break;
			}
		case 3:
			{
				NameTexture = "LaserTrap2.png";
				break;
			}
		default: 
			{
				NameTexture = "LaserTrap2.png";
				break;
			}
		}

		//Die Textur f�r die Wand wird geladen
		if (!t_obstacle[i].loadFromFile("Resources/Textures/Traps/" + NameTexture))
		{
			// handle error
		}

		//Die Textur f�r die Wand wird gesetzt
		groundObstacle.s_obs.setTexture(t_obstacle[i]);

		//Dem Hindernis wird mitgeteilt wie gro� das Fenster ist
		groundObstacle.set_windowsize(WinX, WinY);

		// xPos wird immer mit neuen Abstand + gerechnet.
		xPos= xPos+Random(150, 500);

		// Zuf�lliger Abstand zwischen 80 und 150 px auf der X Achse.
		groundObstacle.setPosition(xPos, 470);

		//Eine Kopie des Hindernisses wird der Map hinzugef�gt
		s_obstacle.push_back(groundObstacle);
	}
}

// Random r�ckgabe zwischen min und max.
int Map::Random(int min, int max)
{
	srand(time(NULL));
	return rand()%(max-min) + min;
}

void Map::create_lv2()
{
	//Level 2 Fehlt derzeit noch
}


void Map::SetWindowSize(int lv_num, int x, int y)
{
	//Die Levelnummer wird eingetragen
	lv=lv_num;

	//Die Fenstergr��e wird eingetragen
	WinX = x;
	WinY = y;

	//Die Map wird erstellt
	create_map(lv);
}
// Kollisionsabfrage ob der Player Kollsision verursacht.
bool Map::checkKollision()
{
	// Hindernisse kollisionsabfrage.
	for(int i=0; i < s_obstacle.size(); i++)
	{
		sf::FloatRect boundingBox = s_obstacle[i].getBoundingBox();
		if(boundingBox.contains(CoordinatePlayer))
		{
			return true;
		}
	}

	for(int i=0; i < s_wall.size(); i++)
	{
		sf::FloatRect boundingBox = s_obstacle[i].getBoundingBox();
		if(boundingBox.contains(CoordinatePlayer))
		{
			return true;
		}
	}

	return false;
}

bool Map::checkGoal()
{
	sf::FloatRect boundingBox = Goal.getGlobalBounds();
	if(boundingBox.contains(CoordinatePlayer))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//Zeichnen aller Hintergr�nde
	for(int i = 0; i < s_bg.size(); i++)
	{
		target.draw(s_bg[i], states);

	}

	//Auf die Hintergr�nde wird der Boden draufgemalt
	for(int i=0; i<s_floor.size(); i++)
	{
		target.draw(s_floor[i], states);

	}

	//Andere Objekte, wie W�nde, kommen nat�rlich zum Schluss
	for(int i=0; i<s_wall.size(); i++)
	{
		target.draw(s_wall[i], states);
	}

	// Hindernisse.
	for(int i=0; i < s_obstacle.size(); i++)
	{
		target.draw(s_obstacle[i],states);
	}

	// Zeichnen des Ziels.
	target.draw(Goal,states);
}