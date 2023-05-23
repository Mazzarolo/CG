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
    Gun* gun;
    Vector2 position;
    int hitBoxRadius;
    int color[3];
    float speed;
    bool dead;

public:
    Enemy(int screenWidth, int screenHeight, int x, int y, int hitBoxRadius, float speed, int color[3], Animation* sprite);

    ~Enemy();

    void render();

    void move();

    bool isDead();
};

#endif // ENEMY_H