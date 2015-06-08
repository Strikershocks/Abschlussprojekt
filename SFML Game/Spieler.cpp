/*Spieler.cpp
**createdate: 03.06.2015
**author: Stefanie Dautz
**last update: 04.06.2015
**description:
**gesammelte Daten des Spielers (Spielfigur, Spielname)*/
#include "Spieler.hpp"

Spieler::Spieler()
{
	this->Leben = 3;
	SetAnimationPosition(100, 100);
}

void Spieler::setModel(std::string model)
{
	this->PlayerModel = model;
}

void Spieler::setName(std::string name)
{this->PlayerName = name;}

void Spieler::setposition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Spieler::MinusLeben(void)
{this->Leben--;}

void Spieler::PlusLeben(void)
{this->Leben++;}


std::string Spieler::getModel(void)
{return this->PlayerModel;}

std::string Spieler::getName(void)
{return this->PlayerName;}

int Spieler::getX()
{
	return animatedSprite.getPosition().x;
}

int Spieler::getY()
{
	return animatedSprite.getPosition().y;
}

int Spieler::getLeben()
{return this->Leben;}

void Spieler::StartAnimation()
{
	animatedSprite.play(*currentAnimation);
}

void Spieler::StopAnimation()
{
	animatedSprite.stop();
}

void Spieler::BewegenSpieler(sf::Vector2f movement, sf::Time frameTime)
{
	animatedSprite.move(movement * frameTime.asSeconds());
}

void Spieler::UpdateAnimation(sf::Time frameTime)
{
	animatedSprite.update(frameTime);
}

void Spieler::ChangeAnimation(int index)
{
	if(index == 1)
	{
		currentAnimation = &walkingAnimationRight;
	}
	else
	{
	}
}

// Animations auswahl nach Player auswahl.
void Spieler::AnimationSelect(std::string PlayerModel)
{
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
}

void Spieler::SetAnimationPosition(float x, float y)
{
	animatedSprite.setPosition(x, y);
}

void Spieler::initSpieler()
{
	// Animation Standards setzen.
	// Ausführung der Animations auswahl
	AnimationSelect(PlayerModel);

	// Setzen der Anfangsanimation
	currentAnimation = &walkingAnimationRight;

	// Setzen der Postion vom AnimationSprite
	animatedSprite.setPosition(sf::Vector2f(535, 100));

		// Textur wird geladen.
	if(!Texture.loadFromFile("Resources/Textures/" + PlayerModel)) 
	{
		// Loading Error der PNG
	}
	Texture.setSmooth(true);
}

void Spieler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(animatedSprite, states);
}