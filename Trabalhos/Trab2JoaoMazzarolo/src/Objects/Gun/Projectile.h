#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../Lib/gl_canvas2d.h"
#include "../../Tools/Clock.h"

class Projectile : public Clock
{
private:
    Vector2 position;
    int radius;
    int colorCircle[3];
    int colorBorder[3];
    int speed;

public:
    Projectile(int x, int y, int radius, int speed, float* colorCircle, float* colorBorder);

    void render();

    void move();

    int getY();
};

#endif // PROJECTILE_H
