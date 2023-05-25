#include "Background.h"

Background::Background(int screenWidth, int screenHeight, int offsetY, int curveHeight)
{
    this->screenWidth = screenWidth;

    this->screenHeight = screenHeight;

    createStars(250);

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
    points.push_back(Vector2(-6 * screenWidth / 32, 1 * height / 3));
    points.push_back(Vector2(26 * screenWidth / 32, 2 * height / 3));
    points.push_back(Vector2(10 * screenWidth / 32, 3 * height / 3));
    leftCurve = new Bezier(points);

    points.clear();

    points.push_back(Vector2(22 * screenWidth / 32, 0 * height / 3));
    points.push_back(Vector2(6 * screenWidth / 32, 1 * height / 3));
    points.push_back(Vector2(38 * screenWidth / 32, 2 * height / 3));
    points.push_back(Vector2(22 * screenWidth / 32, 3 * height / 3));
    rightCurve = new Bezier(points);
}

Background::~Background()
{
    delete leftCurve;
    delete rightCurve;
    for (int i = 0; i < (int) stars.size(); i++)
    {
        delete stars[i];
    }
}

void Background::render()
{
    CV::clear(backColor[0], backColor[1], backColor[2]);
    renderStars();
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

void Background::createStars(int numStars)
{
    for(int i = 0; i < numStars; i++)
    {
        int x = rand() % screenWidth;
        int y = rand() % screenHeight;
        int radius = rand() % 2 + 1;
        stars.push_back(new Star(x, y, radius));
    }
}

void Background::renderStars()
{
    for(int i = 0; i < (int) stars.size(); i++)
    {
        stars[i]->render();
        stars[i]->naturalMove(screenHeight);
    }
}
