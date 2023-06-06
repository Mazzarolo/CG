#include "BlockerEnemy.h"

BlockerEnemy::BlockerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Background* background, bool right) : Enemy(screenWidth, screenHeight, x, y, speed)
{
    this->right = right;
    this->background = background;
    this->sprite = sprite;
    this->hitBoxRadius = 20;
    gun = new Gun(x, y, screenHeight, 1.5f, -300);
}

void BlockerEnemy::move(bool accelerating)
{
    Enemy::move(accelerating);
    if(right)
    {
        if(position.x < background->getAllX(position.y)[0])
            position.x -= speed * 2 *getDeltaTime();
        else
            right = false;
    }
    else
    {
        if(position.x > background->getAllX(position.y)[1])
            position.x += speed * 2 * getDeltaTime();
        else
            right = true;
    }
}