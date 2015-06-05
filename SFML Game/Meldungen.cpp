#include "Meldungen.hpp"
/*Meldungen.cpp
**createdate: 04.06.2015
**author: Gamestudio™
**last update: 04.06.2015
**description:
**gesammelte Meldungen*/

void Meldungen::Window_Success()
{
	CreateMeldung("Success!", "You are the Winner!");
}

void Meldungen::Player_Died()
{
	CreateMeldung("You died!", "Game over!");
}

void Meldungen::Window_failNetwork()
{
	CreateMeldung("keine Verbindung!", "Wir haben leider keine Netzwerkverbindung gefunden!");
}

void Meldungen::CreateMeldung(std::string Titel, std::string MeldungText)
{
	// Fenster Start
	sf::RenderWindow window(sf::VideoMode(290, 35), Titel, sf::Style::Close);
	sf::Text Meldung;
	//sf::Font font;

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
		
		/*// Überprüfung ob die Font (Schrift) vorhanden ist!
		if (font.loadFromFile("arial.ttf"))
		{
			Meldung.setFont(font);
			// Meldungsnachricht
			Meldung.setString(MeldungText);
			Meldung.setCharacterSize(24); // In Pixel
			Meldung.setColor(sf::Color::Red);
		}*/

		window.draw(Meldung);
        window.display();
    }   
}
