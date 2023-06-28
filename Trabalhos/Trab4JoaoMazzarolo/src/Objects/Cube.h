#ifndef CUBE_H
#define CUBE_H

#include "../Lib/gl_canvas2d.h"
#include "Point.h"

class Cube
{
private:
    float side, angle;
    Point center;
    Point *points[8];
    Point *transf[8];

public:
    Cube(Point center, float side);
    ~Cube();

    Point rotateX(Point p, float angle);

    Point rotateY(Point p, float angle);

    Point rotateZ(Point p, float angle);

    Point translate(Point p);

    Point project(Point p);

    void transform();

    void render();

};

#endif // CUBE_H