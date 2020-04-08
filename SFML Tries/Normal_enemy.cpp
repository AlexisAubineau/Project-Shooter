#include "stdafx.h"
#include "Normal_Enemy.h"
#include "Game.h"
#include <chrono>

NormalEnemy::NormalEnemy() :_velocity(0),
_maxVelocity(600.0f)
{
	Load("images/normal_enemy.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
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
		_velocity += 10.0f;


	sf::Vector2f pos = this->GetPosition();

	if (pos.x < GetSprite().getScale().x / 2
		|| pos.x >(Game::SCREEN_WIDTH - GetSprite().getScale().x / 2)
		|| pos.y < GetSprite().getScale().y / 2
		|| pos.y < (Game::SCREEN_HEIGHT - GetSprite().getScale().y / 2))
	{
		_velocity = -_velocity; //Limits movement to the screen size
	}

	GetSprite().move(_velocity * elapsedTime, _velocity);
}



