/*Spieler.cpp
**createdate: 03.06.2015
**author: Stefanie Dautz
**last update: 04.06.2015
**description:
**gesammelte Daten des Spielers (Spielfigur, Spielname)*/
#include "Spieler.hpp"

// Einstellen der animatedSprite
AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);

Spieler::Spieler()
{
	if(!Herz.loadFromFile("Resources/Textures/heart.png")) 
	{
		// Loading Error der PNG
	}
	Herz.setSmooth(true);

	this->PlusLeben();
	this->PlusLeben();
	this->PlusLeben();

	animatedSprite.setPosition(200, 200);
}

void Spieler::setName(std::string name)
{
	if (!font.loadFromFile("Resources/Sansation.ttf"))
	{
		// handle error
	}
	Name.setFont(font);
	Name.setPosition( 40, 80);
	this->Name.setString(name);
}

void Spieler::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Spieler::MinusLeben(void)
{this->Lebensanzeige.pop_back();}

void Spieler::PlusLeben(void)
{
	sf::Sprite Leben;
	Leben.setTexture(Herz);
	Leben.setPosition(40 + getLeben() * 40, 40);

	this->Lebensanzeige.push_back(Leben);
}

std::string Spieler::getName(void)
{
	return this->Name.getString();
}

int Spieler::getX()
{
	return animatedSprite.getPosition().x;
}

int Spieler::getY()
{
	return animatedSprite.getPosition().y;
}

int Spieler::getLeben()
{
	return this->Lebensanzeige.size();
}

void Spieler::AnimationTest(sf::Vector2f movement, sf::Time frameTime, int index, std::string PlayerModel)
{
	if(!Texture.loadFromFile("Resources/Textures/" + PlayerModel)) 
	{
		// Loading Error der PNG
	}

	Texture.setSmooth(true);

	if(PlayerModel != "HinagikuSprite.png")
	{
		// Animation setzen für Rechts Bewegen.
		walkingAnimationRight.setSpriteSheet(Texture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
		walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));
	}
	else if(PlayerModel == "HinagikuSprite.png")
	{
		// Animation setzen für Rechts Bewegen.
		walkingAnimationRight.setSpriteSheet(Texture);
		walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect(64, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect(32, 96, 32, 48));
		walkingAnimationRight.addFrame(sf::IntRect( 0, 96, 32, 48));

	}

	Animation* currentAnimation = &walkingAnimationRight;

	if(index == 0)
	{
		animatedSprite.play(*currentAnimation);
		
	}
	else
	{
		animatedSprite.stop();

	}
	animatedSprite.move(movement * frameTime.asSeconds());
	Name.move(movement.x * frameTime.asSeconds(), 0);

	for(int i = 0; i <Lebensanzeige.size(); i++)
		Lebensanzeige[i].move(movement.x * frameTime.asSeconds(), 0);
	
	// update AnimatedSprite
    animatedSprite.update(frameTime);
	
	

}

void Spieler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(animatedSprite, states);
	target.draw(Name, states);

	for(int i = 0; i < Lebensanzeige.size(); i++)
	{
		target.draw(Lebensanzeige[i], states);
	}
}