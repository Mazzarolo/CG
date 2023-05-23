#include "Player.h"

Player::Player(int screenWidth, int screenHeight, int startY, int curveHeight)
{
    center = Vector2(screenWidth / 2, startY);

    sprite = new Animation(5, 2, 10, 0.1f);
    sprite->load("Trab2JoaoMazzarolo\\src\\Images\\Ship.bmp");
    sprite->setPosition(-sprite->getWidth() / 2, -sprite->getHeight() / 2);

    hearth = new Bitmap();
    hearth->load("Trab2JoaoMazzarolo\\src\\Images\\Health.bmp");
    hearth->setPosition(10, screenHeight - hearth->getHeight() - 10);

    coins = new Animation(9, 1, 9, 0.1f);
    coins->load("Trab2JoaoMazzarolo\\src\\Images\\Coin.bmp");
    coins->setPosition(-coins->getWidth() / 2 + 30, screenHeight - hearth->getHeight() * 2);

    gun = new Gun(screenWidth / 2, startY, screenHeight);

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
    score = 0;
    scorePosition = Vector2(60, screenHeight - 85);

    invincibleTime = invincibleTimeCounter = 1.0f;
    invincibleBlinkTime = invincibleBlinkTimeCounter = 0.1f;
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

    renderSprite();

    CV::translate(0, 0);

    renderStats();
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
    invincibleTime = invincibleTimeCounter = 1.0f;
    invincibleBlinkTime = invincibleBlinkTimeCounter = 0.1f;
}

void Player::gunControl()
{
    gun->moveX(center.x);

    if(shooting)
        gun->shoot();

    gun->moveX(center.x);

    gun->render();
}

void Player::renderStats()
{
    coins->render();

    char scoreText[10];
    sprintf(scoreText, "%d", score);
    CV::color(1, 1, 1);
    CV::textTitle(scorePosition.x, scorePosition.y, scoreText);

    score += 1;

    for (int i = 0; i < life; i++)
    {
        hearth->render();
        hearth->moveX(hearth->getWidth() + 10);
    }

    hearth->moveX(-hearth->getWidth() * life - 10 * life);
}

bool Player::takeDamage()
{
    if(invincibleTimeCounter < invincibleTime)
        return false;
    //PlaySound(TEXT("Trab2JoaoMazzarolo\\src\\Sounds\\Zap.wav"), NULL, SND_ASYNC);
    life--;
    invincibleTimeCounter = 0;
    if(life <= 0)
        return true;
    else
        return false;
}

void Player::renderSprite()
{
    if(invincibleTimeCounter < invincibleTime)
    {
        if(invincibleBlinkTimeCounter > invincibleBlinkTime)
        {
            invincibleBlinkTimeCounter = 0;
            sprite->render();
        }
        invincibleTimeCounter += getDeltaTime();
        invincibleBlinkTimeCounter += getDeltaTime();
    }
    else
    {
        sprite->render();
    }
}
