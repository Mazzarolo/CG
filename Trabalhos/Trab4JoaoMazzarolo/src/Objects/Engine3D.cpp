#include "Engine3D.h"

Engine3D::Engine3D(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    eixo = new Cylinder(2, 0.5, 2);
    conection1 = new Cylinder(1, 0.5, 0.5);
    conection2 = new Cylinder(1, 0.5, 0.5);
    manivela1 = new Cylinder(1, 1, 2);
    manivela1->changeShapeToCircularCone(1, 1);
    manivela1->rotateCylinderZ(-PI / 2);
    manivela2 = new Cylinder(1, 1, 2);
    manivela2->changeShapeToCircularCone(1, 1);
    manivela2->rotateCylinderZ(-PI / 2);
    pistao1 = new Cylinder(1, 1, 0.5);
    pistao2 = new Cylinder(1, 1, 0.5);
    pistao1->rotateCylinderZ(angHorizontal);
    pistao2->rotateCylinderZ(-angHorizontal);
    camisa1 = new Cylinder(1, 1, 1.5);
    camisa2 = new Cylinder(1, 1, 1.5);
    camisa1->rotateCylinderZ(angHorizontal);
    camisa2->rotateCylinderZ(-angHorizontal);
    eixo->translateCylinder(Point(0, 1, -1));
    conection1->translateCylinder(Point(0, 1.5, 0.5));
    conection2->translateCylinder(Point(0, 1.5, -0.5));
    manivela1->translateCylinder(Point(0, 1, 2));
    manivela2->translateCylinder(Point(0, 1, -2));
    pistao1->translateCylinder(Point(-6, 8, 0.5));
    pistao2->translateCylinder(Point(6, 8, -0.5));
    camisa1->translateCylinder(Point(-4.8, 6.8, 0.5));
    camisa2->translateCylinder(Point(4.8, 6.8, -0.5));
    cameraSliderX = new Slider(screenWidth / 10, screenHeight * 9 / 10, 100, 20, 10, 1, 0);
    cameraSliderX->setZero();
    cameraSliderY = new Slider(screenWidth * 4 / 10, screenHeight * 9 / 10, 100, 20, 10, 1, 0);
    cameraSliderY->setZero();
    speedSlider = new Slider(screenWidth * 7 / 10, screenHeight * 9 / 10, 100, 20, 10, 1, 0);
    speedSlider->setZero();
}

void Engine3D::drawParallelLines(float x1, float y1, float x2, float y2, float radius, int numLines) {
    float angleStep = 2 * PI / numLines;

    for (int i = 0; i < numLines; ++i) {
        float angle = i * angleStep;

        float dx = radius * cos(angle);
        float dy = radius * sin(angle);

        float x1_parallel = x1 + dx;
        float y1_parallel = y1 + dy;
        float x2_parallel = x2 + dx;
        float y2_parallel = y2 + dy;

        CV::line(x1_parallel, y1_parallel, x2_parallel, y2_parallel);
    }
}

void Engine3D::onMouse(int button, int state, int wheel, int direction, int x, int y)
{
    cameraSliderY->onMouse(x, y, button, state);
    eixo->setAngY(cameraSliderY->percent() * PI * 2);
    conection1->setAngY(cameraSliderY->percent() * PI * 2);
    conection2->setAngY(cameraSliderY->percent() * PI * 2);
    manivela1->setAngY(cameraSliderY->percent() * PI * 2);
    manivela2->setAngY(cameraSliderY->percent() * PI * 2);
    pistao1->setAngY(cameraSliderY->percent() * PI * 2);
    pistao2->setAngY(cameraSliderY->percent() * PI * 2);
    camisa1->setAngY(cameraSliderY->percent() * PI * 2);
    camisa2->setAngY(cameraSliderY->percent() * PI * 2);

    cameraSliderX->onMouse(x, y, button, state);
    eixo->setAngX(cameraSliderX->percent() * PI * 2);
    conection1->setAngX(cameraSliderX->percent() * PI * 2);
    conection2->setAngX(cameraSliderX->percent() * PI * 2);
    manivela1->setAngX(cameraSliderX->percent() * PI * 2);
    manivela2->setAngX(cameraSliderX->percent() * PI * 2);
    pistao1->setAngX(cameraSliderX->percent() * PI * 2);
    pistao2->setAngX(cameraSliderX->percent() * PI * 2);
    camisa1->setAngX(cameraSliderX->percent() * PI * 2);
    camisa2->setAngX(cameraSliderX->percent() * PI * 2);

    float inc = 0;
    if(wheel == 0 && direction == 1)
        inc = -5000 * getDeltaTime();
    else if(wheel == 0 && direction == -1)
        inc = 5000 * getDeltaTime();

    eixo->increaseDistance(inc);
    manivela1->increaseDistance(inc);
    manivela2->increaseDistance(inc);
    pistao1->increaseDistance(inc);
    pistao2->increaseDistance(inc);
    conection1->increaseDistance(inc);
    conection2->increaseDistance(inc);
    camisa1->increaseDistance(inc);
    camisa2->increaseDistance(inc);

    speedSlider->onMouse(x, y, button, state);
    speed = 1 + speedSlider->percent() * 10;
    eixo->setSpeed(speed);
    manivela1->setSpeed(speed);
    manivela2->setSpeed(speed);
    pistao1->setSpeed(speed);
    pistao2->setSpeed(speed);
    conection1->setSpeed(speed);
    conection2->setSpeed(speed);
    camisa1->setSpeed(speed);
    camisa2->setSpeed(speed);
}

