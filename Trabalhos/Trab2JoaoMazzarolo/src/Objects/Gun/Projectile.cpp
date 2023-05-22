#include "Projectile.h"

Projectile::Projectile(int x, int y, int radius, int speed, float* colorCircle, float* colorBorder)
{
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
}

void Projectile::render()
{
    CV::color(colorCircle[0], colorCircle[1], colorCircle[2]);
    CV::circleFill(position.x, position.y, radius, 30);
    CV::color(colorBorder[0], colorBorder[1], colorBorder[2]);
    CV::circle(position.x, position.y, radius + 2, 30);
}

void Projectile::move()
{
    position.y += speed * getDeltaTime();
}

int Projectile::getY()
{
    return position.y;
}