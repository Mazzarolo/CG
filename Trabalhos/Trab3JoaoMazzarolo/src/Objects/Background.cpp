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

    planets.push_back(new Animation(10, 2, 20, 0.1f));
    planets[0]->setPosition(50, 400);
    planets[0]->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Planets\\Planet01.bmp");

    planets.push_back(new Animation(10, 2, 20, 0.1f));
    planets[1]->setPosition(50, 200);
    planets[1]->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Planets\\Planet02.bmp");

    planets.push_back(new Animation(10, 2, 20, 0.1f));
    planets[2]->setPosition(400, 600);
    planets[2]->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Planets\\Planet03.bmp");

    planets.push_back(new Animation(10, 2, 20, 0.1f));
    planets[3]->setPosition(-800, 700);
    planets[3]->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Planets\\Planet04.bmp");

    planets.push_back(new Animation(10, 2, 20, 0.1f));
    planets[4]->setPosition(300, 1000);
    planets[4]->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Planets\\Planet05.bmp");

    planets.push_back(new Animation(10, 2, 20, 0.1f));
    planets[5]->setPosition(-1700, -300);
    planets[5]->load((char*) "Trab3JoaoMazzarolo\\src\\Images\\Planets\\Planet06.bmp");
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
    for(int i = 0; i < (int) planets.size(); i++)
    {
        if(planets[i]->getPosition().y > -500 && planets[i]->getPosition().y < screenHeight + 100)
            planets[i]->render();
        planets[i]->moveY(-1.0f * getDeltaTime() * 10);
        if(planets[i]->getPosition().y < -500)
        {
            planets[i]->setPosition(planets[i]->getPosition().x, screenHeight + 100);
        }
    }
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

bool Background::checkCollision(Vector2 point, int hitBoxRadius, bool right)
{
    if(right)
    {
        rightCurve->moveY(renderY);
        if(rightCurve->checkCollision(point, hitBoxRadius))
        {
            return true;
        }
        rightCurve->moveY(renderY + height);
        if(rightCurve->checkCollision(point, hitBoxRadius))
        {
            return true;
        }
    }
    else
    {
        leftCurve->moveY(renderY);
        if(leftCurve->checkCollision(point, hitBoxRadius))
        {
            return true;
        }
        leftCurve->moveY(renderY + height);
        if(leftCurve->checkCollision(point, hitBoxRadius))
        {
            return true;
        }
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

vector<Vector2> Background::getSpawnPoints()
{
    vector<Vector2> points;
    points.push_back(leftCurve->getSpawnPoint());
    points.push_back(rightCurve->getSpawnPoint());
    return points;
}
