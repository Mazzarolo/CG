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
    //printf("%.f %.f\n", position.x, position.y);
}

void Projectile::loadExplosionSprite()
{
    explosionSprite = new Animation(8, 1, 8, 0.1f);
    explosionSprite->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Explosions\\ProjectileExplosion.bmp");
}

void Projectile::render()
{
    renderSprite();
}

void Projectile::move()
{
    if(ended)
        return;
    position.y += speed * getDeltaTime();
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
}

void Projectile::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}