#pragma once

#include "VisibleGameObject.h"

class EnemyProjectile : public VisibleGameObject
{
public:
	EnemyProjectile();
	~EnemyProjectile();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);
};
