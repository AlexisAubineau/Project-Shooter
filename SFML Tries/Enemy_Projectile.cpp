#include "Enemy_projectile.h"
#include "stdafx.h"
#include "Game.h"



EnemyProjectile::EnemyProjectile()
{
	Load("images/bullet_enemy.png");
	assert(IsLoaded());
	GetSprite().setOrigin(GetSprite().getScale().x / 2, GetSprite().getScale().y / 2);
	
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::Draw(sf::RenderWindow& rw)
{
	VisibleGameObject::Draw(rw);
}


void EnemyProjectile::Update(float elapsedTime)
{
	GetSprite().move(-10.0f,0.0f);
}
