#ifndef SMALL_ENEMY_H
#define SMALL_ENEMY_H

#include "Enemy.h"

class SmallEnemy : public Enemy
{
private:
    int minX, maxX;
    bool right;

public:
    SmallEnemy(int screenWidth, int screenHeight, int x, int y, float speed, int minX, int maxX, bool right, Animation* sprite, int life);

    virtual ~SmallEnemy() { };

    void move(bool accelerating);
};

#endif // SMALL_ENEMY_H