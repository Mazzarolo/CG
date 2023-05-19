#include "Player.h"

Player::Player(int screenWidth, int screenHeight)
{
    center = Vector2(screenWidth / 2, screenHeight / 5);
    speed = 300;
    shape.push_back(Vector2(0, 15));
    shape.push_back(Vector2(15, -15));
    shape.push_back(Vector2(-15, -15));
    left = right = top = false;
    fixedY = screenHeight / 5;
    color[0] = 1;
    color[1] = color[2] = 0;
}

void Player::render()
{
    move();

    CV::translate(center.x, fixedY);
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

void Player::onKeyboardDown()
{
    switch(getKeyDown())
    {
        case 119:
            top = true;
            break;
        case 97:
            left = true;
            break;
        case 100:
            right = true;
            break;
    }
}

void Player::onKeyboardUp()
{
    switch(getKeyUp())
    {
        case 119:
            top = false;
            break;
        case 97:
            left = false;
            break;
        case 100:
            right = false;
            break;
    }
}

void Player::move()
{
    float speed = this->speed * getDeltaTime();
    if(right)
        center.x += speed;
    if(left)
        center.x -= speed;
    if(top)
        center.y -= speed;

    center.y -= getDeltaTime() * 100;

    if(center.y < -(fixedY) * 4)
        center.y = fixedY;
}

int Player::getY()
{
    return center.y;
}
