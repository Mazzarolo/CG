#include "SmallEnemy.h"

SmallEnemy::SmallEnemy(int screenWidth, int screenHeight, int x, int y, float speed, int minX, int maxX, bool right, Animation* sprite, int life) 
    : Enemy(screenWidth, screenHeight, x, y, speed, life)
{
    this->minX = minX;
    this->maxX = maxX;
    this->right = right;
    this->sprite = sprite;
    this->hitBoxRadius = 16;
    gun = new Gun(x, y, screenHeight, 0.8f - speed * 0.001, -speed * 3);
}

void SmallEnemy::move(bool accelerating)
{
    Enemy::move(accelerating);
    if(right)
    {
        if(position.x < maxX)
            position.x -= speed * 2 *getDeltaTime();
        else
            right = false;
    }
    else
    {
        if(position.x > minX)
            position.x += speed * 2 * getDeltaTime();
        else
            right = true;
    }
}