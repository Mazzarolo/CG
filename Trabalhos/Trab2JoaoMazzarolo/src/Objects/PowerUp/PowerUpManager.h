// Classe que representa o gerenciador de power ups

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
    // Construtor
    PowerUpManager(int screenWidth, int screenHeight, Background* background, Player* player);

    // Reseta o gerenciador
    void reset();

    // Renderiza o gerenciador e controla ele (chamado no loop principal)
    void render(bool isUp);

    // Spawn de um novo item de power up
    void spawn();

    // Renderiza as cartas de power up quando for necessário
    void renderCards();

    // Verifica se está na etapa de seleção de power ups
    bool getSelecting();

private:
    // Cria as cartas de power up
    void createCards();
};

#endif // POWER_UP_MANAGER_H