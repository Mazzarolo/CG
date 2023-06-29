#ifndef CYLINDER_H
#define CYLINDER_H

#include "../lib/gl_canvas2d.h"
#include "Point.h"

#define DIM 40

class Cylinder
{
private:
    Point mat[DIM + 1][DIM + 1];

    Point transf[DIM + 1][DIM + 1];

    float ang = 0;
public:
    Cylinder(int orientation, float radiusMultiplier, float heightMultiplier);

    void render();

    Point rotateX(Point p);

    Point rotateY(Point p);

    void translateCylinder(Point offset);

    Point translate(Point p);
    Point translate(Point p, Point offset);

    Point project(Point p);

    void transform();
};

#endif // CYlINDER_H