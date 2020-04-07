#include "stdafx.h"
#include "PlayerShip.h"
#include "Game.h"

PlayerShip::PlayerShip():_velocity(0),
_maxVelocity(600.0f)
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
	return _velocity;
}

void PlayerShip::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		_velocity += 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_velocity -= 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		_velocity -= 10.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_velocity += 10.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;
	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;

	sf::Vector2f pos = this->GetPosition();

	if (pos.x < GetSprite().getScale().x / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getScale().x / 2)
		|| pos.y < GetSprite().getScale().y / 2
		|| pos.y < (Game::SCREEN_HEIGHT - GetSprite().getScale().y / 2))
	{
		_velocity = -_velocity; //Limits movement to the screen size
	}

	GetSprite().move(_velocity * elapsedTime, 0);
}



