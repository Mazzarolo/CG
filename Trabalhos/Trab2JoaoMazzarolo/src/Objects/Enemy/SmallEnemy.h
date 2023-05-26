#ifndef SMALL_ENEMY_H
#define SMALL_ENEMY_H

#include "Enemy.h"

class SmallEnemy : public Enemy
{
public:
    SmallEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite);

    virtual ~SmallEnemy() { };

    void move(bool down);
};

#endif // SMALL_ENEMY_H