#include "EnemiesManager.h"

EnemiesManager::EnemiesManager(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    spawnTime = 3;
    spawnTimeCounter = 0;

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[0]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy0.bmp");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[1]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy1.bmp");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[2]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy2.bmp");

    srand(time(NULL));
}

void EnemiesManager::render()
{
    spawn();

    for(int i = 0; i < (int) enemies.size(); i++)
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
        //printf("Enemy spawned at (%d, %d)\n", x, y);
        float speed = 150;
        int enemyType = rand() % sprites.size();
        if (enemyType == 0)
        {
            enemies.push_back(new SeekerEnemy(screenWidth, screenHeight, x, y, speed, sprites[enemyType]));
        }
        else if (enemyType == 1)
        {
            enemies.push_back(new BlockerEnemy(screenWidth, screenHeight, x, y, speed, sprites[enemyType]));
        }
        else if (enemyType == 2)
        {
            enemies.push_back(new SmallEnemy(screenWidth, screenHeight, x, y, speed, sprites[enemyType]));
        }
    }
}

void EnemiesManager::reset()
{
    for(int i = 0; i < (int) enemies.size(); i++)
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
    for(int i = 0; i < (int) enemies.size(); i++)
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