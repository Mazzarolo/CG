#ifndef BLOCKER_ENEMY_H
#define BLOCKER_ENEMY_H

#include "Enemy.h"
#include "../Background.h"

class BlockerEnemy : public Enemy
{
private:
    Background* background;
    bool right;

public:
    BlockerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Background* background, bool right);

    virtual ~BlockerEnemy() { };

    void move(bool accelerating);
};

#endif // BLOCKER_ENEMY_H