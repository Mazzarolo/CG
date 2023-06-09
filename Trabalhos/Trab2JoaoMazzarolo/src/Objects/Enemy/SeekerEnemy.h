#ifndef SEEKER_ENEMY_H
#define SEEKER_ENEMY_H

#include "Enemy.h"
#include "../Player.h"

class SeekerEnemy : public Enemy
{
private:
    Player* player;

public:
    SeekerEnemy(int screenWidth, int screenHeight, int x, int y, float speed, Animation* sprite, Player* player);

    virtual ~SeekerEnemy() { };

    void move(bool accelerating);
};

#endif // SEEKER_ENEMY_H