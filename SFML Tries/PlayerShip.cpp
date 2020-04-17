#include "stdafx.h"
#include "PlayerShip.h"
#include "Game.h"
#include "Projectile.h"

PlayerShip::PlayerShip(): _velocityRight(0), _velocityForward(0), _maxVelocity(10), _playerProjectile(0)
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

void PlayerShip::PlayerControl()
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
		PlayerShoot();
	}

	if (_velocityForward > _maxVelocity)
		_velocityForward = _maxVelocity;
	else if (_velocityRight > _maxVelocity)
		_velocityRight = _maxVelocity;

	if (_velocityForward < -_maxVelocity)
		_velocityForward = -_maxVelocity;
	else if (_velocityRight < -_maxVelocity)
		_velocityRight = -_maxVelocity;

	GetSprite().move(_velocityRight, _velocityForward);
}

void PlayerShip::PlayerDeplacementZone()
{
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
		if (GetSprite().getPosition().x > 0)
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
}

void PlayerShip::PlayerShoot()
{
	Projectile* bullet = new Projectile;
	bullet->SetPosition(GetPosition().x, GetPosition().y);
	Game::_gameObjectManager.Add("bullet" + std::to_string(_playerProjectile), bullet);
	_playerProjectile++;
}


void PlayerShip::PlayerShootRemove()
{
	for (int i = 0; i < _playerProjectile; ++i)
	{
		if (Game::_gameObjectManager.Get("bullet" + std::to_string(i)) != nullptr &&
			Game::_gameObjectManager.Get("bullet" + std::to_string(i))->GetPosition().x >= Game::SCREEN_WIDTH)
		{
			Game::_gameObjectManager.Remove("bullet" + std::to_string(i));
			_playerProjectile = 0;
			break;
		}
	}
}

void PlayerShip::PlayerDeath()
{
	for (int j = 0; j < Game::_gameObjectManager.GetObjectCount(); ++j)
	{
		if (Game::_gameObjectManager.Get("laser" + std::to_string(j)) != nullptr
			&& Game::_gameObjectManager.Get("Player1")->GetBoundingRect().intersects(
				Game::_gameObjectManager
				.Get("laser" + std::to_string(j))->GetBoundingRect()))
		{
			_velocityForward = 0;
			_velocityRight = 0;
			Game::_gameObjectManager.Remove("Player1");
			break;
		}
	}
}


void PlayerShip::Update(float elapsedTime)
{
	PlayerControl();
	PlayerDeplacementZone();
	PlayerShootRemove();
	PlayerDeath();
}
