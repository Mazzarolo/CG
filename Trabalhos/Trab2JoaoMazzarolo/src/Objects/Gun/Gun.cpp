#include "Gun.h"

Gun::Gun(int x, int y, int screenHeight)
{
    position.x = x;
    position.y = y;
    limitY = screenHeight;
    speed = 500;
    shootRate = 0.5;
}

Gun::Gun(int x, int y, int screenHeight, float shootRate, int speed)
{
    position.x = x;
    position.y = y;
    limitY = screenHeight;
    this->speed = speed;
    this->shootRate = shootRate;
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
    for (int i = 0; i < projectiles.size(); i++)
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
    for (int i = 0; i < projectiles.size(); i++)
    {
        delete projectiles[i];
    }
    projectiles.clear();
}