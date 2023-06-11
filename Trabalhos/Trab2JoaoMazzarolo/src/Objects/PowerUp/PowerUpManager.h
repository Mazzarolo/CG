#ifndef POWER_UP_MANAGER_H
#define POWER_UP_MANAGER_H

#include "PowerUpItem.h"
#include "PowerUpCard.h"
#include "../Background.h"
#include "../Player.h"
#include <vector>

class PowerUpManager : public Clock
{
private:
    PowerUpItem* powerUpItem;
    vector<PowerUpCard*> powerUpGunCards, powerUpBulletCards;
    vector<bool> activeBulletCards;
    Background* background;
    Player* player;
    int selectedCards[2];
    bool powerUpIsGun, selecting;
    int screenWidth, screenHeight, counter, limit, bulletCardsActive;
    float spawnTime, spawnTimeCounter;

public:
    PowerUpManager(int screenWidth, int screenHeight, Background* background, Player* player);

    void reset();

    void render(bool isUp);

    void spawn();

    void renderCards();

    bool getSelecting();

private:
    void createCards();
};

#endif // POWER_UP_MANAGER_H