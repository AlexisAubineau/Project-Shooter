#pragma once
#include "VisibleGameObject.h"

class NormalEnemy : public VisibleGameObject
{
public:
	NormalEnemy();
	virtual ~NormalEnemy();

	void Update(float);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity;
	float _angle;
	float _elapsedTimeSinceStart;

	float LinearVelocityX(float angle);
	float LinearVelocityY(float angle);
};

