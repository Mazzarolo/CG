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
    points.push_back(Vector2(2 * screenWidth / 32, 3 * screenHeight / 3));
    leftCurve = new Bezier(points);

    points.clear();

    points.push_back(Vector2(30 * screenWidth / 32, 0 * screenHeight / 3));
    points.push_back(Vector2(32 * screenWidth / 32, 1 * screenHeight / 3));
    points.push_back(Vector2(28 * screenWidth / 32, 2 * screenHeight / 3));
    points.push_back(Vector2(30 * screenWidth / 32, 3 * screenHeight / 3));
    rightCurve = new Bezier(points);

    height = screenHeight;
}

void Background::render()
{   
    CV::clear(backColor[0], backColor[1], backColor[2]);
    CV::translate(0, y);
    CV::color(lineColor[0], lineColor[1], lineColor[2]);
    leftCurve->render();
    rightCurve->render();
    CV::translate(0, y + height);
    leftCurve->render();
    rightCurve->render();
    CV::translate(0, 0);
}

bool Background::checkCollision(Vector2 point)
{
    CV::translate(0, y);
    if(leftCurve->checkCollision(point) || rightCurve->checkCollision(point))
    {
        CV::translate(0, 0);
        return true;
    }
    CV::translate(0, y + height);
    if(leftCurve->checkCollision(point) || rightCurve->checkCollision(point))
    {
        CV::translate(0, 0);
        return true;
    }
    CV::translate(0, 0);
    return false;
}

void Background::moveY(int y, int screenHeight)
{
    this->y = y - screenHeight / 5;
}
