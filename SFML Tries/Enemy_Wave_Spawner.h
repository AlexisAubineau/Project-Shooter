#pragma once

#include "VisibleGameObject.h"

class EnemyWaveSpawner : public VisibleGameObject
{
public:
	EnemyWaveSpawner();
	~EnemyWaveSpawner();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

};
