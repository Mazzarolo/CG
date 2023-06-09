#include "BlockerEnemy.h"

BlockerEnemy::BlockerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Background* background, bool right) : Enemy(screenWidth, screenHeight, x, y, speed)
{
    this->right = right;
    this->background = background;
    this->sprite = sprite;
    this->hitBoxRadius = 20;
    gun = new Gun(x, y, screenHeight, 5.0f, -300);
}

void BlockerEnemy::move(bool accelerating)
{
    Enemy::move(accelerating);

    if(background->checkCollision(position, hitBoxRadius, right))
    {
        right = !right;
    }

    if(right)
        position.x -= speed * 2 *getDeltaTime();
    else
        position.x += speed * 2 * getDeltaTime();
}