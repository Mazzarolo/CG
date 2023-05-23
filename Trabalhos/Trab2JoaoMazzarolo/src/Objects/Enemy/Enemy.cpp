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
    gun = new Gun(screenWidth / 2, screenHeight, screenHeight, 0.5f, -400);
}

void Enemy::render()
{
    move();

    sprite->setPosition(position.x - sprite->getWidth() / 2, position.y - sprite->getHeight() / 2);
    sprite->render();

    gun->render();
}

void Enemy::move()
{
    if(position.y < -100)
    {
        dead = true;
        return;
    }
    position.y += speed * getDeltaTime();

    gun->moveX(position.x);
}

bool Enemy::isDead()
{
    return dead;
}
