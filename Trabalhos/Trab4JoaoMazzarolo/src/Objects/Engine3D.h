#ifndef ENGINE_3D_H
#define ENGINE_3D_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Slider.h"
#include "Cylinder.h"

class Engine3D : public Clock
{
private:
    Slider *cameraSliderX, *cameraSliderY, *speedSlider;
    int screenWidth, screenHeight;
    Cylinder *eixo, *manivela1, *manivela2, *pistao1, *pistao2, *conection1, *conection2, *camisa1, *camisa2;
    float ang = PI / 2, angHorizontal = PI / 4, speed = 1;
    bool bielaVisible = true;

    void drawParallelLines(float x1, float y1, float x2, float y2, float radius, int numLines);

public:
    Engine3D(int screenWidth, int screenHeight);
    ~Engine3D();

    void render();

    void movePistao1();

    void movePistao2();

    void movePistoes();

    void onMouse(int button, int state, int wheel, int direction, int x, int y);

    void onKeyboard(int key);
};

#endif // ENGINE_3D_H