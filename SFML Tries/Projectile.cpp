#include "Projectile.h"
#include <cassert>


Projectile::Projectile()
{
	Load("images/");
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

void Projectile::Update(float elapsedTime)
{
	
}
