#include "Player.h"

Player::Player(int screenWidth, int screenHeight)
{
    center = Vector2(screenWidth / 2, screenHeight / 2);
    speed = 5;
    shape.push_back(Vector2(0, 15));
    shape.push_back(Vector2(15, -15));
    shape.push_back(Vector2(-15, -15));
    left = right = top = down = false;
    yScreenCenter = screenHeight / 2;
    color[0] = 1;
    color[1] = color[2] = 0;
}

void Player::render()
{
    move();
    CV::translate(center.x, yScreenCenter);
    float xPoints[3], yPoints[3];
    for (int i = 0; i < 3; i++)
    {
        xPoints[i] = shape.at(i).x;
        yPoints[i] = shape.at(i).y;
    }
    CV::color(color[0], color[1], color[2]);
    CV::polygonFill(xPoints, yPoints, 3);
    CV::translate(0, 0);
}

void Player::getKeys(int key)
{
    switch(key)
    {
        case 119:
            top = true;
            break;
        case 115:
            down = true;
            break;
        case 97:
            left = true;
            break;
        case 100:
            right = true;
            break;
    }
}

void Player::move()
{
    if(right)
        center.x += speed;
    if(left)
        center.x -= speed;
    if(top)
        center.y -= speed;
    if(down)
        center.y += speed;

    if(center.y < -(yScreenCenter))
        center.y = yScreenCenter;
}

void Player::brake(int key)
{
    switch(key)
    {
        case 119:
            top = false;
            break;
        case 115:
            down = false;
            break;
        case 97:
            left = false;
            break;
        case 100:
            right = false;
            break;
    }
}

int Player::getY()
{
    return center.y;
}