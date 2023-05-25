#include "Gun.h"

Gun::Gun(int x, int y, int screenHeight)
{
    position.x = x;
    position.y = y;
    limitY = screenHeight;
    speed = 500;
    shootRate = 0.5;
    shootRateCounter = 0;
}

Gun::Gun(int x, int y, int screenHeight, float shootRate, int speed)
{
    position.x = x;
    position.y = y;
    limitY = screenHeight;
    this->speed = speed;
    this->shootRate = shootRate;
    shootRateCounter = 0;
}

void Gun::shoot()
{
    if (shootRateCounter < shootRate)
        return;
    shootRateCounter = 0;
    projectiles.push_back(new Projectile(position.x, position.y, 5, speed, new float[3]{1, 0, 0}, new float[3]{0.3, 0.3, 0.3}));
}

void Gun::render()
{
    shootRateCounter += getDeltaTime();
    for (int i = 0; i < (int) projectiles.size(); i++)
    {
        projectiles[i]->render();
        projectiles[i]->move();
        if(projectiles[i]->getY() > limitY + 10 || projectiles[i]->getY() < -10)
        {
            delete projectiles[i];
            projectiles.erase(projectiles.begin() + i);
        }
    }
}

void Gun::moveX(int x)
{
    position.x = x;
}

void Gun::reset()
{
    for (int i = 0; i < (int) projectiles.size(); i++)
    {
        delete projectiles[i];
    }
    projectiles.clear();
}

bool Gun::verifyCollision(Vector2 position, int radius)
{
    bool hit = false;

    for (int i = 0; i < (int) projectiles.size(); i++)
    {
        if (Collisions::circleCircle(projectiles[i]->getPosition(), projectiles[i]->getRadius(), position, radius) && !projectiles[i]->getEnded())
        {
            projectiles[i]->explode();
            hit = true;
        } else if(projectiles[i]->hasEnded())
        {
            delete projectiles[i];
            projectiles.erase(projectiles.begin() + i);
        }
    }

    return hit;
}

void Gun::move(int x, int y)
{
    position.x = x;
    position.y = y;
}

bool Gun::isEmpty()
{
    return projectiles.empty();
}
