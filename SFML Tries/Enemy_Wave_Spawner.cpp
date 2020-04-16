#include "Enemy_Wave_Spawner.h"
#include "Normal_Enemy.h"
#include "stdafx.h"
#include "Projectile.h"
#include "Game.h"


float SpawnInterval = 0;
float TimeDelta = 0.0f;
int mobCount = 0;
int mobDestroyed = 0;

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

	if (SpawnInterval >= 100 && mobCount <= 2)
	{
		if (mobDestroyed <= 5)
		{
			NormalEnemy* mobs = new NormalEnemy();
			mobs->SetPosition(800, 200 + rand() % 500);
			mobCount++;
			SpawnInterval = 0;
			Game::_gameObjectManager.Add("mob" + std::to_string(mobCount), mobs);
		} else
		{
			NormalEnemy* mobs = new NormalEnemy();
			mobs->Load("images/boss_enemy.png");
			mobs->SetPosition(800, 500);
			mobCount++;
			mobDestroyed = 0;
			SpawnInterval = 0;
			Game::_gameObjectManager.Add("mob" + std::to_string(mobCount), mobs);
		}

		
	}

	for (int i = 0; i < mobCount; ++i)
	{
		for (int j = 0; j < Game::_gameObjectManager.GetObjectCount(); ++j)
		{
			if (Game::_gameObjectManager.Get("mob" + std::to_string(i)) != nullptr
				&& Game::_gameObjectManager.Get("bullet" + std::to_string(j)) != nullptr
				&& Game::_gameObjectManager.Get("mob" + std::to_string(i))->GetBoundingRect().intersects(Game::_gameObjectManager.Get("bullet" + std::to_string(j))->GetBoundingRect()))
			{
				Game::_gameObjectManager.Remove("mob" + std::to_string(i));
				mobCount = 0;
				mobDestroyed++;
				break;
				
			}
		}
			
		
		
	}
	
}

void EnemyWaveSpawner::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

