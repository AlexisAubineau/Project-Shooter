#include "Projectile.h"
#include "stdafx.h"
#include "Game.h"

Projectile* bullet = new Projectile;

Projectile::Projectile()
{
	Load("images/bullet.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
}

Projectile::~Projectile()
{
}

void Projectile::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}

void Projectile::SpawnBullet()
{
	sf::String bullets;
	bullets = "Projectile";
	Game::_gameObjectManager.Add(bullets, bullet);
	bullet->SetPosition(PlayerShip().GetPosition().x + 90, PlayerShip().GetPosition().y + 8);
	std::cout << bullet << ": " << bullet->GetPosition().x << ", " << bullet->GetPosition().y << std::endl;
}

float Projectile::GetVelocity() const
{
	return _velocity;
}

void Projectile::Update(float elapsedTime)
{
	
}
