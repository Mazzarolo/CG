#include "Background.h"

Background::Background(int screenWidth, int screenHeight, int offsetY, int curveHeight)
{
    this->offsetY = offsetY;

    height = curveHeight;

    renderY = -offsetY;

    for(int i = 0; i < 3; i++)
    {
        backColor[i] = 0;
        lineColor[i] = 1;
    }

    srand(time(NULL));

    vector<Vector2> points;
    points.push_back(Vector2(10 * screenWidth / 32, 0 * height / 3));
    points.push_back(Vector2(0 * screenWidth / 32, 1 * height / 3));
    points.push_back(Vector2(20 * screenWidth / 32, 2 * height / 3));
    points.push_back(Vector2(10 * screenWidth / 32, 3 * height / 3));
    leftCurve = new Bezier(points);

    points.clear();

    points.push_back(Vector2(22 * screenWidth / 32, 0 * height / 3));
    points.push_back(Vector2(10 * screenWidth / 32, 1 * height / 3));
    points.push_back(Vector2(32 * screenWidth / 32, 2 * height / 3));
    points.push_back(Vector2(22 * screenWidth / 32, 3 * height / 3));
    rightCurve = new Bezier(points);
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

bool Background::checkCollision(Vector2 point, int hitBoxRadius)
{   
    leftCurve->moveY(renderY);
    rightCurve->moveY(renderY);

    if(leftCurve->checkCollision(point, hitBoxRadius) || rightCurve->checkCollision(point, hitBoxRadius))
    {
        return true;
    }

    leftCurve->moveY(renderY + height);
    rightCurve->moveY(renderY + height);
    
    if(leftCurve->checkCollision(point, hitBoxRadius) || rightCurve->checkCollision(point, hitBoxRadius))
    {
        return true;
    }
    return false;
}

void Background::moveY(int y)
{
    renderY = y - offsetY;
}
