#include "EnemiesManager.h"

EnemiesManager::EnemiesManager(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    spawnTime = 5;
    spawnTimeCounter = 0;

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[0]->load("Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy0");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[1]->load("Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy1");

    sprites.push_back(new Animation(2, 1, 2, 0.3f));
    sprites[2]->load("Trab2JoaoMazzarolo\\src\\Images\\Enemies\\Enemy2");
}