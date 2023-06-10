#include "SeekerEnemy.h"

SeekerEnemy::SeekerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Player* player, int life) 
    : Enemy(screenWidth, screenHeight, x, y, speed, life)
{
    this->sprite = sprite;
    this->player = player;
    this->hitBoxRadius = 32;
    gun = new Gun(x, y, screenHeight, 0.8f - speed * 0.001, -speed * 3); 
}

void SeekerEnemy::move(bool accelerating)
{
    Enemy::move(accelerating);
    if(player->getPosition().x < position.x)
        position.x += speed * getDeltaTime();
    else
        position.x -= speed * getDeltaTime();
}