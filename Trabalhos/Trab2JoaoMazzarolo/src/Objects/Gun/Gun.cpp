#include "Gun.h"

Gun::Gun(int x, int y, int screenHeight, int radius)
{
    this->radius = radius;
    position.x = x;
    position.y = y;
    limitY = screenHeight;
    speed = 500;
    shootRate = 0.5;
    shootRateCounter = 0;
    numProjectiles = 1;
    projectileRadius = 5;
    damage = 1;
    projectileModel = new Projectile(position.x, position.y, projectileRadius, speed, new float[3]{1, 0, 0}, new float[3]{0.3, 0.3, 0.3});
}

Gun::Gun(int x, int y, int screenHeight, float shootRate, int speed)
{
    position.x = x;
    position.y = y;
    limitY = screenHeight;
    this->speed = speed;
    this->shootRate = shootRate;
    shootRateCounter = 0;
    numProjectiles = 1;
    projectileRadius = 5;
    damage = 1;
    projectileModel = new Projectile(position.x, position.y, projectileRadius, speed, new float[3]{1, 0, 0}, new float[3]{0.3, 0.3, 0.3});
}

void Gun::shoot()
{
    if (shootRateCounter < shootRate)
        return;
    shootRateCounter = 0;
    if(numProjectiles == 1)
    {
        Projectile* projectile = projectileModel->clone();
        projectile->setPosition(position.x, position.y);
        projectiles.push_back(projectile);
        return;
    }

    int offset = radius / (numProjectiles - 1);
    for(int i = 0; i < numProjectiles; i++)
    {
        Projectile* projectile = projectileModel->clone();
        projectile->setPosition(position.x - (radius / 2) + offset * i, position.y);
        projectiles.push_back(projectile);
    }
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

void Gun::render(bool down)
{
    shootRateCounter += getDeltaTime();
    for (int i = 0; i < (int) projectiles.size(); i++)
    {
        projectiles[i]->render();
        projectiles[i]->move(down);
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
    delete projectileModel;
    damage = 1;
    speed = 500;
    shootRate = 0.5;
    shootRateCounter = 0;
    numProjectiles = 1;
    projectileRadius = 5;
    projectileModel = new Projectile(position.x, position.y, projectileRadius, speed, new float[3]{1, 0, 0}, new float[3]{0.3, 0.3, 0.3});
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

void Gun::addShootRate(float shootRate)
{
    this->shootRate *= shootRate;
}

void Gun::addSpeed(int speed)
{
    this->speed *= speed;
}

void Gun::addShoot()
{
    numProjectiles++;
}

void Gun::addProjectileRadius(int radius)
{
    projectileRadius += radius;
}

void Gun::addDamage(int damage)
{
    this->damage += damage;
}

int Gun::getDamage()
{
    return damage;
}