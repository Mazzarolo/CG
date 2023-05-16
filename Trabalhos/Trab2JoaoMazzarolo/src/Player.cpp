#include "Player.h"

Player::Player(int screenWidth, int screenHeight)
{
    center = Vector2(screenWidth / 2, screenHeight / 2);
    speed = Vector2(0, 0);
    shape.push_back(Vector2(0, 15));
    shape.push_back(Vector2(15, -15));
    shape.push_back(Vector2(-15, -15));
    maxSpeed = 1;
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
    moving = true;
    switch(key)
    {
        case 119:
            if(speed.y > -maxSpeed)
                speed.y--;
            break;
        case 115:
            if(speed.y < maxSpeed)
                speed.y++;
            break;
        case 97:
            if(speed.x > -maxSpeed)
                speed.x--;
            break;
        case 100:
            if(speed.x < maxSpeed)
                speed.x++;
            break;
        default:
            moving = false;
            break;
    }
}

void Player::move()
{
    if(!moving)
    {
        if(speed.x > 0)
            speed.x--;
        else if(speed.x < 0)
            speed.x++;
        if(speed.y > 0)
            speed.y--;
        else if(speed.y < 0)
            speed.y++;
    }
    center = center + speed;
}

void Player::brake(int key)
{
    if(key == 119 || key == 115 || key == 97 || key == 100)
        moving = false;
}

int Player::getY()
{
    return center.y;
}
