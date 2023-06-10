#include "EnemiesManager.h"

EnemiesManager::EnemiesManager(int screenWidth, int screenHeight, Background* background, Player* player)
{
    this->background = background;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->player = player;
    spawnTime = 7;
    spawnTimeCounter = 0;

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[0]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy0.bmp");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[1]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy1.bmp");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[2]->load((char*) "Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy2.bmp");

    srand(time(NULL));
}

void EnemiesManager::render(int level, bool up)
{
    spawn(level);

    for(int i = 0; i < (int) enemies.size(); i++)
    {
        enemies[i]->render(up);
        if(enemies[i]->isDead())
        {
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
        }
    }
}

void EnemiesManager::spawn(int level)
{
    spawnTimeCounter += getDeltaTime();
    if(level > 6)
        level = 6;
    if(spawnTimeCounter >= spawnTime - level * 1.0f)
    {
        spawnTimeCounter = 0;
        int x = rand();
        int y = screenHeight + 100;
        //printf("Enemy spawned at (%d, %d)\n", x, y);
        float speed = 150;
        int enemyType = rand() % sprites.size();
        if (enemyType == 0)
        {
            speed = 75 + level * 10;
            x = screenWidth / 4 + x % (screenWidth / 2);
            enemies.push_back(new SeekerEnemy(screenWidth, screenHeight, x, y, speed, sprites[enemyType], player));
        }
        else if (enemyType == 1)
        {
            int num = level + 1;
            if(num > 4)
                num = 4;
            speed = 75 + level * 10;
            vector<Vector2> limits = background->getSpawnPoints();
            float distance = (limits[1].x - limits[0].x) / num;
            x = limits[0].x + x % (int)(distance);
            for(int i = 0; i < num; i++)
                enemies.push_back(new BlockerEnemy(screenWidth, screenHeight, x + i * distance, y, speed, sprites[enemyType], background, rand() % 2));
        }
        else if (enemyType == 2)
        {
            speed = 85 + level * 10;
            int distance = screenWidth / 7;
            int num = level + 1;
            
            x = x % (screenWidth - num * distance);

            for (int i = 0; i < num; i++)
                enemies.push_back(new SmallEnemy(screenWidth, screenHeight, x + i * distance, y, speed, i * distance,
                 screenWidth - (num - 1 - i) * distance, rand() % 2, sprites[enemyType]));
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
bool EnemiesManager::verifyCollision()
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

        if(enemies[i]->verifyCollision(player->getPosition(), player->getHitBoxRadius(), player->getGun()))
        {
            hit = true;
        }
    }

    return hit;
}
