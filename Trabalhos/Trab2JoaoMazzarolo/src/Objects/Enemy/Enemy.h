#ifndef ENEMY_H
#define ENEMY_H

#include "../Animation.h"
#include "../Gun/Gun.h"
#include "../../Tools/Clock.h"
#include "../../Lib/gl_canvas2d.h"

class Enemy : public Clock
{
protected:
    static int count;
    Animation* sprite;
    static Animation* explosion;
    Gun* gun;
    Vector2 position;
    int life, id;
    int hitBoxRadius;
    float speed;
    float explosionTime, explosionTimeCounter;
    bool dead;

protected:
    Enemy(int screenWidth, int screenHeight, int x, int y, float speed, int life);

public:
    virtual ~Enemy();

    void render(bool accelerating);

    virtual void move(bool accelerating);

    bool isDead();

    bool verifyCollision(Vector2 PlayerPosition, int playerRadius, Gun* playerGun);

    int getId();

private:
    void renderSprite();

};

#endif // ENEMY_H
