#ifndef ENGINEV_2D_H
#define ENGINEV_2D_H

#include "../Tools/Clock.h"
#include "../Objects/Slider.h"
#include "../lib/gl_canvas2d.h"

class EngineV2D : public Clock
{
private:
    Slider *speedSlider, *angSlider;
    int screenWidth, screenHeight;
    float ang = 0, angHorizontal = PI / 4, rpm = 1;
    Vector2 manivelaPos, pistao1Pos, pistao2Pos;

    void rotateManivela(float angle);

    void movePistoes();

public:
    EngineV2D(int screenWidth, int screenHeight);
    ~EngineV2D();

    void render();

    void onMouse(int button, int state, int wheel, int direction, int x, int y);

};

#endif // ENGINEV_2D_H