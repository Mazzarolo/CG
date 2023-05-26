#ifndef BLOCKER_ENEMY_H
#define BLOCKER_ENEMY_H

#include "Enemy.h"

class BlockerEnemy : public Enemy
{
public:
    BlockerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite);

    virtual ~BlockerEnemy() { };

    void move(bool down);
};

#endif // BLOCKER_ENEMY_H