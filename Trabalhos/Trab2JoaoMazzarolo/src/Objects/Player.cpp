#include "Player.h"

Player::Player(int screenWidth, int screenHeight, int startY, int curveHeight)
{
    center = Vector2(screenWidth / 2, startY);
    hitBoxRadius = 15;
    speed = 300;
    cameraSpeed = 100;
    shape.push_back(Vector2(0, 15));
    shape.push_back(Vector2(15, -15));
    shape.push_back(Vector2(-15, -15));
    left = right = top = false;
    fixedY = startY;
    maxY = curveHeight - startY;
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
        xPoints[i] = shape[i].x;
        yPoints[i] = shape[i].y;
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

    center.y -= getDeltaTime() * cameraSpeed;

    if(center.y < -maxY)
        center.y = fixedY;
}

int Player::getY()
{
    return center.y;
}

Vector2 Player::getPosition()
{
    //printf("%f %d\n", center.x, fixedY);
    return Vector2(center.x, fixedY);
}

void Player::setX(int x)
{
    center.x = x;
}

vector<Vector2> Player::getShapeAbs()
{
    vector<Vector2> shapeAbs;
    for (int i = 0; i < 3; i++)
    {
        shapeAbs.push_back(Vector2(shape[i].x + center.x, shape[i].y + fixedY));
        printf("%.1f %.1f\n", shapeAbs[i].x, shapeAbs[i].y);
    }
    return shape;
}

int Player::getHitBoxRadius()
{
    return hitBoxRadius;
}