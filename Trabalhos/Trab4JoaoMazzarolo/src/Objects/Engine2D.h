#ifndef ENGINE_2D_H
#define ENGINE_2D_H

#include "../Tools/Clock.h"
#include "Component2D.h"

class Engine2D : public Clock
{
private:
    Component2D *pistao;
    Component2D *manivela;
    Component2D *biela;

public:
    Engine2D(int screenWidth, int screenHeight);
    ~Engine2D();

    void render();
};

# endif // ENGINE_2D_H