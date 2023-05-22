#include "Player.h"

Player::Player(int screenWidth, int screenHeight, int startY, int curveHeight)
{
    center = Vector2(screenWidth / 2, startY);
    sprite = new Animation(5, 2, 10, 0.1f);
    sprite->load("Trab2JoaoMazzarolo\\src\\Images\\Ship.bmp");
    sprite->setPosition(-sprite->getWidth() / 2, -sprite->getHeight() / 2);
    hitBoxRadius = 23;
    speed = 300;
    cameraSpeed = 100;
    left = right = top = false;
    fixedY = startY;
    maxY = curveHeight - startY;
    color[0] = 1;
    color[1] = color[2] = 0;
}

Player::~Player()
{
    delete sprite;
}

void Player::render()
{
    move();

    CV::translate(center.x, fixedY);

    sprite->render();

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

int Player::getHitBoxRadius()
{
    return hitBoxRadius;
}
