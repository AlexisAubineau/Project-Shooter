#include "stdafx.h"
#include "Normal_Enemy.h"
#include "Enemy_projectile.h"
#include "Projectile.h"
#include "Game.h"


float shoot_patern = 0;
std::vector<VisibleGameObject> laserArray(20);
EnemyProjectile laser;

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
	
	
	float moveAmount = _velocity * elapsedTime;


	float moveByX = LinearVelocityX(_angle) * moveAmount/3;
	float moveByY = LinearVelocityY(_angle++) * moveAmount;

	
	if (shoot_patern >= 30)
	{
		laser.SetPosition(GetPosition().x, GetPosition().y);
		laserArray.push_back(laser);
		shoot_patern = 0;
	}
	
	for (size_t i = 0; i < laserArray.size(); ++i)
	{
		laserArray[i].Draw(Game::GetWindow());
		laserArray[i].GetSprite().move(-10.0f, 0);
		if (laserArray[i].GetPosition().x == 0)
		{
			laserArray.erase(laserArray.begin() + i);
		}
	}

	if (Projectile().GetBoundingRect().intersects(GetBoundingRect()))
	{
		delete this;
	}
	
	std::cout << Game::_gameObjectManager.GetObjectCount() <<std::endl;
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