void Engine3D::render()
{
    ang = manivela1->getAngZ();
    CV::color(0, 0, 0);
    CV::translate(screenWidth / 2, screenHeight / 4);
    eixo->render();
    eixo->rotateCylinderZ();
    conection1->render();
    conection1->rotateCylinderZ();
    conection2->render();
    conection2->rotateCylinderZ();
    manivela1->render();
    manivela1->rotateCylinderZ();
    manivela2->render();
    manivela2->rotateCylinderZ();
    pistao1->render();
    movePistao1();
    pistao2->render();
    movePistao2();
    camisa1->render();
    camisa2->render();
    if(bielaVisible)
    {
        CV::color(0, 0, 0);
        CV::line(conection1->getUpFaceCenter().x, conection1->getUpFaceCenter().y, pistao1->getUpFaceCenter().x, pistao1->getUpFaceCenter().y);
        drawParallelLines(conection1->getUpFaceCenter().x, conection1->getUpFaceCenter().y, pistao1->getUpFaceCenter().x, pistao1->getUpFaceCenter().y, 5, 10);
        CV::line(conection2->getUpFaceCenter().x, conection2->getUpFaceCenter().y, pistao2->getUpFaceCenter().x, pistao2->getUpFaceCenter().y);
        drawParallelLines(conection2->getUpFaceCenter().x, conection2->getUpFaceCenter().y, pistao2->getUpFaceCenter().x, pistao2->getUpFaceCenter().y, 5, 10);
    }
    CV::translate(0, 0);
    CV::color(0, 0, 0);
    CV::text(screenWidth / 10, screenHeight - 20, "Angulo X");
    cameraSliderX->render();
    CV::text(screenWidth * 4 / 10, screenHeight - 20, "Angulo Y");
    cameraSliderY->render();
    CV::text(screenWidth * 7 / 10, screenHeight - 20, "RPM");
    speedSlider->render();
    CV::text(20, 10, "PRECIONE ESPACO PARA VER A MODELAGEM EM 2D");
    CV::text(20, 30, "RODE O SCROLL DO MOUSE PARA DAR ZOOM IN E OUT");
    CV::text(20, 70, "PRECIONE AS TECLAS DE 1 A 5 ");
    CV::text(20, 50, "PARA ESCONDER / REVELAR OS COMPONENTES");
}

void Engine3D::movePistao1()
{
    Point pistao1Pos;

    pistao1Pos.x = ((cos(PI - ang) + sin(PI - ang)) / 2) * getDeltaTime() * speed;
    pistao1Pos.y = -((cos(PI - ang) + sin(PI - ang)) / 2) * getDeltaTime() * speed;

    pistao1Pos.z = 0;

    if(ang > -getDeltaTime() * speed && ang < getDeltaTime() * speed)
    {
        pistao1->resetPosition(1, 1, 0.5);
        pistao1->rotateCylinderZ(angHorizontal);
        pistao1->translateCylinder(Point(-6, 8, 0.5));
    }

    pistao1->translateCylinder(pistao1Pos);
}

void Engine3D::movePistao2()
{
    Point pistao2Pos;

    pistao2Pos.x = -((sin(ang) + cos(ang)) / 2) * getDeltaTime() * speed;
    pistao2Pos.y = -((sin(ang) + cos(ang)) / 2) * getDeltaTime() * speed;

    pistao2Pos.z = 0;

    if(ang > -getDeltaTime() * speed && ang < getDeltaTime() * speed)
    {
        pistao2->resetPosition(1, 1, 0.5);
        pistao2->rotateCylinderZ(-angHorizontal);
        pistao2->translateCylinder(Point(6, 8, -0.5));
    }

    pistao2->translateCylinder(pistao2Pos);
}

void Engine3D::onKeyboard(int key)
{
    if(key == 49)
    {
        camisa1->setVisible();
        camisa2->setVisible();
    }
    else if(key == 50)
    {
        eixo->setVisible();
        conection1->setVisible();
        conection2->setVisible();
    }
    else if(key == 51)
    {
        pistao1->setVisible();
        pistao2->setVisible();
    }
    else if(key == 52)
    {
        manivela1->setVisible();
        manivela2->setVisible();
    }
    else if(key == 53)
    {
        bielaVisible = !bielaVisible;
    }
}
