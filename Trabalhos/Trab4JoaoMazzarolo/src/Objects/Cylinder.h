#ifndef CYLINDER_H
#define CYLINDER_H

#include "../lib/gl_canvas2d.h"
#include "../Tools/Clock.h"
#include "Point.h"

#define DIM 30

class Cylinder : public Clock
{
private:
    Point mat[DIM + 1][DIM + 1];

    Point transf[DIM + 1][DIM + 1];

    float ang = 0, angY = 0, angZ = 0, distance = -300, speed = 1;

    bool visible = true;
public:
    Cylinder(int orientation, float radiusMultiplier, float heightMultiplier);

    void changeShapeToCone(float radiusMultiplier, float heightMultiplier);

    void changeShapeToCircularCone(float radiusMultiplier, float heightMultiplier);

    void changeShapeToSphere(float radiusMultiplier);

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

    void resetPosition(int orientation, float radiusMultiplier, float heightMultiplier);

    Point getUpFaceCenter();

    Point getDownFaceCenter();

    Point getCenter();

    void setSpeed(float speed);

    Point project(Point p);
    void project();

    void increaseDistance(float inc);

    void transform();

    void setVisible();
};

#endif // CYlINDER_H