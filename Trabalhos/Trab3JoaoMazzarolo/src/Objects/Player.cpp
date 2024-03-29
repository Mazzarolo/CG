#include "Player.h"

Player::Player(int screenWidth, int screenHeight, int startY, int curveHeight)
{
    center = Vector2(screenWidth / 2, startY);

    sprite = new Animation(5, 2, 10, 0.1f);
    sprite->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Ship.bmp");
    sprite->setPosition(-sprite->getWidth() / 2, -sprite->getHeight() / 2);

    hearth = new Bitmap();
    hearth->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Health.bmp");
    hearth->setPosition(10, screenHeight - hearth->getHeight() - 10);

    coins = new Animation(9, 1, 9, 0.1f);
    coins->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Coin.bmp");
    coins->setPosition(-coins->getWidth() / 2 + 30, screenHeight - hearth->getHeight() * 2);

    explosion = new Animation(5, 1, 5, 0.1f);
    explosion->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Explosions\\ExplosionBig.bmp");
    explosion->setPosition(-explosion->getWidth() / 2, -explosion->getHeight() / 2);

    hitBoxRadius = 18;
    gun = new Gun(screenWidth / 2, startY, screenHeight, hitBoxRadius);
    speed = 300;
    cameraSpeed = cameraSpeedChanger = 100;
    left = right = top = false;
    fixedY = startY;
    maxY = curveHeight - startY;
    color[0] = 1;
    color[1] = color[2] = 0;
    shooting = false;
    life = 3;
    score = 0;
    scorePosition = Vector2(60, screenHeight - 85);
    scoreTime = scoreTimeCounter = 0.01f;
    changingTime = 30;
    changingTimeCounter = 0;
    invincibleTime = invincibleTimeCounter = 1.0f;
    shieldTime = shieldTimeCounter = 5.0f;
    invincibleBlinkTime = invincibleBlinkTimeCounter = 0.05f;
    scoreMultiplier = scoreChanger = 10;
}

Player::~Player()
{
    delete sprite;
}

void Player::render()
{
    if(life > 0)
    {
        move();

        verifyChanges();

        gunControl();
    }

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
    speed = 300;
    invincibleTimeCounter = invincibleTime;
    invincibleBlinkTimeCounter = invincibleBlinkTime;
    shieldTimeCounter = shieldTime;
    score = 0;
    scoreTime = scoreTimeCounter = 0.1f;
    changingTimeCounter = 0;
    cameraSpeed = cameraSpeedChanger;
    scoreMultiplier = scoreChanger;
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

    if (life > 0)
    {
        if(scoreTimeCounter < scoreTime)
        {
            scoreTimeCounter += getDeltaTime();
        }
        else
        {
            scoreTimeCounter = 0;
            if(top)
                score += scoreMultiplier + scoreMultiplier / 2;
            else
                score += scoreMultiplier;
        }
    }

    for (int i = 0; i < life; i++)
    {
        hearth->render();
        hearth->moveX(hearth->getWidth() + 10);
    }

    hearth->moveX(-hearth->getWidth() * life - 10 * life);
}

bool Player::takeDamage(int x)
{
    if(invincibleTimeCounter < invincibleTime || shieldTimeCounter < shieldTime)
    {
        if(life > 0)
            center.x = x;
        return false;
    }

    life--;

    invincibleTimeCounter = 0;
    if(life <= 0)
        return true;
    else
    {
        center.x = x;
        return false;
    }
}

bool Player::takeDamage()
{
    if(invincibleTimeCounter < invincibleTime || shieldTimeCounter < shieldTime)
    {
        return false;
    }

    life--;

    invincibleTimeCounter = 0;

    if(life <= 0)
        return true;
    else
    {
        return false;
    }
}

void Player::renderSprite()
{
    if(life <= 0)
    {
        explosion->render();
        return;
    }

    if(shieldTimeCounter < shieldTime)
    {
        CV::color(rand() % 14);
        CV::circleFill(0, 0, hitBoxRadius + 10, 30);
        CV::color(0, 0, 0);
        CV::circleFill(0, 0, hitBoxRadius + 5, 30);
        shieldTimeCounter += getDeltaTime();
    }

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

void Player::verifyChanges()
{
    if(changingTimeCounter < changingTime)
    {
        changingTimeCounter += getDeltaTime();
    }
    else
    {
        changingTimeCounter = 0;
        cameraSpeed += cameraSpeedChanger;
        scoreMultiplier += scoreChanger;
    }
}

Gun* Player::getGun()
{
    return gun;
}

bool Player::isUp()
{
    return top;
}

int Player::getLevel()
{
    return (int) (getStopWatch() / changingTime);
}

void Player::addScore(int x)
{
    score += x;
}

int Player::getLife()
{
    return life;
}

int Player::getScore()
{
    return score;
}

void Player::addShield()
{
    shieldTimeCounter = 0;
}

void Player::addLife()
{
    life++;
}

void Player::addScoreMultiplier()
{
    scoreMultiplier += scoreChanger;
}

void Player::addSpeed(float multiplier)
{
    speed *= multiplier;
}
