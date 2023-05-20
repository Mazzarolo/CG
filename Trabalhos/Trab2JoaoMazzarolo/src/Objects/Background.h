#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "../Lib/gl_canvas2d.h"
#include "Bezier.h"

using namespace std;

class Background
{
private:
    Bezier* leftCurve;
    Bezier* rightCurve;
    int backColor[3], lineColor[3];
    int renderY, height, offsetY;

public:
    Background(int screenWidth, int screenHeight, int offsetY);

    bool checkCollision(Vector2 point);

    void render();

    void moveY(int renderY);
};

#endif // BACKGROUND_H
