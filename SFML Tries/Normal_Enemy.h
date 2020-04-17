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

	float _shoot_patern = 0;
	int _lasernbr = 0;

	float LinearVelocityX(float angle);
	float LinearVelocityY(float angle);
};

