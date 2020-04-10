#include "stdafx.h"
#include "Normal_Enemy.h"
#include "Game.h"

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
	
	if (_elapsedTimeSinceStart < 3.0f)
		return;
	
	float moveAmount = _velocity * elapsedTime;


	float moveByX = LinearVelocityX(_angle) * moveAmount;
	float moveByY = LinearVelocityY(_angle++) * moveAmount;

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



