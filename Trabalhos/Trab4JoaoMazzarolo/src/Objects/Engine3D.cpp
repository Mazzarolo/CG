#include "Engine3D.h"

Engine3D::Engine3D(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    eixo = new Cylinder(2, 0.5, 3);
    manivela1 = new Cylinder(1, 1, 1);
    manivela2 = new Cylinder(1, 1, 1);
    pistao1 = new Cylinder(1, 1, 0.5);
    pistao2 = new Cylinder(1, 1, 0.5);
    pistao1->rotateCylinderZ(PI / 4);
    pistao2->rotateCylinderZ(-PI / 4);
    eixo->translateCylinder(Point(0, 0, -2));
    manivela1->translateCylinder(Point(0, 0.5, 2));
    manivela2->translateCylinder(Point(0, 0.5, -2));
    pistao1->translateCylinder(Point(-3, 5, 2));
    pistao2->translateCylinder(Point(5, 7, -2));
}

void Engine3D::render()
{
    ang = manivela1->getAngZ();
    CV::color(0, 0, 0);
    CV::translate(screenWidth / 2, screenHeight / 4);
    eixo->render();
    eixo->rotateCylinderZ();
    manivela1->render();
    manivela1->rotateCylinderZ();
    manivela2->render();
    manivela2->rotateCylinderZ();
    pistao1->render();
    movePistao1();
    pistao2->render();
    movePistao2();
}

void Engine3D::movePistao1()
{
    Point pistao1Pos;

    pistao1Pos.x = -cos(ang) * getDeltaTime();
    pistao1Pos.y = cos(ang) * getDeltaTime();

    pistao1Pos.z = 0;

    pistao1->translateCylinder(pistao1Pos);
}

void Engine3D::movePistao2()
{
    Point pistao2Pos;

    pistao2Pos.x = -sin(ang) * getDeltaTime();
    pistao2Pos.y = -sin(ang) * getDeltaTime();

    pistao2Pos.z = 0;

    pistao2->translateCylinder(pistao2Pos);
}