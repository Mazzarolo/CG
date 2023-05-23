#ifndef ENEMIESMANAGER_H
#define ENEMIESMANAGER_H

#include <vector>
#include "Enemy.h"
#include "../../Lib/gl_canvas2d.h"

class EnemiesManager
{
private:
    vector<Enemy*> enemies;
    vector<Animation*> sprites;
    int screenWidth, screenHeight;
    int spawnTime, spawnTimeCounter;

private:
    EnemiesManager(int screenWidth, int screenHeight);

    void render();
};

#endif // ENEMIESMANAGER_H