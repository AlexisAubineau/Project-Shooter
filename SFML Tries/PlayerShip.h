#pragma once
#include "Projectile.h"
#include "VisibleGameObject.h"

class PlayerShip : public VisibleGameObject
{
public:
	PlayerShip();
	~PlayerShip();
	
	void Update(float elapsedTime);
	void PlayerControl();
	void PlayerDeplacementZone();
	void PlayerShoot();
	void PlayerShootRemove();
	void PlayerDeath();
	void Draw(sf::RenderWindow& rw);
	
	float GetVelocity() const;

private:
	float _velocityRight;
	float _velocityForward;
	float _maxVelocity;
	
	int _playerProjectile;
};
