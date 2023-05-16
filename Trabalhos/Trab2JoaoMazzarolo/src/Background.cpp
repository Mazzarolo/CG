#include "Background.h"

Background::Background(int screenWidth, int screenHeight)
{
    y = 0;

    for(int i = 0; i < 3; i++)
    {
        backColor[i] = 0;
        lineColor[i] = 1;
    }

    vector<Vector2> points;
    points.push_back(Vector2(2 * screenWidth / 32, 0 * screenHeight / 3));
    points.push_back(Vector2(0 * screenWidth / 32, 1 * screenHeight / 3));
    points.push_back(Vector2(4 * screenWidth / 32, 2 * screenHeight / 3));
    points.push_back(Vector2(1 * screenWidth / 32, 3 * screenHeight / 3));
    leftCurve = new Bezier(points);

    points.clear();

    points.push_back(Vector2(30 * screenWidth / 32, 0 * screenHeight / 3));
    points.push_back(Vector2(32 * screenWidth / 32, 1 * screenHeight / 3));
    points.push_back(Vector2(28 * screenWidth / 32, 2 * screenHeight / 3));
    points.push_back(Vector2(31 * screenWidth / 32, 3 * screenHeight / 3));
    rightCurve = new Bezier(points);
}

void Background::render()
{   CV::translate(0, y);
    CV::clear(backColor[0], backColor[1], backColor[2]);
    CV::color(lineColor[0], lineColor[1], lineColor[2]);
    leftCurve->render();
    rightCurve->render();
    CV::translate(0, 0);
}

void Background::moveY(int y, int screenHeight)
{
    this->y = y - screenHeight / 2;
}
