#include "Background.h"

Background::Background(int screenWidth, int screenHeight, int offsetY)
{
    this->offsetY = offsetY;

    renderY = -offsetY;

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
    CV::color(lineColor[0], lineColor[1], lineColor[2]);
    leftCurve->moveY(renderY);
    rightCurve->moveY(renderY);
    leftCurve->render();
    rightCurve->render();
    leftCurve->moveY(renderY + height);
    rightCurve->moveY(renderY + height);
    leftCurve->render();
    rightCurve->render();
}

bool Background::checkCollision(Vector2 point)
{   
    leftCurve->moveY(renderY);
    rightCurve->moveY(renderY);

    if(leftCurve->checkCollision(point) || rightCurve->checkCollision(point))
    {
        return true;
    }

    leftCurve->moveY(renderY + height);
    rightCurve->moveY(renderY + height);
    
    if(leftCurve->checkCollision(point) || rightCurve->checkCollision(point))
    {
        return true;
    }
    return false;
}

void Background::moveY(int y)
{
    renderY = y - offsetY;
}
