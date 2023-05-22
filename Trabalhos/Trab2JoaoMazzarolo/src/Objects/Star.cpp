#include "Star.h"

Star::Star(int x, int y, int radius)
{
    speed = 50;
    position.x = x;
    position.y = y;
    this->radius = radius;
}

void Star::render()
{
    CV::color(1, 1, 1);
    CV::circleFill(position.x, position.y, radius, 30);
}

void Star::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void Star::naturalMove(int screenHeight)
{
    int speed = this->speed;
    position.y -= speed * getDeltaTime();
    if(position.y < 0)
    {
        position.y = screenHeight;
    }
}