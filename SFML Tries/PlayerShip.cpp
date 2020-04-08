#include "stdafx.h"
#include "PlayerShip.h"
#include "Game.h"

PlayerShip::PlayerShip():_velocityRight(0), _velocityForward(0)
{
	Load("images/ship.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerShip::GetVelocity() const
{
	return _velocityRight, _velocityForward;
}

void PlayerShip::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		_velocityForward += 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_velocityForward -= 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		_velocityRight += 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_velocityRight -= 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		
	}
	
	sf::Vector2f pos = this->GetPosition();

	if (pos.x < GetSprite().getScale().x / 1
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getScale().x / 1)
		|| pos.y < GetSprite().getScale().y / 1
		|| pos.y < (Game::SCREEN_HEIGHT - GetSprite().getScale().y / 1))
	{
		_velocityForward = -_velocityForward; //Limits movement to the screen size
		_velocityRight = -_velocityRight ; //Limits movement to the screen size
	}

	std::cout << "Vitesse Forward : " << _velocityForward << "\nVitesse Right : " << _velocityRight << std::endl;

	GetSprite().move(_velocityRight , _velocityForward);
}



