#include "Projectile.h"
#include "stdafx.h"
#include "Game.h"

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

float Projectile::GetVelocity() const
{
	return _velocity;
}

void Projectile::Update(float elapsedTime)
{
	GetSprite().move(10.0f, 0.0f);
}
