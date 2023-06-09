#include "PowerUpItem.h"

Animation* PowerUpItem::sprites[2] = {NULL, NULL};

PowerUpItem::PowerUpItem(int x, int y, float speed, Background* background, bool right)
{
    this->position = Vector2(x, y);
    this->speed = speed;
    this->radius = 16;
    this->right = right;
    this->background = background;
    if(sprites[0] == NULL)
    {
        sprites[0] = new Animation(2, 1, 2, 0.5f);
        sprites[0]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\PowerUps\\PowerUp0.bmp");
        sprites[1] = new Animation(2, 1, 2, 0.5f);
        sprites[1]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\PowerUps\\PowerUp1.bmp");
    }
}

void PowerUpItem::render(bool isUp, bool isGun)
{
    move(isUp);
    if(isGun)
    {
        sprites[0]->setPosition(position.x - sprites[0]->getWidth() / 2, position.y - sprites[0]->getHeight() / 2);
        sprites[0]->render();
    }
    else
    {
        sprites[1]->setPosition(position.x - sprites[1]->getWidth() / 2, position.y - sprites[1]->getHeight() / 2);
        sprites[1]->render();
    }
}

void PowerUpItem::move(bool isUp)
{
    if(isUp)
        position.y -= 2 * speed * getDeltaTime();
    else
        position.y -= speed * getDeltaTime();

    if(background->checkCollision(position, radius, right))
    {
        right = !right;
    }

    if(right)
        position.x += speed * 2 *getDeltaTime();
    else
        position.x -= speed * 2 * getDeltaTime();

}

bool PowerUpItem::verifyCollision(Vector2 playerPosition, int playerRadius)
{
    if(Collisions::circleCircle(position, radius, playerPosition, playerRadius))
    {
        return true;
    }
    return false;
}

bool PowerUpItem::isDead()
{
    if(position.y < -100)
        return true;
    return false;
}

void PowerUpItem::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}