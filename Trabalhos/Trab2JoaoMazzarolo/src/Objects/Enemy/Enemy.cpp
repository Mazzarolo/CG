#include "Enemy.h"

Enemy::Enemy(int screenWidth, int screenHeight, int x, int y, int hitBoxRadius, float speed, int color[3], Animation* sprite, Animation* explosion)
{
    this->position = Vector2(x, y);
    this->hitBoxRadius = hitBoxRadius;
    this->speed = -speed;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
    this->sprite = sprite;
    this->explosion = explosion;
    this->dead = false;
    life = 3;
    explosionTime = 0.5f;
    explosionTimeCounter = 0;
    gun = new Gun(x, y, screenHeight, 0.8f, -300);
}

Enemy::~Enemy()
{
    delete gun;
}

void Enemy::render()
{
    if(!dead)
    {
        move();

        gun->shoot();
    }

    gun->render();

    sprite->setPosition(position.x - sprite->getWidth() / 2, position.y - sprite->getHeight() / 2);
    
    renderSprite();
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
    if(dead && explosionTimeCounter >= explosionTime && gun->isEmpty())
        return true;
    else if(position.y < -100)
        return true;
    else
        return false;
}

bool Enemy::verifyCollision(Vector2 PlayerPosition, int playerRadius, Gun* playerGun)
{
    bool hit = false;

    if ((Collisions::circleCircle(position, hitBoxRadius, PlayerPosition, playerRadius) && !dead) || gun->verifyCollision(PlayerPosition, playerRadius))
    {
        hit = true;
    }

    if(playerGun->verifyCollision(position, hitBoxRadius))
        life--;

    if(life <= 0)
        dead = true;

    return hit;
}

void Enemy::renderSprite()
{
    if(dead)
    {
        if(explosionTimeCounter >= explosionTime)
            return;
        explosion->setPosition(position.x - explosion->getWidth() / 2, position.y - explosion->getHeight() / 2);
        explosion->render();
        explosionTimeCounter += getDeltaTime();
    }
    else
    {
        sprite->render();
    }
}