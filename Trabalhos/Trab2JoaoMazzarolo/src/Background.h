#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gl_canvas2d.h"
#include "Bezier.h"

using namespace std;

class Background
{
private:
    Bezier* leftCurve;
    Bezier* rightCurve;
    int backColor[3], lineColor[3];
    int y;

public:
    Background(int screenWidth, int screenHeight);

    void render();

    void moveY(int y, int screenHeight);
};

#endif // BACKGROUND_H
