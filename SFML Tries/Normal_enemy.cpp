#include "stdafx.h"
#include "Normal_Enemy.h"
#include "Enemy_projectile.h"
#include "Projectile.h"
#include "Game.h"



NormalEnemy::NormalEnemy() :_velocity(-230.0f),
							_elapsedTimeSinceStart(0.0f),
							_shoot_patern(0),
							_lasernbr(0)
{
	Load("images/normal_enemy.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
	float random_int = std::rand() % 360 + 1;
	_angle = random_int;
}

NormalEnemy::~NormalEnemy()
{
}

void NormalEnemy::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

float NormalEnemy::GetVelocity() const
{
	return _velocity;
}

void NormalEnemy::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;

	if (_shoot_patern <= 30)
	{
		_shoot_patern++;
	}
	
	
	float moveAmount = _velocity * elapsedTime;


	float moveByX = LinearVelocityX(_angle) * moveAmount/3;
	float moveByY = LinearVelocityY(_angle++) * moveAmount;

	
	if (_shoot_patern >= 30)
	{
		EnemyProjectile* laser = new EnemyProjectile;
		laser->SetPosition(GetPosition().x, GetPosition().y);
		Game::_gameObjectManager.Add("laser" + std::to_string(_lasernbr), laser);
		_lasernbr++;
		_shoot_patern = 0;
	}
	
	for (int i = 0; i < _lasernbr; ++i)
	{
		
		if (Game::_gameObjectManager.Get("laser" + std::to_string(i)) != nullptr && 
			Game::_gameObjectManager.Get("laser"+std::to_string(i))->GetPosition().x <= 0)
		{
			Game::_gameObjectManager.Remove("laser" + std::to_string(i));
			_lasernbr = 0;
			break;
		}
		
	}
	
	GetSprite().move(moveByX, moveByY);
}

float NormalEnemy::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0) angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float NormalEnemy::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0) angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 40.0f));
}



