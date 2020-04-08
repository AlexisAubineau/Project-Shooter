#pragma once

#include "VisibleGameObject.h"

class Projectile: public VisibleGameObject
{
public:
	Projectile();
	~Projectile();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity;
};
