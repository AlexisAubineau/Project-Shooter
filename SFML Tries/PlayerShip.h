#pragma once
#include "VisibleGameObject.h"

class PlayerShip : public VisibleGameObject
{
public:
	PlayerShip();
	~PlayerShip();
	
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);
	float GetVelocity() const;

private:
	float _velocityRight;
	float _velocityForward;
	float _maxVelocity;
};
