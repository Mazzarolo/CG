#ifndef ENEMY_H
#define ENEMY_H

#include "../Animation.h"
#include "../Gun/Gun.h"
#include "../../Tools/Clock.h"
#include "../../Lib/gl_canvas2d.h"

class Enemy : public Clock
{
protected:
    Animation* sprite;
    static Animation* explosion;
    Gun* gun;
    Vector2 position;
    int life;
    int hitBoxRadius;
    float speed;
    float explosionTime, explosionTimeCounter;
    bool dead;

protected:
    Enemy(int screenWidth, int screenHeight, int x, int y, float speed);

public:
    virtual ~Enemy();

    void render(bool down);

    virtual void move(bool down);

    bool isDead();

    bool verifyCollision(Vector2 PlayerPosition, int playerRadius, Gun* playerGun);

private:
    void renderSprite();

};

#endif // ENEMY_H