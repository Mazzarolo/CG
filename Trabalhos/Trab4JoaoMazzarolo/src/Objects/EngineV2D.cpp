#include "EngineV2D.h"

void EngineV2D::rotateManivela(float angle)
{
    manivelaPos.x = screenWidth / 2 + 30 * cos(angle);
    manivelaPos.y = screenHeight / 2 + 30 * sin(angle);
}

void EngineV2D::movePistao1()
{
    pistao1Pos.x = 30 * -sin(ang);
    pistao1Pos.y = 30 * sin(ang);

    pistao1Pos.x += screenWidth * 1 / 4;
    pistao1Pos.y += screenHeight * 3 / 4;
}

void EngineV2D::movePistao2()
{
    pistao2Pos.x = 30 * cos(ang);
    pistao2Pos.y = 30 * cos(ang);

    pistao2Pos.x += screenWidth * 3 / 4;
    pistao2Pos.y += screenHeight * 3 / 4;
}

void EngineV2D::movePistoes()
{
    float manivelaRadius = 30;
    float bielaLenght = 50;

    Vector2 p1 = Vector2(screenWidth / 2, screenHeight / 2);
    Vector2 p2 = manivelaPos;

    float angRel1 = angHorizontal - ang;
    float angRel2 = PI - angHorizontal - ang;

    float theta1 = asin(manivelaRadius * sin(angRel1) / bielaLenght);
    float theta2 = asin(manivelaRadius * sin(angRel2) / bielaLenght);

    float d1 = (bielaLenght + manivelaRadius) - (-1 * bielaLenght * cos(theta1) - 1 * manivelaRadius * cos(angRel1));
    float d2 = (bielaLenght + manivelaRadius) - (-1 * bielaLenght * cos(theta2) - 1 * manivelaRadius * cos(angRel2));

    pistao1Pos.x = p1.x + d1 * cos(angHorizontal);
    pistao1Pos.y = p1.y + d1 * sin(angHorizontal);

    pistao2Pos.x = p1.x + d2 * cos(PI - angHorizontal);
    pistao2Pos.y = p1.y + d2 * sin(PI - angHorizontal);
    /*
    float bielaLength = 100;
    float manivelaRadius = 30;

    float dist = -bielaLength * cos(asin(manivelaRadius * sin(ang) / bielaLength)) + manivelaRadius * cos(ang);

    pistao1Pos = Vector2(dist + (screenWidth / 2), screenHeight / 2);
    */
}

EngineV2D::EngineV2D(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    manivelaPos = Vector2(screenWidth / 2, screenHeight / 2);
    pistao1Pos = Vector2(screenWidth * 1 / 4, screenHeight * 3 / 4);
    pistao2Pos = Vector2(screenWidth * 3 / 4, screenHeight * 3 / 4);
    speedSlider = new Slider(screenWidth * 1 / 4, screenHeight / 4, 100, 20, 10, 1, 0);
    angSlider = new Slider(screenWidth * 2 / 4, screenHeight / 4, 100, 20, 10, 1, 0);
    rpm = 1 + speedSlider->percent() * 10;
    angHorizontal = (PI / 6) + angSlider->percent() * PI / 4;
}

EngineV2D::~EngineV2D()
{
}

void EngineV2D::onMouse(int button, int state, int wheel, int direction, int x, int y)
{
    speedSlider->onMouse(x, y, button, state);
    rpm = 1 + speedSlider->percent() * 10;
    angSlider->onMouse(x, y, button, state);
    angHorizontal = (PI / 6) + angSlider->percent() * PI / 4;
}

void EngineV2D::render()
{
    CV::color(0, 0, 0);
    CV::circle(screenWidth / 2, screenHeight / 2, 30, 30);
    CV::circle(manivelaPos.x, manivelaPos.y, 10, 30);
    CV::circle(pistao1Pos.x, pistao1Pos.y, 10, 30);
    CV::circle(pistao2Pos.x, pistao2Pos.y, 10, 30);
    CV::line(manivelaPos.x, manivelaPos.y, pistao1Pos.x, pistao1Pos.y);
    CV::line(manivelaPos.x, manivelaPos.y, pistao2Pos.x, pistao2Pos.y);
    rotateManivela(ang);
    movePistoes();
    speedSlider->render();
    angSlider->render();
    ang += getDeltaTime() * rpm;
    if (ang >= 2 * PI)
        ang = 0;
}
