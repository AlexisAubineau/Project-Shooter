#include "Enemy_Wave_Spawner.h"
#include "Normal_Enemy.h"
#include "stdafx.h"
#include "Projectile.h"
#include "Game.h"


float SpawnInterval = 0;
float TimeDelta = 0.0f;
int mobCount = 0.0f;

EnemyWaveSpawner::EnemyWaveSpawner()
{
	
}

EnemyWaveSpawner::~EnemyWaveSpawner()
{
	
}

void EnemyWaveSpawner::Update(float elapsedTime)
{
	TimeDelta += elapsedTime;
	
	if (SpawnInterval <=100)
	{
		SpawnInterval++;
	}
	
	

	if (SpawnInterval <= 100)
	{
		SpawnInterval++;
	}

	NormalEnemy* mobs = new NormalEnemy();

	if (SpawnInterval >= 100 && mobCount <= 5)
	{
		Game::_gameObjectManager.Add("mob" +std::to_string(mobCount), mobs);
		mobs->SetPosition(800, 200 + rand() % 800);
		mobCount++;
		SpawnInterval = 0;
	}
	
}

void EnemyWaveSpawner::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

