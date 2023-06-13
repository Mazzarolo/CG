#include "Projectile.h"

Animation* Projectile::explosionSprite = NULL;

Projectile::Projectile(int x, int y, int radius, int speed, float* colorCircle, float* colorBorder)
{
    if (explosionSprite == NULL)
        loadExplosionSprite();
    position.x = x;
    position.y = y;
    this->radius = radius;
    this->speed = speed;
    this->colorCircle[0] = colorCircle[0];
    this->colorCircle[1] = colorCircle[1];
    this->colorCircle[2] = colorCircle[2];
    this->colorBorder[0] = colorBorder[0];
    this->colorBorder[1] = colorBorder[1];
    this->colorBorder[2] = colorBorder[2];
    explosionTime = 0.8f;
    explosionTimeCounter = 0;
    ended = false;
    curved = topDown = decelerator = continuous = decending = false;
    enemyId = -1;
    fixedX = x;
}

void Projectile::loadExplosionSprite()
{
    explosionSprite = new Animation(8, 1, 8, 0.1f);
    explosionSprite->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Explosions\\ProjectileExplosion.bmp");
}

void Projectile::render()
{
    renderSprite();
}

void Projectile::move()
{
    if(ended)
        return;

    if(topDown && position.y > 550)
        decending = true;

    if(decending)
    {
        position.y -= speed * getDeltaTime();
    }
    else
    {
        position.y += speed * getDeltaTime();
    }

    if(curved)
    {
        position.x = fixedX + cos(position.y / 50) * getDeltaTime() * 3000;
    }
}

void Projectile::move(bool down)
{
    if(ended)
        return;

    if(down)
        position.y += 2 * speed * getDeltaTime();
    else
        position.y += speed * getDeltaTime();
}

int Projectile::getY()
{
    return position.y;
}

int Projectile::getRadius()
{
    return radius;
}

Vector2 Projectile::getPosition()
{
    return position;
}

void Projectile::renderSprite()
{
    if (!ended)
    {
        CV::color(colorCircle[0], colorCircle[1], colorCircle[2]);
        CV::circleFill(position.x, position.y, radius, 30);
        CV::color(colorBorder[0], colorBorder[1], colorBorder[2]);
        CV::circle(position.x, position.y, radius + 2, 30);
    }
    else
    {
        if(explosionTimeCounter > explosionTime)
            return;
        explosionSprite->setPosition(position.x - explosionSprite->getWidth() / 2, position.y - explosionSprite->getHeight() / 2);
        explosionSprite->render();
        explosionTimeCounter += getDeltaTime();
    }
}

void Projectile::explode()
{
    ended = true;
}

bool Projectile::hasEnded()
{
    return ended && explosionTimeCounter >= explosionTime;
}

bool Projectile::getEnded()
{
    return ended;
}

Projectile* Projectile::clone()
{
    Projectile* p = new Projectile(position.x, position.y, radius, speed, colorCircle, colorBorder);
    p->setTopDown(topDown);
    p->setCurved(curved);
    p->setContinuous(continuous);
    p->setDecelerator(decelerator);
    p->decending = decending;
    return p;
}

void Projectile::setPosition(int x, int y)
{
    position.x = x;
    fixedX = x;
    position.y = y;
}

void Projectile::setSpeed(int speed)
{
    this->speed = speed;
}

void Projectile::setRadius(int radius)
{
    this->radius = radius;
}

void Projectile::setTopDown(bool topDown)
{
    this->topDown = topDown;
    if(!topDown)
        return;
    if(!curved && !continuous && !decelerator)
    {
        colorCircle[0] = 0.5f;
        colorCircle[1] = 0.0f;
        colorCircle[2] = 0.7f;
        return;
    }
    colorCircle[0] = (colorCircle[0] + 0.5f) / 2.0f;
    colorCircle[1] = (colorCircle[1] + 0.0f) / 2.0f;
    colorCircle[2] = (colorCircle[2] + 0.7f) / 2.0f;
}

bool Projectile::getTopDown()
{
    return topDown;
}

void Projectile::setCurved(bool curved)
{
    this->curved = curved;
    if(!curved)
        return;
    if(!topDown && !continuous && !decelerator)
    {
        colorCircle[0] = 0.0f;
        colorCircle[1] = 0.5f;
        colorCircle[2] = 0.7f;
        return;
    }
    colorCircle[0] = (colorCircle[0] + 0.0f) / 2.0f;
    colorCircle[1] = (colorCircle[1] + 0.5f) / 2.0f;
    colorCircle[2] = (colorCircle[2] + 0.7f) / 2.0f;
}

bool Projectile::getCurved()
{
    return curved;
}

void Projectile::setContinuous(bool continuous)
{
    this->continuous = continuous;
    if(!continuous)
        return;
    if(!topDown && !curved && !decelerator)
    {
        colorCircle[0] = 0.7f;
        colorCircle[1] = 0.5f;
        colorCircle[2] = 0.0f;
        return;
    }
    colorCircle[0] = (colorCircle[0] + 0.7f) / 2.0f;
    colorCircle[1] = (colorCircle[1] + 0.5f) / 2.0f;
    colorCircle[2] = (colorCircle[2] + 0.0f) / 2.0f;
}

bool Projectile::getContinuous()
{
    return continuous;
}

void Projectile::setEnemyId(int id)
{
    enemyId = id;
}

int Projectile::getEnemyId()
{
    return enemyId;
}

void Projectile::setDecelerator(bool decelerator)
{
    this->decelerator = decelerator;
    if(!decelerator)
        return;
    if(!topDown && !curved && !continuous)
    {
        colorCircle[0] = 0.5f;
        colorCircle[1] = 0.5f;
        colorCircle[2] = 1.0f;
        return;
    }
    colorCircle[0] = (colorCircle[0] + 0.5f) / 2.0f;
    colorCircle[1] = (colorCircle[1] + 0.5f) / 2.0f;
    colorCircle[2] = (colorCircle[2] + 1.0f) / 2.0f;
}

bool Projectile::getDecelerator()
{
    return decelerator;
}