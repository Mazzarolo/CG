#include "SeekerEnemy.h"

SeekerEnemy::SeekerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite) : Enemy(screenWidth, screenHeight, x, y, speed)
{
    this->sprite = sprite;
    this->hitBoxRadius = 32;
    gun = new Gun(x, y, screenHeight, 0.8f, -300);
}

void SeekerEnemy::move()
{
    Enemy::move();
}