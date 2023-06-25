#ifndef CUBE_H
#define CUBE_H

#include "../Lib/gl_canvas2d.h"

class Point
{
public:
    float x;
    float y;
    float z;

    Point() { x = 0; y = 0; z = 0; }
    Point(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
};

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

    Point translate(Point p);

    Point project(Point p);

    void transform();

    void render();

};

#endif // CUBE_H