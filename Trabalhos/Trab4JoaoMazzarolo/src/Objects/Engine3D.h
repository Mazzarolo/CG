#ifndef ENGINE_3D_H
#define ENGINE_3D_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Cylinder.h"

class Engine3D : public Clock
{
private:
    int screenWidth, screenHeight;
    Cylinder *manivela, *pistao1, *pistao2;
    float ang = 0;

public:
    Engine3D(int screenWidth, int screenHeight);
    ~Engine3D();

    void render();

    void movePistao1();

    void movePistao2();

};

#endif // ENGINE_3D_H