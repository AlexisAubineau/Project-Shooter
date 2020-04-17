#include "Enemy_Wave_Spawner.h"
#include "Normal_Enemy.h"
#include "stdafx.h"
#include "Game.h"


EnemyWaveSpawner::EnemyWaveSpawner(): _SpawnInterval(0),_TimeDelta(0),_mobCount(0),_mobDestroyed(0),_difficulty(4)
{
	
}

EnemyWaveSpawner::~EnemyWaveSpawner()
{
	
}

void EnemyWaveSpawner::Update(float elapsedTime)
{
	_TimeDelta += elapsedTime;
	
	if (_SpawnInterval <=100)
	{
		_SpawnInterval++;
	}
	
	

	if (_SpawnInterval <= 30)
	{
		_SpawnInterval++;
	}

	if (_SpawnInterval >= 30 && _mobCount <= _difficulty)
	{
		if (_mobDestroyed <= 5)
		{
			NormalEnemy* mobs = new NormalEnemy();
			mobs->SetPosition(800, Game::SCREEN_HEIGHT/2 + rand() % (Game::SCREEN_HEIGHT/2));
			_SpawnInterval = 0;
			Game::_gameObjectManager.Add("mob" + std::to_string(_mobCount), mobs);
			_mobCount++;
		} else
		{
			NormalEnemy* mobs = new NormalEnemy();
			mobs->Load("images/boss_enemy.png");
			mobs->SetPosition(800, Game::SCREEN_HEIGHT/ 2);
			
			Game::_gameObjectManager.Add("mob" + std::to_string(_mobCount), mobs);
			_mobDestroyed = 0;

			_SpawnInterval = 0;
			_difficulty+=4;
			_mobCount++;
		}

		
	}

	for (int i = 0; i < _mobCount; ++i)
	{
		for (int j = 0; j < Game::_gameObjectManager.GetObjectCount(); ++j)
		{
			if (Game::_gameObjectManager.Get("mob" + std::to_string(i)) != nullptr
				&& Game::_gameObjectManager.Get("bullet" + std::to_string(j)) != nullptr
				&& Game::_gameObjectManager.Get("bullet" + std::to_string(j))->GetBoundingRect().intersects(Game::_gameObjectManager.Get("mob" + std::to_string(i))->GetBoundingRect()))
			{
				Game::_gameObjectManager.Remove("mob" + std::to_string(i));
				Game::_gameObjectManager.Remove("bullet" + std::to_string(j));
				_mobCount--;
				_mobDestroyed++;
				break;
				
			}
		}
		
	}
	
}

void EnemyWaveSpawner::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

