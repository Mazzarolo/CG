#ifndef CYLINDER_H
#define CYLINDER_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Point.h"

#define DIM 40

class Cylinder : public Clock
{
private:
    Point mat[DIM + 1][DIM + 1];

    Point transf[DIM + 1][DIM + 1];

    float ang = 0, angY = 0, angZ = 0, distance = -300;
public:
    Cylinder(int orientation, float radiusMultiplier, float heightMultiplier);

    void render();

    Point rotateX(Point p);
    Point rotateX(Point p, float angle);

    Point rotateY(Point p);
    Point rotateY(Point p, float angle);

    Point rotateZ(Point p);
    Point rotateZ(Point p, float angle);

    void rotateCylinderX(float angle);

    void rotateCylinderY(float angle);
    void rotateCylinderY();

    void rotateCylinderZ(float angle);
    void rotateCylinderZ();

    float getAngZ();

    void setAngY(float angY);
    float getAngY();

    void translateCylinder(Point offset);

    Point translate(Point p);
    Point translate(Point p, Point offset);

    Point getUpFaceCenter();

    Point getDownFaceCenter();

    Point project(Point p);
    void project();

    void increaseDistance(float inc);

    void transform();
};

#endif // CYlINDER_H