#include "Engine3D.h"

Engine3D::Engine3D(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    eixo = new Cylinder(2, 0.5, 2);
    manivela1 = new Cylinder(1, 1, 1);
    manivela2 = new Cylinder(1, 1, 1);
    pistao1 = new Cylinder(1, 1, 0.5);
    pistao2 = new Cylinder(1, 1, 0.5);
    pistao1->rotateCylinderZ(PI / 4);
    pistao2->rotateCylinderZ(-PI / 4);
    eixo->translateCylinder(Point(0, 0, -1));
    manivela1->translateCylinder(Point(0, 0.5, 1));
    manivela2->translateCylinder(Point(0, 0.5, -1));
    pistao1->translateCylinder(Point(-4, 6, 1));
    pistao2->translateCylinder(Point(6, 8, -1));
    cameraSlider = new Slider(screenWidth / 2, screenHeight * 9 / 10, 100, 20, 10, 1, 0);
    cameraSlider->setZero();
}

void drawParallelLines(float x1, float y1, float x2, float y2, float radius, int numLines) {
    // Calcula a inclinação da linha original
    float slope = (y2 - y1) / (x2 - x1);

    // Calcula o ângulo entre as linhas paralelas
    float angleStep = 2 * PI / numLines;

    // Desenha as linhas paralelas em um padrão circular
    for (int i = 0; i < numLines; ++i) {
        // Calcula o ângulo para a linha atual
        float angle = i * angleStep;

        // Calcula as coordenadas para a linha paralela
        float dx = radius * cos(angle);
        float dy = radius * sin(angle);

        // Calcula as coordenadas finais para a linha paralela
        float x1_parallel = x1 + dx;
        float y1_parallel = y1 + dy;
        float x2_parallel = x2 + dx;
        float y2_parallel = y2 + dy;

        // Aqui você pode chamar a função de desenho (substitua com a função apropriada para o seu caso)
        CV::line(x1_parallel, y1_parallel, x2_parallel, y2_parallel);
    }
}

void Engine3D::onMouse(int button, int state, int wheel, int direction, int x, int y)
{
    cameraSlider->onMouse(x, y, button, state);
    eixo->setAngY(cameraSlider->percent() * 2 * PI);
    manivela1->setAngY(cameraSlider->percent() * 2 * PI);
    manivela2->setAngY(cameraSlider->percent() * 2 * PI);
    pistao1->setAngY(cameraSlider->percent() * 2 * PI);
    pistao2->setAngY(cameraSlider->percent() * 2 * PI);
    float inc = 0;
    if(wheel == 0 && direction == 1)
        inc = -100;
    else if(wheel == 0 && direction == -1)
        inc = 100;
    
    eixo->increaseDistance(inc);
    manivela1->increaseDistance(inc);
    manivela2->increaseDistance(inc);
    pistao1->increaseDistance(inc);
    pistao2->increaseDistance(inc);
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
    CV::color(0, 0, 0);
    CV::line(manivela1->getDownFaceCenter().x, manivela1->getDownFaceCenter().y, pistao1->getUpFaceCenter().x, pistao1->getUpFaceCenter().y);

    CV::line(manivela2->getDownFaceCenter().x, manivela2->getDownFaceCenter().y, pistao2->getUpFaceCenter().x, pistao2->getUpFaceCenter().y);
    CV::translate(0, 0);
    cameraSlider->render();
}

void Engine3D::movePistao1()
{
    Point pistao1Pos;

    pistao1Pos.x = -cos(ang) * getDeltaTime() * 5;
    pistao1Pos.y = cos(ang) * getDeltaTime() * 5;

    pistao1Pos.z = 0;

    pistao1->translateCylinder(pistao1Pos);
}

void Engine3D::movePistao2()
{
    Point pistao2Pos;

    pistao2Pos.x = -sin(ang) * getDeltaTime() * 5;
    pistao2Pos.y = -sin(ang) * getDeltaTime() * 5;

    pistao2Pos.z = 0;

    pistao2->translateCylinder(pistao2Pos);
}