#ifndef ENEMIESMANAGER_H
#define ENEMIESMANAGER_H

#include <vector>
#include "BlockerEnemy.h"
#include "SmallEnemy.h"
#include "SeekerEnemy.h"
#include "../../Tools/Clock.h"
#include "../../Lib/gl_canvas2d.h"

class EnemiesManager : public Clock
{
private:
    vector<Enemy*> enemies;
    vector<Animation*> sprites;
    Animation* explosion;
    int screenWidth, screenHeight;
    float spawnTime, spawnTimeCounter;

public:
    EnemiesManager(int screenWidth, int screenHeight);

    void reset();

    void render(int level, bool up);

    void spawn(int level);

    bool verifyCollision(Vector2 playerPosition, int playerRadius, Gun* playerGun);
};

#endif // ENEMIESMANAGER_H