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
    counter = 0;
    limit = 5;
    createCards();
}

void PowerUpManager::createCards()
{
    powerUpGunCards.push_back(new PowerUpCard(75, 50, (char*) "Make your Weapon Bigger", [this] {player->getGun()->addProjectileRadius(3);}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, (char*) "More bullets per shoot", [this] {player->getGun()->addShoot();}));
    powerUpGunCards.push_back(new PowerUpCard(75, 50, (char*) "More bullets per second", [this] {player->getGun()->addShootRate(0.8);}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, (char*) "Add speed to your bullets", [this] {player->getGun()->addSpeed(1.5);}));
    powerUpGunCards.push_back(new PowerUpCard(75, 50, (char*) "Add damage to your gun", [this] {player->getGun()->addDamage(1);}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, (char*) "Get more health", [this] {player->addLife();}));
    powerUpGunCards.push_back(new PowerUpCard(75, 50, (char*) "5 Seconds Shield", [this] {player->addShield();}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, (char*) "Get 1000 points", [this] {player->addScore(1000);}));
    powerUpGunCards.push_back(new PowerUpCard(75, 50, (char*) "Get more points over time", [this] {player->addScoreMultiplier();}));
    powerUpGunCards.push_back(new PowerUpCard(425, 50, (char*) "Get more speed", [this] {player->addSpeed(1.2);}));

    powerUpBulletCards.push_back(new PowerUpCard(75, 50, (char*) "Your bullets can pierce foes", [this] {player->getGun()->setContinuous();}));
    powerUpBulletCards.push_back(new PowerUpCard(75, 50, (char*) "Your bullets change trajectory", [this] {player->getGun()->setCurved();}));
    powerUpBulletCards.push_back(new PowerUpCard(75, 50, (char*) "Your bullets return home", [this] {player->getGun()->setTopDown();}));
    powerUpBulletCards.push_back(new PowerUpCard(75, 50, (char*) "Your bullets slow foes", [this] {player->getGun()->setDecelerator();}));
    for (int i = 0; i < (int) powerUpBulletCards.size(); i++)
    {
        activeBulletCards.push_back(true);
    }

    bulletCardsActive = activeBulletCards.size();
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
            if(powerUpIsGun)
            {
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
            else
            {
                do
                {
                    selectedCards[0] = rand() % powerUpBulletCards.size();
                    selectedCards[1] = rand() % powerUpBulletCards.size();
                } while (selectedCards[0] == selectedCards[1] || !activeBulletCards[selectedCards[0]] || !activeBulletCards[selectedCards[1]]);
                powerUpBulletCards[selectedCards[0]]->setActive(true);
                powerUpBulletCards[selectedCards[0]]->setPosition(75);
                powerUpBulletCards[selectedCards[1]]->setActive(true);
                powerUpBulletCards[selectedCards[1]]->setPosition(425);
            }
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
    if(counter < limit || bulletCardsActive < 2)
    {
        powerUpIsGun = true;
        counter++;
    }
    else
    {
        powerUpIsGun = false;
        counter = 0;
    }
    int x = background->getSpawnPoints()[0].x + (background->getSpawnPoints()[1].x - background->getSpawnPoints()[0].x) / 2.0f;
    powerUpItem = new PowerUpItem(x, screenHeight + 10, 100, background, rand() % 2);
}

void PowerUpManager::renderCards()
{
    CV::clear(0.1, 0.1, 0.1);

    vector<PowerUpCard*> cards;

    if(powerUpIsGun)
    {
        cards = powerUpGunCards;
    }
    else
    {
        cards = powerUpBulletCards;
    }

    cards[selectedCards[0]]->render();
    CV::color(1, 1, 1);
    CV::textTitle(screenWidth / 2 - 10, screenHeight / 2, "OR");
    cards[selectedCards[1]]->render();
    if(!cards[selectedCards[0]]->getActive() || !cards[selectedCards[1]]->getActive())
    {
        if(!cards[selectedCards[0]]->getActive() && !powerUpIsGun)
        {
            cards[selectedCards[0]]->setActive(false);
            cards[selectedCards[1]]->setActive(false);
            activeBulletCards[selectedCards[0]] = false;
            bulletCardsActive--;
        }
        else if(!cards[selectedCards[1]]->getActive() && !powerUpIsGun)
        {
            cards[selectedCards[0]]->setActive(false);
            cards[selectedCards[1]]->setActive(false);
            activeBulletCards[selectedCards[1]] = false;
            bulletCardsActive--;
        }
        else
        {
            cards[selectedCards[0]]->setActive(false);
            cards[selectedCards[1]]->setActive(false);
        }
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
    counter = 0;
    if(powerUpItem != NULL)
    {
        delete powerUpItem;
        powerUpItem = NULL;
    }
    for(int i = 0; i < (int) powerUpGunCards.size(); i++)
    {
        powerUpGunCards[i]->setActive(false);
    }
    for(int i = 0; i < (int) powerUpBulletCards.size(); i++)
    {
        powerUpBulletCards[i]->setActive(false);
    }
    for(int i = 0; i < (int) activeBulletCards.size(); i++)
    {
        activeBulletCards[i] = true;
    }
    bulletCardsActive = activeBulletCards.size();
}
