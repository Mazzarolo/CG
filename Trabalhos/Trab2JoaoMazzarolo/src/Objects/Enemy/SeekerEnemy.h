#ifndef SEEKER_ENEMY_H
#define SEEKER_ENEMY_H

#include "Enemy.h"

class SeekerEnemy : public Enemy
{
public:
    SeekerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite);

    virtual ~SeekerEnemy() { };

    void move(bool accelerating);
};

#endif // SEEKER_ENEMY_H