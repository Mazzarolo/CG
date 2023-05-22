#ifndef STAR_H
#define STAR_H

#include "../Lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "player.h"

class Star : public Clock
{
private:
    Vector2 position;
    int radius, speed;

public:
    Star(int x, int y, int radius);

    void render();

    void setPosition(int x, int y);

    void naturalMove(int screenHeight);
};


#endif // STAR_H
