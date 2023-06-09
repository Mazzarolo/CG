#include "PowerUpManager.h"

PowerUpManager::PowerUpManager(int screenWidth, int screenHeight, Background* background, Player* player)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->background = background;
    this->player = player;
    spawnTime = 10;
    spawnTimeCounter = 0;
    selecting = false;
    createCards();
}

void PowerUpManager::createCards()
{
    powerUpGunCards.push_back(new PowerUpCard(75, 50, "GUN", [this] {player->powerUpGun();}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, "BULLET", [this] {player->powerUpGun();}));
}

void PowerUpManager::render(bool isUp)
{
    if(selecting)
    {
        renderCards();
        return;
    }

    if(spawnTimeCounter >= spawnTime)
    {
        spawn();
        spawnTimeCounter = 0;
    }
    else
    {
        spawnTimeCounter += getDeltaTime();
    }

    if(powerUpItem != NULL)
    {
        powerUpItem->render(isUp, powerUpIsGun);

        if(powerUpItem->verifyCollision(player->getPosition(), player->getHitBoxRadius()))
        {
            delete powerUpItem;
            powerUpItem = NULL;
            selecting = true;
            powerUpGunCards[0]->setActive(true);
            powerUpGunCards[1]->setActive(true);
        }
        else if(powerUpItem->isDead())
        {
            delete powerUpItem;
            powerUpItem = NULL;
        }
    }
}

void PowerUpManager::spawn()
{
    powerUpIsGun = rand() % 2;
    int x = background->getSpawnPoints()[0].x + (background->getSpawnPoints()[1].x - background->getSpawnPoints()[0].x) / 2.0f;
    powerUpItem = new PowerUpItem(x, screenHeight + 10, 300, background, rand() % 2);
}

void PowerUpManager::renderCards()
{
    CV::clear(0.1, 0.1, 0.1);
    powerUpGunCards[0]->render();
    powerUpGunCards[1]->render();
    if(!powerUpGunCards[0]->getActive() || !powerUpGunCards[1]->getActive())
    {
        powerUpGunCards[0]->setActive(false);
        powerUpGunCards[1]->setActive(false);
        selecting = false;
    }
}

bool PowerUpManager::getSelecting()
{
    return selecting;
}

void PowerUpManager::reset()
{
    selecting = false;
    spawnTimeCounter = 0;
    if(powerUpItem != NULL)
    {
        delete powerUpItem;
        powerUpItem = NULL;
    }
    for(int i = 0; i < powerUpGunCards.size(); i++)
    {
        powerUpGunCards[i]->setActive(false);
    }
    for(int i = 0; i < powerUpBulletCards.size(); i++)
    {
        powerUpBulletCards[i]->setActive(false);
    }
}