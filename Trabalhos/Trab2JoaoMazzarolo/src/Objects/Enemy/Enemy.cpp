#include "Enemy.h"

Animation* Enemy::explosion = NULL;

Enemy::Enemy(int screenWidth, int screenHeight, int x, int y, float speed, int life)
{
    if(explosion == NULL)
    {
        explosion = new Animation(5, 1, 5, 0.1f);
        explosion->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Explosions\\ExplosionBig.bmp");
    }

    this->position = Vector2(x, y);
    this->speed = -speed;
    this->dead = false;
    this->life = life;
    explosionTime = 0.5f;
    explosionTimeCounter = 0;
}

Enemy::~Enemy()
{
    delete gun;
}

void Enemy::render(bool accelerating)
{
    if(!dead)
    {
        move(accelerating);

        gun->shoot();
    }

    gun->render(accelerating);

    sprite->setPosition(position.x - sprite->getWidth() / 2, position.y - sprite->getHeight() / 2);
    
    //CV::color(1, 0, 0);
    //CV::circle(position.x, position.y, hitBoxRadius, 30);
    renderSprite();
}

void Enemy::move(bool accelerating)
{
    if(position.y < -100)
    {
        dead = true;
        return;
    }
    if(accelerating)
        position.y += 2 * speed * getDeltaTime();
    else
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