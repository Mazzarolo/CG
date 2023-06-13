#include "BlockerEnemy.h"

BlockerEnemy::BlockerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Background* background, bool right, int life) : Enemy(screenWidth, screenHeight, x, y, speed, life)
{
    this->right = right;
    this->background = background;
    this->sprite = sprite;
    this->hitBoxRadius = 20;
    gun = new Gun(x, y, screenHeight, 5.0f - speed * 0.001, -speed * 3);
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