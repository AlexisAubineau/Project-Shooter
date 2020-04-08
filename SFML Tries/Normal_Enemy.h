#pragma once
#include "VisibleGameObject.h"

class NormalEnemy : public VisibleGameObject
{
public:
	NormalEnemy();
	virtual ~NormalEnemy();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity;
	float _maxVelocity;
};

