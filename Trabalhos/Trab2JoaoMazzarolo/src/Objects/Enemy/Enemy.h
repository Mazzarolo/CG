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
    Animation* explosion;
    Gun* gun;
    Vector2 position;
    int life;
    int hitBoxRadius;
    int color[3];
    float speed;
    float explosionTime, explosionTimeCounter;
    bool dead;

public:
    Enemy(int screenWidth, int screenHeight, int x, int y, int hitBoxRadius, float speed, int color[3], Animation* sprite, Animation* explosion);

    ~Enemy();

    void render();

    void move();

    bool isDead();

    bool verifyCollision(Vector2 PlayerPosition, int playerRadius, Gun* playerGun);

private:
    void renderSprite();

};

#endif // ENEMY_H