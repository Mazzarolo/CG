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
    powerUpGunCards.push_back(new PowerUpCard(75, 50, "Make your Weapon Bigger", [this] {player->getGun()->addProjectileRadius(1);}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, "More bullets per shoot", [this] {player->getGun()->addShoot();}));
    powerUpGunCards.push_back(new PowerUpCard(75, 50, "More bullets per second", [this] {player->getGun()->addShootRate(0.8);}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, "Add speed to your gun", [this] {player->getGun()->addSpeed(1.2);}));
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

        if(powerUpItem->verifyCollision(player->getPosition(), player->getHitBoxRadius()) && player->getLife() > 0)
        {
            delete powerUpItem;
            powerUpItem = NULL;
            selecting = true;
            selectedCards[0] = rand() % powerUpGunCards.size();
            do
            {
                selectedCards[1] = rand() % powerUpGunCards.size();
            } while (selectedCards[0] == selectedCards[1]);
            powerUpGunCards[selectedCards[0]]->setActive(true);
            powerUpGunCards[selectedCards[0]]->setPosition(75);
            powerUpGunCards[selectedCards[1]]->setActive(true);
            powerUpGunCards[selectedCards[1]]->setPosition(425);
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
    powerUpItem = new PowerUpItem(x, screenHeight + 10, 150, background, rand() % 2);
}

void PowerUpManager::renderCards()
{
    CV::clear(0.1, 0.1, 0.1);
    powerUpGunCards[selectedCards[0]]->render();
    CV::color(1, 1, 1);
    CV::textTitle(screenWidth / 2 - 10, screenHeight / 2, "OR");
    powerUpGunCards[selectedCards[1]]->render();
    if(!powerUpGunCards[selectedCards[0]]->getActive() || !powerUpGunCards[selectedCards[1]]->getActive())
    {
        powerUpGunCards[selectedCards[0]]->setActive(false);
        powerUpGunCards[selectedCards[1]]->setActive(false);
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