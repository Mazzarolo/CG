#include "EnemiesManager.h"

EnemiesManager::EnemiesManager(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    spawnTime = 3;
    spawnTimeCounter = 0;

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[0]->load("Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy0.bmp");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[1]->load("Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy1.bmp");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[2]->load("Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy2.bmp");
}

void EnemiesManager::render()
{
    spawn();

    for(int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->render();
        if(enemies[i]->isDead())
        {
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
        }
    }
}

void EnemiesManager::spawn()
{
    spawnTimeCounter += getDeltaTime();
    if(spawnTimeCounter >= spawnTime)
    {
        spawnTimeCounter = 0;
        int x = screenWidth / 4 + rand() % (screenWidth / 2);
        int y = screenHeight + 100;
        int hitBoxRadius = 20;
        float speed = 200;
        int color[3] = {1, 0, 0};
        int spriteIndex = rand() % sprites.size();
        enemies.push_back(new Enemy(screenWidth, screenHeight, x, y, hitBoxRadius, speed, color, sprites[spriteIndex]));
    }
}

void EnemiesManager::reset()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        delete enemies[i];
    }
    enemies.clear();
    spawnTimeCounter = 0;
}

// verifica as colisoes de todas as fontes, e retorna true se o jogador for atingido
bool EnemiesManager::verifyCollision(Vector2 playerPosition, int playerRadius, Gun* playerGun)
{
    bool hit = false;
    for(int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i]->isDead())
        {
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
            continue;
        }

        if(enemies[i]->verifyCollision(playerPosition, playerRadius, playerGun))
        {
            hit = true;
        }
    }

    return hit;
}