#include "Enemy.h"

Enemy::Enemy(int screenWidth, int screenHeight, int x, int y, int hitBoxRadius, float speed, int color[3], Animation* sprite)
{
    this->position = Vector2(x, y);
    this->hitBoxRadius = hitBoxRadius;
    this->speed = -speed;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->sprite = sprite;
    this->dead = false;
    life = 3;
    gun = new Gun(x, y, screenHeight, 1.0f, -400);
}

Enemy::~Enemy()
{
    delete gun;
}

void Enemy::render()
{
    move();

    gun->shoot();
    gun->render();

    sprite->setPosition(position.x - sprite->getWidth() / 2, position.y - sprite->getHeight() / 2);
    sprite->render();
}

void Enemy::move()
{
    if(position.y < -100)
    {
        dead = true;
        return;
    }
    position.y += speed * getDeltaTime();

    gun->move(position.x, position.y);
}

bool Enemy::isDead()
{
    return dead;
}

bool Enemy::verifyCollision(Vector2 PlayerPosition, int playerRadius, Gun* playerGun)
{
    bool hit = false;

    if (Collisions::circleCircle(position, hitBoxRadius, PlayerPosition, playerRadius) || gun->verifyCollision(PlayerPosition, playerRadius))
    {
        hit = true;
    }

    if(playerGun->verifyCollision(position, hitBoxRadius))
        life--;

    if(life <= 0)
        dead = true;

    return hit;
}
