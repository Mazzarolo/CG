#include "Player.h"

Player::Player(int screenWidth, int screenHeight, int startY, int curveHeight)
{
    gun = new Gun(screenWidth / 2, startY, screenHeight);
    center = Vector2(screenWidth / 2, startY);
    sprite = new Animation(5, 2, 10, 0.1f);
    sprite->load("Trab2JoaoMazzarolo\\src\\Images\\Ship.bmp");
    sprite->setPosition(-sprite->getWidth() / 2, -sprite->getHeight() / 2);
    hearth = new Bitmap();
    hearth->load("Trab2JoaoMazzarolo\\src\\Images\\Health.bmp");
    hearth->setPosition(10, screenHeight - hearth->getHeight() - 10);
    hitBoxRadius = 18;
    speed = 300;
    cameraSpeed = 100;
    left = right = top = false;
    fixedY = startY;
    maxY = curveHeight - startY;
    color[0] = 1;
    color[1] = color[2] = 0;
    shooting = false;
    life = 3;
}

Player::~Player()
{
    delete sprite;
}

void Player::render()
{
    move();

    gunControl();

    CV::translate(center.x, fixedY);

    sprite->render();

    CV::translate(0, 0);

    renderHealth();
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
        case 32:
            shooting = true;
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
        case 32:
            shooting = false;
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

void Player::reset(int x)
{
    center.x = x;
    center.y = fixedY;
    life = 3;
    gun->reset();
}

void Player::gunControl()
{
    gun->moveX(center.x);

    if(shooting)
        gun->shoot();
    
    gun->moveX(center.x);

    gun->render();
}

void Player::renderHealth()
{
    for (int i = 0; i < life; i++)
    {
        hearth->render();
        hearth->moveX(hearth->getWidth() + 10);
    }
    hearth->moveX(-hearth->getWidth() * life - 10 * life);
}

bool Player::takeDamage()
{
    life--;
    if(life <= 0)
        return true;
    else
        return false;
}