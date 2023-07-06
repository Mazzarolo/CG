#include "EngineV2D.h"

void EngineV2D::rotateManivela(float angle)
{
    manivelaPos.x = 20 * cos(angle) - 20 * sin(angle);
    manivelaPos.y = 20 * sin(angle) + 20 * cos(angle);

    manivelaPos.x += screenWidth / 2;
    manivelaPos.y += screenHeight / 2;
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

EngineV2D::EngineV2D(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

EngineV2D::~EngineV2D()
{
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
    movePistao1();
    movePistao2();
    ang += getDeltaTime() * 5;
    if (ang >= 2 * PI)
        ang = 0;
}