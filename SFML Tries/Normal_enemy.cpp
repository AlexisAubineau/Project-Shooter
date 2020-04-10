#include "stdafx.h"
#include "Normal_Enemy.h"
#include "Enemy_projectile.h"
#include "Game.h"


float shoot_patern = 0;
float projectile_count = 0;

NormalEnemy::NormalEnemy() :_velocity(-230.0f),
							_elapsedTimeSinceStart(0.0f)
{
	Load("images/normal_enemy.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
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

	if (shoot_patern <= 30)
	{
		shoot_patern++;
	}
	
	if (_elapsedTimeSinceStart < 10.0f)
		return;
	
	float moveAmount = _velocity * elapsedTime;


	float moveByX = LinearVelocityX(_angle) * moveAmount;
	float moveByY = LinearVelocityY(_angle++) * moveAmount;

	EnemyProjectile* laser = new EnemyProjectile;
	if (shoot_patern >= 30)
	{
		projectile_count++;
		Game::_gameObjectManager.Add("Laser"+(char)(projectile_count), laser);
		laser->SetPosition(GetSprite().getPosition().x, GetSprite().getPosition().y);
		shoot_patern = 0;
		std::cout << Game::_gameObjectManager.GetObjectCount() << std::endl;
		
		VisibleGameObject* onGoingLaser = Game::_gameObjectManager.Get(("Laser" + (char(projectile_count))));
		if (onGoingLaser->GetPosition().x <= 0)
		{
			Game::_gameObjectManager.Remove("Laser" + (char(projectile_count)));
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



