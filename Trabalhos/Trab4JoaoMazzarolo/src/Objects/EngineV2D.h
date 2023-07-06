#ifndef ENGINEV_2D_H
#define ENGINEV_2D_H

#include "../Tools/Clock.h"
#include "../lib/gl_canvas2d.h"

class EngineV2D : public Clock
{
private:

    int screenWidth, screenHeight;
    float ang = 0;
    Vector2 manivelaPos, pistao1Pos, pistao2Pos;

    void rotateManivela(float angle);

    void movePistao1();

    void movePistao2();

public:
    EngineV2D(int screenWidth, int screenHeight);
    ~EngineV2D();

    void render();

};

#endif // ENGINEV_2D_H