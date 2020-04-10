#include "stdafx.h"
#include "PlayerShip.h"
#include "Game.h"
#include "Projectile.h"

float projectiles_count = 0;

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
		//std::cout << "Position Player : x:" << GetSprite().getPosition().y << std::endl;
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
		projectiles_count++;
		Projectile* bullet = new Projectile;
		Game::_gameObjectManager.Add("bullet" + (char)(projectiles_count), bullet);
		bullet->SetPosition(this->GetPosition().x, this->GetPosition().y);
		std::cout << Game::_gameObjectManager.GetObjectCount() << std::endl;
		if (Game::_gameObjectManager.Get("bullet" + (char)(projectiles_count))->GetPosition().x > Game::SCREEN_WIDTH)
		{
			Game::_gameObjectManager.Remove("bullet remove" + (char)(projectiles_count));

		}
	}

	if (_velocityForward > _maxVelocity)
		_velocityForward = _maxVelocity;
	else if (_velocityRight > _maxVelocity)
		_velocityRight = _maxVelocity;

	if (_velocityForward < -_maxVelocity)
		_velocityForward = -_maxVelocity;
	else if (_velocityRight < -_maxVelocity)
		_velocityRight = -_maxVelocity;

	if (GetSprite().getPosition().y >= Game().SCREEN_HEIGHT - 34 || GetSprite().getPosition().y <= 0)
	{
		if (GetSprite().getPosition().y > 0)
		{
			GetSprite().setPosition(GetSprite().getPosition().x, Game().SCREEN_HEIGHT - 34);
			_velocityForward = -_velocityForward / 2;
		}
		else
		{
			GetSprite().setPosition(GetSprite().getPosition().x, 0);
			_velocityForward = -_velocityForward / 2;
		}
	}
	

	if (GetSprite().getPosition().x >= Game().SCREEN_WIDTH - 82 || GetSprite().getPosition().x <= 0)
	{
		if(GetSprite().getPosition().x > 0)
		{
			GetSprite().setPosition(Game().SCREEN_WIDTH - 82, GetSprite().getPosition().y);
			_velocityRight = -_velocityRight / 2;
		}
		else
		{
			GetSprite().setPosition(0, GetSprite().getPosition().y);
			_velocityRight = -_velocityRight / 2;
		}
	}
	
	sf::Vector2f pos = this->GetPosition();
	GetSprite().move(_velocityRight , _velocityForward);
}



