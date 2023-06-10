#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../Lib/gl_canvas2d.h"
#include "../../Tools/Clock.h"
#include "../Animation.h"

class Projectile : public Clock
{
private:
    static Animation* explosionSprite;
    Vector2 position;
    int radius;
    float colorCircle[3];
    float colorBorder[3];
    int speed;
    float explosionTime, explosionTimeCounter;
    bool ended;

public:
    Projectile(int x, int y, int radius, int speed, float* colorCircle, float* colorBorder);

    virtual ~Projectile() { };

    static void loadExplosionSprite();

    void render();

    void move();
    void move(bool down);

    int getY();

    int getRadius();

    Vector2 getPosition();

    virtual void renderSprite();

    void explode();

    bool hasEnded();

    bool getEnded();

    Projectile* clone();

    void setPosition(int x, int y);

    void setRadius(int radius);

    void setSpeed(int speed);
};

#endif // PROJECTILE_H
