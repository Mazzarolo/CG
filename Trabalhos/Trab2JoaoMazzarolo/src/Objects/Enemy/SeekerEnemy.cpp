#include "SeekerEnemy.h"

SeekerEnemy::SeekerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Player* player) : Enemy(screenWidth, screenHeight, x, y, speed)
{
    this->sprite = sprite;
    this->player = player;
    this->hitBoxRadius = 32;
    gun = new Gun(x, y, screenHeight, 0.8f, -300);
}

void SeekerEnemy::move(bool accelerating)
{
    Enemy::move(accelerating);
    if(player->getPosition().x < position.x)
        position.x += speed * getDeltaTime();
    else
        position.x -= speed * getDeltaTime();
}