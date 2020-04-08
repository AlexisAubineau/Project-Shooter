#include "stdafx.h"
#include "PlayerShip.h"
#include "Game.h"
#include "Projectile.h"

Projectile* bullet = new Projectile;

PlayerShip::PlayerShip():_velocityRight(0), _velocityForward(0), _maxVelocity(10)
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
		_velocityForward -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_velocityForward += 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		_velocityRight -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_velocityRight += 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::_gameObjectManager.Add("Bullet", bullet + 1);
		bullet->SetPosition(GetSprite().getPosition().x + 90, GetSprite().getPosition().y + 8);
		std::cout << "New projectile : " << bullet->GetPosition().x << ", " << bullet->GetPosition().y << std::endl;
	}

	if (_velocityForward > _maxVelocity)
		_velocityForward = _maxVelocity;
	else if (_velocityRight > _maxVelocity)
		_velocityRight = _maxVelocity;

	if (_velocityForward < -_maxVelocity)
		_velocityForward = -_maxVelocity;
	else if (_velocityRight < -_maxVelocity)
		_velocityRight = -_maxVelocity;
	
	sf::Vector2f pos = this->GetPosition();

	/*if (pos.x < GetSprite().getScale().x / 1
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getScale().x / 1)
		|| pos.y < GetSprite().getScale().y / 1
		|| pos.y < (Game::SCREEN_HEIGHT - GetSprite().getScale().y / 1))
	{
		_velocityForward = -_velocityForward; //Limits movement to the screen size
		_velocityRight = -_velocityRight ; //Limits movement to the screen size
	}*/

	GetSprite().move(_velocityRight , _velocityForward);
}



