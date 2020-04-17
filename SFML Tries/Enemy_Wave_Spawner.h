#pragma once

#include "VisibleGameObject.h"

class EnemyWaveSpawner : public VisibleGameObject
{
public:
	EnemyWaveSpawner();
	~EnemyWaveSpawner();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

private:
	float _SpawnInterval;
	float _TimeDelta;
	int _mobCount;
	int _mobDestroyed;
	int _difficulty;

};
