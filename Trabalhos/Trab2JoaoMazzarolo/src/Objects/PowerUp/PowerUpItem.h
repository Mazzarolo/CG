#ifndef POWER_UP_ITEM_H
#define POWER_UP_ITEM_H

#include "../../Tools/Collisions.h"
#include "../../Lib/gl_canvas2d.h"
#include "../../Tools/Clock.h"
#include "../Animation.h"
#include "../Background.h"

class PowerUpItem : public Clock
{
private:
    static Animation* sprites[2];
    Background* background;    
    Vector2 position;
    float speed;
    int radius;
    bool right;

public:
    PowerUpItem(int x, int y, float speed, Background* background, bool right);

    void render(bool isUp, bool isGun);

    void move(bool isUp);

    bool verifyCollision(Vector2 playerPosition, int playerRadius);

    bool isDead();

    void setPosition(int x, int y);
};

#endif // POWER_UP_ITEM_H