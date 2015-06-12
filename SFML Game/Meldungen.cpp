#include "Meldungen.hpp"
/*Meldungen.cpp
**createdate: 04.06.2015
**author: Gamestudio™
**last update: 04.06.2015
**description:
**gesammelte Meldungen*/

#define MAX_MENU_ITEMS 5

Meldungen::Meldungen()
{
	sprite.scale(0.4, 0.4);
}

void Meldungen::Window_Success(bool RankingSuccsess)
{
	if(RankingSuccsess == true)
		CreateMeldung("Success!", "You are the Winner! \n Du wurdest im Ranking hinzugefügt!");
	else
		CreateMeldung("Success!", "You are the Winner!");
		
}

void Meldungen::Player_Died()
{
	CreateMeldung("You died!", "Game over!");
}

void Meldungen::Window_failNetwork()
{
	CreateMeldung("keine Verbindung!", "Wir haben leider keine Netzwerkverbindung gefunden");
}

void Meldungen::Window_failMusic()
{
	CreateMeldung("keine Musik!", "Die Musik konnte leider nicht geladen werden");
}

void Meldungen::Abspann(float width, float height)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Credits", sf::Style::Close);
	sf::Text Mitwirkende[MAX_MENU_ITEMS];
	sf::Texture Background;
	//sf::Sprite sprite;
	sf::Font font;

	while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
			{
				window.close();
			}    
        }
		window.clear(sf::Color::White);
		// Überprüfung ob die Font (Schrift) vorhanden ist!
		if (font.loadFromFile("Resources/Sansation.ttf"))
		{
			for(int i = 0; i < MAX_MENU_ITEMS; i++)
			{
				Mitwirkende[i].setFont(font);
				Mitwirkende[i].setColor(sf::Color::Blue);
				Mitwirkende[i].setPosition(sf::Vector2f(width / width, height / (MAX_MENU_ITEMS + 1) * i));
			}

			Mitwirkende[0].setString("Niklas Kraßmann");

			Mitwirkende[1].setString("Lukas Riebesel");

			Mitwirkende[2].setString("Kai Blume");

			Mitwirkende[3].setString("Stefanie Dautz");

			Mitwirkende[4].setString("Erstellt für die Georg-Sonnin-Schule \n zu Werbezwecken");
		}

		if (!Background.loadFromFile("Resources/Textures/GSS_Skyline.png", sf::IntRect(0, 0, 3607, 793))) 
		{
			// handle error
		}
		// Es soll immer wiederholt werden.
		Background.setRepeated(true);

		// Es soll zur not geglättet werden.
		Background.setSmooth(true);

		// setzt dem Sprite die Texture Ground.
		sprite.setTexture(Background);
		sprite.setPosition(25, 480);

		window.draw(sprite);

		for (int i = 0; i < MAX_MENU_ITEMS; i++)
		{
			window.draw(Mitwirkende[i]);
		}

        window.display();
	 }
}

void Meldungen::CreateMeldung(std::string Titel, std::string MeldungText)
{
	// Fenster Start
	sf::RenderWindow window(sf::VideoMode(290, 35), Titel, sf::Style::Close);
	sf::Text Meldung;
	sf::Font font;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
				window.close();
			}    
        }
        window.clear();
		
		// Überprüfung ob die Font (Schrift) vorhanden ist!
		if (font.loadFromFile("Resources/Sansation.ttf"))
		{
			Meldung.setFont(font);
			// Meldungsnachricht
			Meldung.setString(MeldungText);
			Meldung.setCharacterSize(24); // In Pixel
			Meldung.setColor(sf::Color::Red);
		}

		window.draw(Meldung);
        window.display();
    }   
}
