#ifndef ENGINE_3D_H
#define ENGINE_3D_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Cylinder.h"

class Engine3D : public Clock
{
private:
    int screenWidth, screenHeight;
    Cylinder *eixo, *manivela1, *manivela2, *pistao1, *pistao2;
    float ang = 0;

public:
    Engine3D(int screenWidth, int screenHeight);
    ~Engine3D();

    void render();

    void movePistao1();

    void movePistao2();

    void moveEixo();
};

#endif // ENGINE_3D_H